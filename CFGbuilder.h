#pragma once

#include <string>
#include <vector>
#include <map>
#include <any>
#include <tuple>
#include <stdexcept>

#include "antlr4-runtime.h"
#include "janusParser.h"
#include "janusBaseVisitor.h"

#include "structures.h"

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
        cfg.blocks[entryL] = Block{entryL, BlockType::START, ctx->getStart()->getLine(), "", AssignmentOp::ADD, nullptr, nullptr, procName, nullptr};
        cfg.procedureEntry[procName] = entryL;

        Label reverseentryL = createLabel();
        cfg.blocks[reverseentryL] = Block{reverseentryL, BlockType::START, ctx->getStart()->getLine(), "", AssignmentOp::ADD, nullptr, nullptr, procName, nullptr};
        cfg.reverseprocedureEntry[procName] = reverseentryL;

        Label exitL = createLabel();
        cfg.blocks[exitL] = Block{exitL, BlockType::STOP, 0, "", AssignmentOp::ADD, nullptr, nullptr, procName};
        cfg.procedureExit[procName] = exitL;

        Label reverseexitL = createLabel();
        cfg.blocks[reverseexitL] = Block{reverseexitL, BlockType::STOP, 0, "", AssignmentOp::ADD, nullptr, nullptr, procName};
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
        b.label = l;
        b.varName = ctx->variableName()->getText();
        b.line = ctx->getStart()->getLine();

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
        rb.label = rl;
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
        bif.label = lif;
        bif.type = BlockType::IF;
        bif.line = ctx->ifExpression()->getStart()->getLine();
        bif.condExpr = ctx->ifExpression()->expression();
        cfg.blocks[lif] = bif;

        Label lfi = createLabel();
        Block bfi;
        bfi.label = lfi;
        bfi.type = BlockType::FI;
        bfi.line = ctx->fiExpression()->getStart()->getLine();
        bfi.condExpr = ctx->fiExpression()->expression();
        cfg.blocks[lfi] = bfi;

        Label rlif = createLabel();
        Block rbif;
        rbif.label = rlif;
        rbif.type = BlockType::IF;
        rbif.line = ctx->fiExpression()->getStart()->getLine();
        rbif.condExpr = ctx->fiExpression()->expression();
        cfg.blocks[rlif] = rbif;

        Label rlfi = createLabel();
        Block rbfi;
        rbfi.label = rlfi;
        rbfi.type = BlockType::FI;
        rbfi.line = ctx->ifExpression()->getStart()->getLine();
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
        bfrom.label = lfrom;
        bfrom.type = BlockType::FROM;
        bfrom.line = ctx->fromExp()->getStart()->getLine();
        bfrom.condExpr = ctx->fromExp()->expression();
        cfg.blocks[lfrom] = bfrom;

        Label lunt = createLabel();
        Block bunt;
        bunt.label = lunt;
        bunt.type = BlockType::UNTIL;
        bunt.line = ctx->untilExp()->getStart()->getLine();
        bunt.condExpr = ctx->untilExp()->expression();
        cfg.blocks[lunt] = bunt;

        Label rlfrom = createLabel();
        Block rbfrom;
        rbfrom.label = rlfrom;
        rbfrom.type = BlockType::UNTIL;
        rbfrom.line = ctx->fromExp()->getStart()->getLine();
        rbfrom.condExpr = ctx->fromExp()->expression();
        cfg.blocks[rlfrom] = rbfrom;

        Label rlunt = createLabel();
        Block rbunt;
        rbunt.label = rlunt;
        rbunt.type = BlockType::FROM;
        rbunt.line = ctx->untilExp()->getStart()->getLine();
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
        b.label = l;
        string callType = ctx->call()->getText();
        b.type = (callType == "call") ? BlockType::CALL : BlockType::UNCALL;
        b.line = ctx->getStart()->getLine();
        b.procedurename = ctx->functionName()->getText();
        cfg.blocks[l] = b;

        Label rl = createLabel();
        Block rb = b;
        rb.label = rl;
        rb.type = (b.type == BlockType::CALL) ? BlockType::UNCALL : BlockType::CALL;
        rb.line = ctx->getStart()->getLine();
        cfg.blocks[rl] = rb;

        return make_tuple(l, l, rl, rl);
    }

    virtual any visitSkip(janusParser::SkipContext *ctx) override
    {
        Label l = createLabel();
        Block b{l, BlockType::SKIP, ctx->getStart()->getLine()};
        cfg.blocks[l] = b;

        Label rl = createLabel();
        Block rb{rl, BlockType::SKIP, ctx->getStart()->getLine()};
        cfg.blocks[rl] = rb;

        return make_tuple(l, l, rl, rl);
    }
};