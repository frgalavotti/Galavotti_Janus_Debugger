#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <any>
#include <tuple>
#include <format>
#include <stdexcept>

#include "antlr4-runtime.h"
#include "janusLexer.h"
#include "janusParser.h"
#include "janusBaseVisitor.h"

using namespace std;

using Label = size_t;

enum class AssignmentOp
{
    ADD,
    SUB,
    XOR,
    SWAP
};

enum class BlockType
{
    START,
    STOP,
    ASS_VAR,
    ASS_ARR,
    SWAP,
    SKIP,
    CALL,
    UNCALL,
    IF_HEAD,
    FI_HEAD,
    FROM_HEAD,
    UNTIL_HEAD
};

struct Block
{
    Label id;
    BlockType type;

    string varName;
    AssignmentOp op;
    janusParser::ExpressionContext *expr1 = nullptr;
    janusParser::ExpressionContext *expr2 = nullptr;
    string procedurename;
    janusParser::ExpressionContext *condExpr = nullptr;
};

enum class StackItemType
{
    CALL,
    UNCALL,
    IF_TRUE,
    IF_FALSE,
    LOOP1,
    LOOP2
} ;

struct StackItem
{
    StackItemType type;
    Label l1;
    Label l2;
    Label s1;
    Label s2;
};

struct ProgramCFG
{
    map<string, int> variables;
    map<string, vector<int>> arrays;

    map<Label, Block> blocks;
    map<Label, vector<Label>> forwardFlow;
    map<Label, vector<Label>> backwardFlow;

    map<string, Label> procedureEntry;
    map<string, Label> procedureExit;

    map<string, Label> reverseprocedureEntry;
    map<string, Label> reverseprocedureExit;

    void addEdge(Label u, Label v)
    {
        forwardFlow[u].push_back(v);
        backwardFlow[v].push_back(u);
    }
};

string TypeToString(BlockType type) {
    switch (type) {
        case BlockType::START:return "START";
        case BlockType::STOP:return "STOP";
        case BlockType::ASS_VAR:return "ASS_VAR";
        case BlockType::SWAP:return "SWAP";
        case BlockType::SKIP:return "SKIP";
        case BlockType::CALL:return "CALL";
        case BlockType::UNCALL:return "UNCALL";
        case BlockType::IF_HEAD:return "IF";
        case BlockType::FI_HEAD:return "FI";
        case BlockType::FROM_HEAD:return "FROM";
        case BlockType::UNTIL_HEAD:return "UNTIL";
    }
    return "UNKNOWN";
}

string TypeToString(StackItemType type) {
    switch (type) {
        case StackItemType::CALL:return "CALL";
        case StackItemType::UNCALL:return "UNCALL";
        case StackItemType::IF_TRUE:return "THEN";
        case StackItemType::IF_FALSE:return "ELSE";
        case StackItemType::LOOP1:return "LOOP1";
        case StackItemType::LOOP2:return "LOOP2";
    }
    return "UNKNOWN";
}

class ReversibleJanusInterpreter
{
private:
    ProgramCFG cfg;
    Label l1 = 0;
    Label l2 = 0;
    vector<StackItem> pi;

public:
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
            l1 = top.l1;
            l2 = cfg.forwardFlow[l1][0];
            break;
        }
        case BlockType::IF_HEAD:
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
        case BlockType::FI_HEAD:
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
        case BlockType::FROM_HEAD:
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
        case BlockType::UNTIL_HEAD:
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
            l2 = top.l1;
            l1 = cfg.backwardFlow[l2][0];
            break;
        }
        case BlockType::STOP:
        {
            l2 = l1;
            l1 = prevL;
            break;
        }
        case BlockType::IF_HEAD:
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
        case BlockType::FI_HEAD:
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
        case BlockType::FROM_HEAD:
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
        case BlockType::UNTIL_HEAD:
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
        cout << "\n[f = step forward, b = step backward, q = quit]\n";
        cout << "\n|=== STACK STATE:\n";
        for (auto &item : pi)
        {
            cout << " " << TypeToString(item.type);
        }
        cout << "\n\n|=== CURRENT BLOCKS: < l1= " << TypeToString(cfg.blocks[l1].type) << ", l2= " << TypeToString(cfg.blocks[l2].type) << " >\n";
        cout << "\n|=== VARIABLES STATE: \n";
        for (auto &[var, val] : cfg.variables)
        {
            cout << " " << var << " = " << val << "\n";
        }
        if(m != "") cout<< m << endl;
    }
};

class CFGBuilder : public janusBaseVisitor
{
private:
    ProgramCFG cfg;
    Label nextLabel = 1;

    Label createLabel()
    {
        return nextLabel++;
    }

public:
    ProgramCFG getCFG() { return cfg; }

    virtual any visitVariables(janusParser::VariablesContext *ctx) override
    {
        if (ctx->variableName())
        {
            string varName = ctx->variableName()->getText();
            if (ctx->Digit())
            {
                int size = stoi(ctx->Digit()->getText());
                cfg.arrays[varName] = vector<int>(size, 0);
            }
            else
            {
                cfg.variables[varName] = 0;
            }
        }
        return visitChildren(ctx);
    }

    virtual any visitFunction(janusParser::FunctionContext *ctx) override
    {
        string procName = ctx->functionName()->getText();

        Label entryL = createLabel();
        cfg.blocks[entryL] = Block{entryL, BlockType::START, "", AssignmentOp::ADD, nullptr, nullptr, procName, nullptr};
        cfg.procedureEntry[procName] = entryL;

        Label reverseentryL = createLabel();
        cfg.blocks[reverseentryL] = Block{reverseentryL, BlockType::START, "", AssignmentOp::ADD, nullptr, nullptr, procName, nullptr};
        cfg.reverseprocedureEntry[procName] = reverseentryL;

        Label exitL = createLabel();
        cfg.blocks[exitL] = Block{exitL, BlockType::STOP, "", AssignmentOp::ADD, nullptr, nullptr, procName};
        cfg.procedureExit[procName] = exitL;

        Label reverseexitL = createLabel();
        cfg.blocks[reverseexitL] = Block{reverseexitL, BlockType::STOP, "", AssignmentOp::ADD, nullptr, nullptr, procName};
        cfg.reverseprocedureExit[procName] = reverseexitL;

        if (ctx->statements())
        {
            auto [firstL, lastL, reversefirstL, reverselastL] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->statements()));
            cfg.addEdge(entryL, firstL);
            cfg.addEdge(lastL, exitL);

            cfg.addEdge(reverseentryL, reversefirstL);
            cfg.addEdge(reverselastL, reverseexitL);
        }
        else
        {
            cfg.addEdge(entryL, exitL);
            cfg.addEdge(reverseentryL, reverseexitL);
        }
        return nullptr;
    }

    virtual any visitStatements(janusParser::StatementsContext *ctx) override
    {
        if (ctx->assignmentExpression())
            return visit(ctx->assignmentExpression());
        else if (ctx->ifConstructor())
            return visit(ctx->ifConstructor());
        else if (ctx->loopConstructor())
            return visit(ctx->loopConstructor());
        else if (ctx->functionCall())
            return visit(ctx->functionCall());
        else if (ctx->skip())
            return visit(ctx->skip());
        else if (ctx->statements().size() == 2)
        {
            auto [fEntry1, fExit1, rEntry1, rExit1] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->statements(0)));
            auto [fEntry2, fExit2, rEntry2, rExit2] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->statements(1)));

            cfg.addEdge(fExit1, fEntry2);
            cfg.addEdge(rExit2, rEntry1);

            return make_tuple(fEntry1, fExit2, rEntry2, rExit1);
        }
        return make_tuple((Label)0, (Label)0, (Label)0, (Label)0);
    }

    virtual any visitAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) override
    {
        Label l = createLabel();
        Block b;
        b.id = l;
        b.varName = ctx->variableName()->getText();

        string op = ctx->assignmentOperator()->getText();
        if (op == "+=")
            b.op = AssignmentOp::ADD;
        else if (op == "-=")
            b.op = AssignmentOp::SUB;
        else if (op == "^=")
            b.op = AssignmentOp::XOR;
        else if (op == "<=>")
            b.op = AssignmentOp::SWAP;

        if (ctx->expression().size() == 2)
        {
            b.type = (b.op == AssignmentOp::SWAP) ? BlockType::SWAP : BlockType::ASS_ARR;
            b.expr1 = ctx->expression(0);
            b.expr2 = ctx->expression(1);
        }
        else
        {
            b.type = (b.op == AssignmentOp::SWAP) ? BlockType::SWAP : BlockType::ASS_VAR;
            b.expr1 = ctx->expression(0);
        }

        cfg.blocks[l] = b;

        Label rl = createLabel();
        Block rb = b;
        rb.id = rl;
        if (rb.op == AssignmentOp::ADD)
            rb.op = AssignmentOp::SUB;
        else if (rb.op == AssignmentOp::SUB)
            rb.op = AssignmentOp::ADD;
        cfg.blocks[rl] = rb;

        return make_tuple(l, l, rl, rl);
    }

    virtual any visitIfConstructor(janusParser::IfConstructorContext *ctx) override
    {
        Label lif = createLabel();
        Block bif;
        bif.id = lif;
        bif.type = BlockType::IF_HEAD;
        bif.condExpr = ctx->ifExpression()->expression();
        cfg.blocks[lif] = bif;

        Label lfi = createLabel();
        Block bfi;
        bfi.id = lfi;
        bfi.type = BlockType::FI_HEAD;
        bfi.condExpr = ctx->fiExpression()->expression();
        cfg.blocks[lfi] = bfi;

        Label rlif = createLabel();
        Block rbif;
        rbif.id = rlif;
        rbif.type = BlockType::IF_HEAD;
        rbif.condExpr = ctx->fiExpression()->expression();
        cfg.blocks[rlif] = rbif;

        Label rlfi = createLabel();
        Block rbfi;
        rbfi.id = rlfi;
        rbfi.type = BlockType::FI_HEAD;
        rbfi.condExpr = ctx->ifExpression()->expression();
        cfg.blocks[rlfi] = rbfi;

        auto [thenFEntry, thenFExit, thenREntry, thenRExit] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->ifExpression()->statements()));
        cfg.addEdge(lif, thenFEntry);
        cfg.addEdge(thenFExit, lfi);
        cfg.addEdge(rlif, thenREntry);
        cfg.addEdge(thenRExit, rlfi);

        if (ctx->elseExpression())
        {
            auto [elseFEntry, elseFExit, elseREntry, elseRExit] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->elseExpression()->statements()));
            cfg.addEdge(lif, elseFEntry);
            cfg.addEdge(elseFExit, lfi);
            cfg.addEdge(rlif, elseREntry);
            cfg.addEdge(elseRExit, rlfi);
        }
        else
        {
            cfg.addEdge(lif, lfi);
            cfg.addEdge(rlif, rlfi);
        }

        return make_tuple(lif, lfi, rlif, rlfi);
    }

    virtual any visitLoopConstructor(janusParser::LoopConstructorContext *ctx) override
    {
        Label lfrom = createLabel();
        Block bfrom;
        bfrom.id = lfrom;
        bfrom.type = BlockType::FROM_HEAD;
        bfrom.condExpr = ctx->fromExp()->expression();
        cfg.blocks[lfrom] = bfrom;

        Label lunt = createLabel();
        Block bunt;
        bunt.id = lunt;
        bunt.type = BlockType::UNTIL_HEAD;
        bunt.condExpr = ctx->untilExp()->expression();
        cfg.blocks[lunt] = bunt;

        Label rlfrom = createLabel();
        Block rbfrom;
        rbfrom.id = rlfrom;
        rbfrom.type = BlockType::UNTIL_HEAD;
        rbfrom.condExpr = ctx->fromExp()->expression();
        cfg.blocks[rlfrom] = rbfrom;

        Label rlunt = createLabel();
        Block rbunt;
        rbunt.id = rlunt;
        rbunt.type = BlockType::FROM_HEAD;
        rbunt.condExpr = ctx->untilExp()->expression();
        cfg.blocks[rlunt] = rbunt;

        if (ctx->doExp())
        {
            auto [dEntry, dExit, rdEntry, rdExit] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->doExp()->statements()));
            cfg.addEdge(lfrom, dEntry);
            cfg.addEdge(dExit, lunt);
            cfg.addEdge(rlunt, rdEntry);
            cfg.addEdge(rdExit, rlfrom);
        }
        else
        {
            cfg.addEdge(lfrom, lunt);
            cfg.addEdge(rlunt, rlfrom);
        }

        if (ctx->loopExp())
        {
            auto [lEntry, lExit, rlEntry, rlExit] = any_cast<tuple<Label, Label, Label, Label>>(visit(ctx->loopExp()->statements()));
            cfg.addEdge(lunt, lEntry);
            cfg.addEdge(lExit, lfrom);
            cfg.addEdge(rlfrom, rlEntry);
            cfg.addEdge(rlExit, rlunt);
        }
        else
        {
            cfg.addEdge(lunt, lfrom);
            cfg.addEdge(rlfrom, rlunt);
        }

        return make_tuple(lfrom, lunt, rlunt, rlfrom);
    }

    virtual any visitFunctionCall(janusParser::FunctionCallContext *ctx) override
    {
        Label l = createLabel();
        Block b;
        b.id = l;
        string callType = ctx->call()->getText();
        b.type = (callType == "call") ? BlockType::CALL : BlockType::UNCALL;
        b.procedurename = ctx->functionName()->getText();
        cfg.blocks[l] = b;

        Label rl = createLabel();
        Block rb = b;
        rb.id = rl;
        rb.type = (b.type == BlockType::CALL) ? BlockType::UNCALL : BlockType::CALL;
        cfg.blocks[rl] = rb;

        return make_tuple(l, l, rl, rl);
    }

    virtual any visitSkip(janusParser::SkipContext *ctx) override
    {
        Label l = createLabel();
        Block b{l, BlockType::SKIP};
        cfg.blocks[l] = b;

        Label rl = createLabel();
        Block rb{rl, BlockType::SKIP};
        cfg.blocks[rl] = rb;

        return make_tuple(l, l, rl, rl);
    }
};

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        cerr << "Use: " << argv[0] << " <file.janus|file.txt> (-m mainfun)? (-d debuglines)?" << endl;
        return 1;
    }

    ifstream stream(argv[1]);
    if (!stream.is_open())
    {
        cerr << "Not able to open file: " << argv[1] << endl;
        return 1;
    }

    map<size_t, size_t> debuglines;
    string main = "main";
    for (int i = 2; i < argc; i++)
    {
        if (string(argv[i]) == "-m")
        {
            if ((i + 1 < argc) && (string(argv[i + 1]) != "-d"))
            {
                main = argv[i + 1];
            }
            else
            {
                cerr << "-m requires the name of the main function afterwards!" << endl;
                return 1;
            }
        }
        else if (string(argv[i]) == "-d")
        {
            while ((i + 1 < argc) && (string(argv[i + 1]) != "-m"))
            {
                try
                {
                    debuglines.insert({stoul(argv[i + 1]), 0});
                    i++;
                }
                catch (const invalid_argument &)
                {
                    cerr << "non-valid value for -d: " << argv[i + 1] << endl;
                    return 1;
                }
            }
        }
    }

    cout << "\033[s";

    antlr4::ANTLRInputStream input(stream);
    janusLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    janusParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.program();

    CFGBuilder builder;
    builder.visit(tree);
    ProgramCFG cfg = builder.getCFG();

    Label startL1;
    auto i = cfg.procedureEntry.find(main);
    if (i != cfg.procedureEntry.end())
        startL1 = i->second;
    else
    {
        cerr << "unable to find main procedure" << endl;
        return 1;
    }
    Label startL2 = cfg.forwardFlow[startL1][0];

    ReversibleJanusInterpreter interpreter(cfg, startL1, startL2);
    interpreter.printState();
    string cmd;
    try{
    while (cout << "> " && cin >> cmd && cmd != "q")
    {
        if (cmd == "f")
        {
            if (!interpreter.stepForward())
                interpreter.printState("Fine esecuzione in avanti");
            else interpreter.printState();
        }
        else if (cmd == "b")
        {
            if (!interpreter.stepBackward())
                interpreter.printState("Inizio programma raggiunto.");
            else interpreter.printState();
        }
    }
    }
    catch (const exception &e)
    {
        cerr << "Errore di esecuzione: " << e.what() << "\n";
    }
    return 0;
}