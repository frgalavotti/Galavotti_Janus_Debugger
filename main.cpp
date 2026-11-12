#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <set>

#include "antlr4-runtime.h"
#include "janusLexer.h"
#include "janusParser.h"

#include "structures.h"
#include "CFGbuilder.h"
#include "ReversibleJanusInterpreter.h"

using namespace std;

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

    set<size_t> debuglines;
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
                cerr << "-m requires the name of the main function afterwards" << endl;
                return 1;
            }
        }
        else if (string(argv[i]) == "-d")
        {
            while ((i + 1 < argc) && (string(argv[i + 1]) != "-m"))
            {
                try
                {
                    debuglines.insert(stoul(argv[i + 1]));
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
                interpreter.printState("End of program reached");
            else interpreter.printState();
        }
        else if (cmd == "b")
        {
            if (!interpreter.stepBackward())
                interpreter.printState("Start of program reached");
            else interpreter.printState();
        }
        else if (cmd == "ff")
        {
            while(true)
            {
                if (!interpreter.stepForward()){
                interpreter.printState("End of program reached");
                break;}
                if(debuglines.contains(interpreter.cfg.blocks[interpreter.l2].line)){
                    interpreter.printState();
                    break;
                }
            }
        }
        else if (cmd == "bb")
        {
            while(true)
            {
                if (!interpreter.stepBackward()){
                interpreter.printState("Start of program reached");
                break;}
                if(debuglines.contains(interpreter.cfg.blocks[interpreter.l1].line)){
                    interpreter.printState();
                    break;
                }
            }
        }
    }
    }
    catch (const exception &e)
    {
        cerr << "execution error: " << e.what() << "\n";
    }
    return 0;
}