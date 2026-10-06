#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <any>
#include <stdexcept>

#include "antlr4-runtime.h"
#include "janusLexer.h"
#include "janusParser.h"
#include "janusBaseVisitor.h"

using namespace std;

class JanusInterpreter : public janusBaseVisitor
{
private:
    bool reverse = false;
    map<size_t, size_t> debuglines;

public:
    map<string, int> variables;
    map<string, vector<int>> arrays;
    map<string, janusParser::FunctionContext *> procedures;

    JanusInterpreter(map<size_t, size_t> d) : debuglines(d) {}

    void checkDebug(antlr4::ParserRuleContext *ctx)
    {
        if (ctx && ctx->getStart())
        {
            size_t line = ctx->getStart()->getLine();
            string value = ctx->getText();

            if (auto ifctx = dynamic_cast<janusParser::IfExpressionContext *>(ctx))
            {
                if (ifctx->expression())
                    value = "if " + ifctx->expression()->getText();
            }
            else if (dynamic_cast<janusParser::DoExpContext *>(ctx))
            {
                value = "do";
            }
            else if (dynamic_cast<janusParser::LoopExpContext *>(ctx))
            {
                value = "loop";
            }
            else if (ctx->getStart()->getText() == "else")
            {
                value = "else";
            }

            if (debuglines.contains(line))
            {
                printVariables(line, ++debuglines[line], value);
                string input;
                getline(cin, input);
                if (input == "i")
                {
                    reverse = !reverse;
                }
            }
        }
    }

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
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitFunctions(janusParser::FunctionsContext *ctx) override
    {
        string procName = ctx->function()->functionName()->getText();
        if (procedures.contains(procName))
            throw runtime_error("each procedure must have a different name");
        else
            procedures[procName] = ctx->function();
        if (ctx->functions() != nullptr)
            return visit(ctx->functions());
        else
            return any();
    }

    void visitNextStatement(janusParser::StatementsContext *ctx)
    {
        if (!ctx)return;

        janusParser::StatementsContext *stmnt = ctx;

        while (stmnt != nullptr)
        {
            auto *parent = dynamic_cast<janusParser::StatementsContext *>(stmnt->parent);
            if (!parent)
            {
                return;
            }
            if (!reverse)
            {
                if (parent->statements(0) == stmnt)
                {
                    visit(parent->statements(1));
                    return;
                }
            }
            else
            {
                if (parent->statements(1) == stmnt)
                {
                    visit(parent->statements(0));
                    return;
                }
            }
            stmnt = parent;
        }

        return;
    }

    virtual any visitStatements(janusParser::StatementsContext *ctx) override
    {
        if (ctx->assignmentExpression() != nullptr)
        {
            visit(ctx->assignmentExpression());
            visitNextStatement(ctx);
            return any();
        }
        else if (ctx->ifConstructor() != nullptr)
        {
            visit(ctx->ifConstructor());
            visitNextStatement(ctx);
            return any();
        }
        else if (ctx->loopConstructor() != nullptr)
        {
            visit(ctx->loopConstructor());
            visitNextStatement(ctx);
            return any();
        }
        else if (ctx->functionCall() != nullptr)
        {
            visit(ctx->functionCall());
            visitNextStatement(ctx);
            return any();
        }
        else if (ctx->skip() != nullptr)
        {
            visit(ctx->skip());
            visitNextStatement(ctx);
            return any();
        }
        else
        {
            if (reverse)
            {
                visit(ctx->statements(1));
                return any();
            }
            else
            {
                visit(ctx->statements(0));
                return any();
            }
        }
    }

    virtual any visitExpression(janusParser::ExpressionContext *ctx) override
    {

        if (ctx->Digit())
        {
            return stoi(ctx->Digit()->getText());
        }
        else if (ctx->TextDigit())
        {
            string name = ctx->TextDigit()->getText();
            if (!ctx->expression().empty())
            {
                int index = any_cast<int>(visit(ctx->expression(0)));
                if (arrays.contains(name) && index >= 0 && index < (int)arrays[name].size())
                {
                    return arrays[name][index];
                }
                return 0;
            }
            return variables.contains(name) ? variables[name] : 0;
        }
        else if (ctx->expression().size() == 1 && ctx->children.size() == 3)
        {
            return visit(ctx->expression(0));
        }
        else if (ctx->expression().size() == 2 && ctx->operator_())
        {
            int a = any_cast<int>(visit(ctx->expression(0)));
            int b = any_cast<int>(visit(ctx->expression(1)));
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

    virtual any visitAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) override
    {
        string varName = ctx->variableName()->getText();
        string op = ctx->assignmentOperator()->getText();

        bool isArray = ctx->expression().size() > 1;
        int index = 0;
        int val = 0;

        if (isArray)
        {
            index = any_cast<int>(visit(ctx->expression(0)));
            val = any_cast<int>(visit(ctx->expression(1)));
        }
        else
        {
            val = any_cast<int>(visit(ctx->expression(0)));
        }

        auto getVal = [&]()
        {
            return isArray ? arrays[varName][index] : variables[varName];
        };

        auto setVal = [&](int v)
        {
            if (isArray)
                arrays[varName][index] = v;
            else
                variables[varName] = v;
        };

        auto assign = [&]()
        {
            if (op == "+=")
                reverse ? setVal(getVal() - val) : setVal(getVal() + val);
            else if (op == "-=")
                reverse ? setVal(getVal() + val) : setVal(getVal() - val);
            else if (op == "^=")
                setVal(getVal() ^ val);
            else if (op == "<=>")
            {
                int current = getVal();
                auto *expr = isArray ? ctx->expression(1) : ctx->expression(0);
                if (expr && expr->TextDigit() != nullptr)
                {
                    string varName2 = expr->TextDigit()->getText();
                    bool isArray2 = expr->children.size() > 1;
                    setVal(val);
                    if (isArray2)
                    {
                        int index2 = any_cast<int>(visit(expr->expression(0)));
                        arrays[varName2][index2] = current;
                    }
                    else
                    {
                        variables[varName2] = current;
                    }
                }
            }
        };

        assign();
        bool b = reverse;
        checkDebug(ctx);
        if (b != reverse)
        {
            assign();
        }
        return nullptr;
    }

    virtual any visitIfConstructor(janusParser::IfConstructorContext *ctx) override
    {

        auto assertion = [&](int i, any ret)
        {
            reverse ? checkDebug(ctx->ifExpression()) : checkDebug(ctx->fiExpression());
            int condition2 = reverse ? any_cast<int>(visit(ctx->ifExpression()->expression())) : any_cast<int>(visit(ctx->fiExpression()->expression()));
            if (!i)
                condition2 = !condition2;
            if (condition2)
                return ret;
            else
            {
                throw runtime_error("Test and assertion of an ifExpression must have the same value");
            }
        };

        bool iselse = ctx->elseExpression() != nullptr;
        reverse ? checkDebug(ctx->fiExpression()) : checkDebug(ctx->ifExpression());
        int condition1 = reverse ? any_cast<int>(visit(ctx->fiExpression()->expression())) : any_cast<int>(visit(ctx->ifExpression()->expression()));
        if (condition1)
        {
            any case_true = ctx->ifExpression()->statements() != nullptr ? visit(ctx->ifExpression()->statements()) : any();
            return assertion(1, case_true);
        }
        else
        {
            if (iselse)
            {
                checkDebug(ctx->elseExpression());
                any case_false = ctx->elseExpression()->statements() != nullptr ? visit(ctx->elseExpression()->statements()) : any();
                return assertion(0, case_false);
            }
            else
                return assertion(0, any());
        }
    }

    virtual any visitIfExpression(janusParser::IfExpressionContext *ctx) override
    {
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitFiExpression(janusParser::FiExpressionContext *ctx) override
    {
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitElseExpression(janusParser::ElseExpressionContext *ctx) override
    {
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitSkip(janusParser::SkipContext *ctx) override
    {
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitLoopConstructor(janusParser::LoopConstructorContext *ctx) override
    {

        auto evalFrom = [&]()
        {
            if (reverse)
            {
                return any_cast<int>(visit(ctx->untilExp()));
            }
            else
            {
                return any_cast<int>(visit(ctx->fromExp()));
            }
        };

        auto evalUntil = [&]()
        {
            if (reverse)
            {
                return any_cast<int>(visit(ctx->fromExp()));
            }
            else
            {
                return any_cast<int>(visit(ctx->untilExp()));
            }
        };

        int assertion = evalFrom();
        if (assertion)
        {
            do
            {

                if (ctx->doExp() != nullptr)
                    visit(ctx->doExp());
                int test = evalUntil();
                if (test != 0)
                    return any();
                if (ctx->loopExp() != nullptr)
                    visit(ctx->loopExp());
                assertion = evalFrom();

            } while (assertion == 0);
            throw runtime_error("assertion of a loopExpression must be false each time it re-evaluates");
        }
        else
            throw runtime_error("assertion of a loopExpression must be true when evaluated for the first time");
    }

    virtual any visitFromExp(janusParser::FromExpContext *ctx) override
    {
        checkDebug(ctx);
        return visit(ctx->expression());
    }

    virtual any visitUntilExp(janusParser::UntilExpContext *ctx) override
    {
        checkDebug(ctx);
        return visit(ctx->expression());
    }

    virtual any visitDoExp(janusParser::DoExpContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual any visitLoopExp(janusParser::LoopExpContext *ctx) override
    {
        checkDebug(ctx);
        return visitChildren(ctx);
    }

    virtual any visitFunctionCall(janusParser::FunctionCallContext *ctx) override
    {
        checkDebug(ctx);
        string type = ctx->call()->getText();
        string name = ctx->functionName()->getText();
        if (!procedures.contains(name))
            throw runtime_error("no procedure with name: " + name);
        if (type == "call")
            visit(procedures[name]);
        else
        {
            bool r = reverse;
            reverse = !reverse;
            visit(procedures[name]);
            reverse = r;
        }
        return any();
    }

    void visitMain(string main)
    {
        if (main == "")
            main = "main";
        procedures.contains(main) ? visit(procedures[main]) : throw runtime_error("No procedure with name: " + main);
    }

    void printVariables(size_t line = 0, size_t it = 0, string value = "")
    {
        cout << "\033[u\033[0J";
        if (line)
            cout << "\n[DEBUG BREAKPOINT: LINE " << line << " OPERATION: " + value + " ITERATION: " << it << " ] (Press ENTER for next step) " << endl;
        else
            cout << "\n=============| END OF PROGRAM |==============";

        cout << "\n=============|   VARIABLES    |==============" << endl;

        for (auto &[name, val] : variables)
        {
            cout << name << " = " << val << endl;
        }
        for (auto &[name, vec] : arrays)
        {
            cout << name << "[" << vec.size() << "] = [ ";
            for (auto i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << " ";
            }
            cout << "]" << endl;
        }
        cout << "=============================================\n"
             << endl;
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
    string main = "";
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

    JanusInterpreter interpreter(debuglines);
    try
    {
        interpreter.visit(tree);
        interpreter.visitMain(main);
        interpreter.printVariables();
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}