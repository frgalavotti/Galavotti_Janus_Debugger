#pragma once

#include <string>
#include <vector>
#include <map>

#include "antlr4-runtime.h"
#include "janusParser.h"

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
    IF,
    FI,
    FROM,
    UNTIL
};

struct Block
{
    Label label;
    BlockType type;
    Label line;

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
    Label l;
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
        case BlockType::IF:return "IF";
        case BlockType::FI:return "FI";
        case BlockType::FROM:return "FROM";
        case BlockType::UNTIL:return "UNTIL";
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