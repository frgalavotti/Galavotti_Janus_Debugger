#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <format>

#include "antlr4-runtime.h"
#include "janusParser.h"

#include "structures.h"

class ReversibleJanusInterpreter
{
public:
    ProgramCFG cfg;
    Label l1 = 0;
    Label l2 = 0;
    vector<StackItem> pi;

    ReversibleJanusInterpreter(ProgramCFG pCFG, Label startL1, Label startL2) : cfg(move(pCFG)), l1(startL1), l2(startL2) {}

    int evalExpr(janusParser::ExpressionContext *ctx){
        if (!ctx)
            return 0;
        if (ctx->Digit())
        {
            return stoi(ctx->Digit()->getText());
        }
        else if (ctx->TextDigit())
        {
            string name = ctx->TextDigit()->getText();
            if (!ctx->expression().empty())
            {
                int index = evalExpr(ctx->expression(0));
                if (cfg.arrays.contains(name) && index >= 0 && index < (int)cfg.arrays[name].size())
                {
                    return cfg.arrays[name][index];
                }
                return 0;
            }
            return cfg.variables.contains(name) ? cfg.variables[name] : 0;
        }
        else if (ctx->expression().size() == 2 && ctx->operator_())
        {
            int a = evalExpr(ctx->expression(0));
            int b = evalExpr(ctx->expression(1));
            string op = ctx->operator_()->getText();

            if (op == "+")
                return a + b;
            if (op == "-")
                return a - b;
            if (op == "*")
                return a * b;
            if (op == "/")
                return b != 0 ? a / b : 0;
            if (op == "%")
                return b != 0 ? a % b : 0;
            if (op == "&")
                return a & b;
            if (op == "|")
                return a | b;
            if (op == "^")
                return a ^ b;
            if (op == "=")
                return a == b ? 1 : 0;
            if (op == "!=")
                return a != b ? 1 : 0;
            if (op == "<")
                return a < b ? 1 : 0;
            if (op == ">")
                return a > b ? 1 : 0;
            if (op == "<=")
                return a <= b ? 1 : 0;
            if (op == ">=")
                return a >= b ? 1 : 0;
            if (op == "&&")
                return (a && b) ? 1 : 0;
            if (op == "||")
                return (a || b) ? 1 : 0;
        }
        return 0;
    }

    void applyOp(string var, AssignmentOp op, int val, int idx = -1){
        if (idx >= 0)
        {
            if (op == AssignmentOp::ADD)
                cfg.arrays[var][idx] += val;
            else if (op == AssignmentOp::SUB)
                cfg.arrays[var][idx] -= val;
            else if (op == AssignmentOp::XOR)
                cfg.arrays[var][idx] ^= val;
        }
        else
        {
            if (op == AssignmentOp::ADD)
                cfg.variables[var] += val;
            else if (op == AssignmentOp::SUB)
                cfg.variables[var] -= val;
            else if (op == AssignmentOp::XOR)
                cfg.variables[var] ^= val;
        }
    }

    AssignmentOp invertOp(AssignmentOp op){
        switch (op)
        {
        case AssignmentOp::ADD:
            return AssignmentOp::SUB;
        case AssignmentOp::SUB:
            return AssignmentOp::ADD;
        case AssignmentOp::XOR:
            return AssignmentOp::XOR;
        case AssignmentOp::SWAP:
            return AssignmentOp::SWAP;
        }
        return op;
    }

    bool stepForward()
    {
        if (!cfg.blocks.contains(l2)) return false;
        const Block &b = cfg.blocks[l2];

        Label l3 = 0;
        if (b.type != BlockType::STOP && !cfg.forwardFlow[l2].empty()) l3 = cfg.forwardFlow[l2][0];

        switch (b.type)
        {
        case BlockType::ASS_VAR:
        {
            int val = evalExpr(b.expr1);
            if (cfg.variables.contains(b.varName))
            {
                applyOp(b.varName, b.op, val);
            }
            else throw runtime_error(format("variable {} not found", b.varName));
            l1 = l2;
            l2 = l3;
            break;
        }
        case BlockType::ASS_ARR:
        {
            int idx = evalExpr(b.expr1);
            int val = evalExpr(b.expr2);
            if (cfg.arrays.contains(b.varName) && idx >= 0 && idx < cfg.arrays[b.varName].size())
            {
                applyOp(b.varName, b.op, val, idx);
            }
            else
                throw runtime_error(format("array {} not found or index error", b.varName));
            l1 = l2;
            l2 = l3;
            break;
        }
        case BlockType::SWAP:
        {
            bool isArr1 = (b.expr2 != nullptr);
            int val = evalExpr(isArr1 ? b.expr2 : b.expr1);
            int index1 = isArr1 ? evalExpr(b.expr1) : 0;
            int current = isArr1 ? cfg.arrays[b.varName][index1] : cfg.variables[b.varName];
            auto expr = isArr1 ? b.expr2 : b.expr1;
            if (expr->TextDigit() != nullptr)
            {
                string varName2 = expr->TextDigit()->getText();
                bool isArr2 = !expr->expression().empty();

                if (isArr1)
                {
                    cfg.arrays[b.varName][index1] = val;
                }
                else
                {
                    cfg.variables[b.varName] = val;
                }

                if (isArr2)
                {
                    int index2 = evalExpr(expr->expression(0));
                    cfg.arrays[varName2][index2] = current;
                }
                else
                {
                    cfg.variables[varName2] = current;
                }
            }

            l1 = l2;
            l2 = l3;
            break;
        }
        case BlockType::SKIP:
        {
            l1 = l2;
            l2 = l3;
            break;
        }
        case BlockType::CALL:
        {
            if (!cfg.procedureEntry.contains(b.procedurename))
            {
                throw runtime_error(format("unable to find procedure {}", b.procedurename));
            }
            Label entryLabel = cfg.procedureEntry[b.procedurename];
            Label entryNext = cfg.forwardFlow[entryLabel][0];
            pi.push_back({StackItemType::CALL, l2});
            l1 = entryLabel;
            l2 = entryNext;
            break;
        }
        case BlockType::UNCALL:
        {
            if (!cfg.procedureEntry.contains(b.procedurename))
            {
                throw runtime_error(format("unable to find procedure {}", b.procedurename));
            }
            Label entryLabel = cfg.reverseprocedureEntry[b.procedurename];
            Label entryNext = cfg.forwardFlow[entryLabel][0];
            pi.push_back({StackItemType::UNCALL, l2});
            l1 = entryLabel;
            l2 = entryNext;
            break;
        }
        case BlockType::START:
        {
            l1 = l2;
            l2 = l3;
            break;
        }
        case BlockType::STOP:
        {
            if (pi.empty())
                return false;
            StackItem top = pi.back();
            pi.pop_back();
            l1 = top.l;
            l2 = cfg.forwardFlow[l1][0];
            break;
        }
        case BlockType::IF:
        {
            bool cond = evalExpr(b.condExpr);
            if(cond){
                pi.push_back({StackItemType::IF_TRUE, l2});
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];
            }else{
                pi.push_back({StackItemType::IF_FALSE, l2});
                l1 = l2;
                l2 = cfg.forwardFlow[l2][1];
            }
            break;
        }
        case BlockType::FI:
        {
            bool cond = evalExpr(b.condExpr);
            StackItem top = pi.back();
            pi.pop_back();
            if(cond){
                if(top.type != StackItemType::IF_TRUE) throw runtime_error("condition and assertion must have the same value");
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];
            }else{
                if(top.type != StackItemType::IF_FALSE) throw runtime_error("condition and assertion must have the same value");
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];
            }
            break;
        }
        case BlockType::FROM:
        {
            bool cond = evalExpr(b.condExpr);
            if(cond)
            {
                pi.push_back({StackItemType::LOOP1, l2});
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];
            }
            else{
                StackItem top = pi.back();
                pi.pop_back();
                if(top.type == StackItemType::LOOP2)
                {
                pi.push_back({StackItemType::LOOP1, l2});
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];}
                else throw runtime_error("first evaluation of loop condition must be true");
            }
            break;
        }
        case BlockType::UNTIL:
        {
            bool cond = evalExpr(b.condExpr);
            StackItem top = pi.back();
            pi.pop_back();
            if(cond && top.type == StackItemType::LOOP1){
                l1 = l2;
                l2 = cfg.forwardFlow[l2][1];
            }
            else if(!cond && top.type == StackItemType::LOOP1){
                pi.push_back({StackItemType::LOOP2, l2});
                l1 = l2;
                l2 = cfg.forwardFlow[l2][0];
            }
            else throw runtime_error("loop stack error");
            break;
        }
        }
        return true;
    }

    bool stepBackward()
    {
        if (!cfg.blocks.contains(l1)) return false;
        const Block &b = cfg.blocks[l1];

        Label prevL = 0;
        if (b.type != BlockType::START && !cfg.backwardFlow[l1].empty()) prevL = cfg.backwardFlow[l1][0];

        switch (b.type)
        {
        case BlockType::ASS_VAR:
        {
            int val = evalExpr(b.expr1);
            if (cfg.variables.contains(b.varName))
            {
                applyOp(b.varName, invertOp(b.op), val);
            }
            else throw runtime_error(format("variable {} not found", b.varName));
            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::ASS_ARR:
        {
            int idx = evalExpr(b.expr1);
            int val = evalExpr(b.expr2);
            if (cfg.arrays.contains(b.varName) && idx >= 0 && idx < cfg.arrays[b.varName].size())
            {
                applyOp(b.varName, invertOp(b.op), val, idx);
            }
            else throw runtime_error(format("array {} not found or index error", b.varName));
            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::SWAP:
        {
            bool isArr1 = (b.expr2 != nullptr);
            int val = evalExpr(isArr1 ? b.expr2 : b.expr1);
            int index1 = isArr1 ? evalExpr(b.expr1) : 0;
            int current = isArr1 ? cfg.arrays[b.varName][index1] : cfg.variables[b.varName];
            auto expr = isArr1 ? b.expr2 : b.expr1;
            if (expr->TextDigit() != nullptr)
            {
                string varName2 = expr->TextDigit()->getText();
                bool isArr2 = !expr->expression().empty();

                if (isArr1)
                {
                    cfg.arrays[b.varName][index1] = val;
                }
                else
                {
                    cfg.variables[b.varName] = val;
                }

                if (isArr2)
                {
                    int index2 = evalExpr(expr->expression(0));
                    cfg.arrays[varName2][index2] = current;
                }
                else
                {
                    cfg.variables[varName2] = current;
                }
            }

            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::SKIP:
        {
            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::CALL:
        {
            if (!cfg.procedureExit.contains(b.procedurename))
            {
                throw runtime_error(format("unable to find procedure {}", b.procedurename));
            }
            Label exitLabel = cfg.procedureExit[b.procedurename];
            Label NextLabel = cfg.backwardFlow[exitLabel][0];
            pi.push_back({StackItemType::CALL, l1});
            l1 = NextLabel;
            l2 = exitLabel;
            break;
        }
        case BlockType::UNCALL:
        {
            if (!cfg.reverseprocedureExit.contains(b.procedurename))
            {
                throw runtime_error(format("unable to find procedure {}", b.procedurename));
            }
            Label entryLabel = cfg.reverseprocedureExit[b.procedurename];
            Label NextLabel = cfg.backwardFlow[entryLabel][0];
            pi.push_back({StackItemType::UNCALL, l1});
            l1 = NextLabel;
            l2 = entryLabel;
            break;
        }
        case BlockType::START:
        {
            if (pi.empty())
                return false;
            StackItem top = pi.back();
            pi.pop_back();
            l2 = top.l;
            l1 = cfg.backwardFlow[l2][0];
            break;
        }
        case BlockType::STOP:
        {
            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::IF:
        {
            bool cond = evalExpr(b.condExpr);
            StackItem top = pi.back();
            pi.pop_back();
            if(cond){
                if(top.type != StackItemType::IF_TRUE) throw runtime_error("condition and assertion must have the same value");
                l2 = l1;
                l1 = cfg.backwardFlow[l2][0];
            }else{
                if(top.type != StackItemType::IF_FALSE) throw runtime_error("condition and assertion must have the same value");
                l2 = l1;
                l1 = cfg.backwardFlow[l2][0];
            }
            break;
        }
        case BlockType::FI:
        {
            bool cond = evalExpr(b.condExpr);
            if(cond){
                pi.push_back({StackItemType::IF_TRUE, l2});
                l2 = l1;
                l1 = cfg.backwardFlow[l2][0];
            }else{
                pi.push_back({StackItemType::IF_FALSE, l2});
                l2 = l1;
                l1 = cfg.backwardFlow[l2][1];
            }
            break;
        }
        case BlockType::FROM:
        {
            bool cond = evalExpr(b.condExpr);
            StackItem top = pi.back();
            pi.pop_back();
            if(cond && top.type == StackItemType::LOOP1){
                l2 = l1;
                l1 = cfg.backwardFlow[l1][1];
            }
            else if(!cond && top.type == StackItemType::LOOP1){
                pi.push_back({StackItemType::LOOP2, l1});
                l2 = l1;
                l1 = cfg.backwardFlow[l1][0];
            }
            else throw runtime_error("loop stack error");
            break;
        }
        case BlockType::UNTIL:
        {
            bool cond = evalExpr(b.condExpr);
            if(cond)
            {
                pi.push_back({StackItemType::LOOP1, l1});
                l2 = l1;
                l1 = cfg.backwardFlow[l1][0];
            }
            else{
                StackItem top = pi.back();
                pi.pop_back();
                if(top.type == StackItemType::LOOP2)
                {
                pi.push_back({StackItemType::LOOP1, l1});
                l2 = l1;
                l1 = cfg.backwardFlow[l1][0];}
                else throw runtime_error("first evaluation of loop condition must be true");
            }
            break;
        }
        }
        return true;
    }

    void printState(string m="")
    {
        cout << "\033[u\033[0J";
        cout << "\n[f = step forward, b = step backward, ff = forward until breakpoint, bb = backwards until breakpoint, q = quit]\n";
        cout << "\n|=== STACK STATE:\n";
        for (auto &item : pi)
        {
            cout << " " << TypeToString(item.type);
        }
        cout << "\n\n|=== CURRENT BLOCKS: < l1= " << TypeToString(cfg.blocks[l1].type);
        cfg.blocks[l1].type == BlockType::START || cfg.blocks[l1].type == BlockType::STOP ? cout<<" "<< cfg.blocks[l1].procedurename : cout<<" line: "<< cfg.blocks[l1].line;
        cout<<", l2= " << TypeToString(cfg.blocks[l2].type);
        cfg.blocks[l2].type == BlockType::START || cfg.blocks[l2].type == BlockType::STOP ? cout<<" "<< cfg.blocks[l2].procedurename : cout<<" line: "<< cfg.blocks[l2].line;
        cout<<" >\n";
        cout << "\n|=== VARIABLES STATE: \n";
        for (auto &[var, val] : cfg.variables)
        {
            cout << " " << var << " = " << val << "\n";
        }
        if(m != "") cout<< m << endl;
    }
};