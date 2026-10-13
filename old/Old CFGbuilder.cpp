class CFGBuilder : public janusBaseVisitor {
private:
    ProgramCFG cfg;
    Label nextLabel = 1;

    Label createLabel() {
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
                arrays[varName] = vector<int>(size, 0);
            }
            else
            {
                variables[varName] = 0;
            }
        }
        return visitChildren(ctx);
    }

    virtual any visitFunction(janusParser::ProcedureContext *ctx) override {
        string procName = ctx->functionName()->getText();

        Label entryL = createLabel();
        cfg.blocks[entryL] = Block{entryL, BlockType::START, "", AssignmentOp::ADD, nullptr, nullptr, procName, nullptr};
        cfg.procedureEntry[procName] = entryL;

        Label currentL = entryL;
        if (ctx->statements()) {
            auto [firstL, lastL] = any_cast<pair<Label, Label>>(visit(ctx->statements()));
            cfg.addEdge(currentL, firstL);
            cfg.addEdge(reversecurrentL, reverselastL);
            currentL = lastL;
        }else{
            Label skipL = createLabel();
            cfg.blocks[skipL] = Block{skipL, BlockType::SKIP};
            cfg.addEdge(currentL, skipL);
            currentL = skipL;
        }

        Label exitL = createLabel();
        cfg.blocks[exitL] = Block{exitL, BlockType::STOP, "", AssignmentOp::ADD, nullptr, nullptr, procName};
        cfg.addEdge(currentL, exitL);
        cfg.procedureExit[procName] = exitL;

        return nullptr;
    }

    virtual any visitStatements(janusParser::StatementsContext *ctx) override {  
        if (ctx->assignmentExpression()) return visit(ctx->assignmentExpression());
        else if (ctx->ifConstructor()) return visit(ctx->ifConstructor());
        else if (ctx->loopConstructor()) return visit(ctx->loopConstructor());
        else if (ctx->functionCall()) return visit(ctx->functionCall());
        else if (ctx->skip()) return visit(ctx->skip());
        else if (ctx->statements().size() == 2) {
            auto [entry1, exit1] = any_cast<pair<Label, Label>>(visit(ctx->statements(0)));
            auto [entry2, exit2] = any_cast<pair<Label, Label>>(visit(ctx->statements(1)));
            cfg.addEdge(exit1, entry2);
            return make_pair(entry1, exit2);
        }
    }

    virtual any visitAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) override {
        Label l = createLabel();
        Block b;
        b.id = l;
        b.varName = ctx->variableName()->getText();

        string op = ctx->assignmentOperator()->getText();
        if (op == "+=")      b.op = AssignmentOp::ADD;
        else if (op == "-=") b.op = AssignmentOp::SUB;
        else if (op == "^=") b.op = AssignmentOp::XOR;
        else if (op == "<=>") b.op = AssignmentOp::SWAP;

        if (ctx->expression().size() == 2) {
            b.type = (b.op == AssignmentOp::SWAP) ? BlockType::SWAP_ARR : BlockType::ASS_ARR;
            b.expr1 = ctx->expression(0);
            b.expr2 = ctx->expression(1);
        } else {
            b.type = (b.op == AssignmentOp::SWAP) ? BlockType::SWAP_VAR : BlockType::ASS_VAR;
            b.expr1 = ctx->expression(0);
        }

        cfg.blocks[l] = b;
        return make_pair(l, l);
    }

    virtual any visitIfConstructor(janusParser::IfConstructorContext *ctx) override {
        Label lif = createLabel();
        Block bif;
        bif.id = lif;
        bif.type = BlockType::IF_HEAD;
        bif.condExpr = ctx->ifExpression()->expression();
        cfg.blocks[lif] = bif;

        auto [thenEntry, thenExit] = any_cast<pair<Label, Label>>(visit(ctx->ifExpression()->statements()));
        cfg.addEdge(lif, thenEntry);

        Label lfi = createLabel();
        Block bfi;
        bfi.id = lfi;
        bfi.type = BlockType::FI_HEAD;
        bfi.condExpr = ctx->fiExpression()->expression();
        cfg.blocks[lfi] = bfi;

        cfg.addEdge(thenExit, lfi);

        if (ctx->elseExpression()) {
            auto [elseEntry, elseExit] = any_cast<pair<Label, Label>>(visit(ctx->elseExpression()->statements()));
            cfg.addEdge(lif, elseEntry);
            cfg.addEdge(elseExit, lfi);
        } else {
            cfg.addEdge(lif, lfi);
        }

        return make_pair(lif, lfi);
    }

    virtual any visitLoopConstructor(janusParser::LoopConstructorContext *ctx) override {
        Label lfrom = createLabel();
        Block bfrom;
        bfrom.id = lfrom;
        bfrom.type = BlockType::FROM_HEAD;
        bfrom.condExpr = ctx->fromExp()->expression();
        cfg.blocks[lfrom] = bfrom;

        Label doEntryPoint = lfrom;
        Label doExitPoint = lfrom;

        if (ctx->doExp()) {
            auto [dEntry, dExit] = any_cast<pair<Label, Label>>(visit(ctx->doExp()->statements()));
            cfg.addEdge(lfrom, dEntry);
            doExitPoint = dExit;
        }

        Label lunt = createLabel();
        Block bunt;
        bunt.id = lunt;
        bunt.type = BlockType::UNTIL_HEAD;
        bunt.condExpr = ctx->untilExp()->expression();
        cfg.blocks[lunt] = bunt;

        cfg.addEdge(doExitPoint, lunt);

        if (ctx->loopExp()) {
            auto [lEntry, lExit] = any_cast<pair<Label, Label>>(visit(ctx->loopExp()->statements()));
            cfg.addEdge(lunt, lEntry);
            cfg.addEdge(lExit, doEntryPoint);
        } else {
            cfg.addEdge(lunt, doEntryPoint);
        }

        return make_pair(lfrom, lunt);
    }

    virtual any visitFunctionCall(janusParser::FunctionCallContext *ctx) override {
        Label l = createLabel();
        Block b;
        b.id = l;
        string callType = ctx->call()->getText();
        b.type = (callType == "call") ? BlockType::CALL : BlockType::UNCALL;
        b.procedurename = ctx->functionName()->getText();

        cfg.blocks[l] = b;
        return make_pair(l, l);
    }

    virtual any visitSkip(janusParser::SkipContext *ctx) override {
        Label l = createLabel();
        Block b{l, BlockType::SKIP};
        cfg.blocks[l] = b;
        return make_pair(l, l);
    }
};