
// Generated from janus.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "janusParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by janusParser.
 */
class  janusVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by janusParser.
   */
    virtual std::any visitProgram(janusParser::ProgramContext *context) = 0;

    virtual std::any visitVariables(janusParser::VariablesContext *context) = 0;

    virtual std::any visitFunctions(janusParser::FunctionsContext *context) = 0;

    virtual std::any visitFunction(janusParser::FunctionContext *context) = 0;

    virtual std::any visitStatements(janusParser::StatementsContext *context) = 0;

    virtual std::any visitAssignmentExpression(janusParser::AssignmentExpressionContext *context) = 0;

    virtual std::any visitIfConstructor(janusParser::IfConstructorContext *context) = 0;

    virtual std::any visitIfExpression(janusParser::IfExpressionContext *context) = 0;

    virtual std::any visitElseExpression(janusParser::ElseExpressionContext *context) = 0;

    virtual std::any visitFiExpression(janusParser::FiExpressionContext *context) = 0;

    virtual std::any visitLoopConstructor(janusParser::LoopConstructorContext *context) = 0;

    virtual std::any visitFromExp(janusParser::FromExpContext *context) = 0;

    virtual std::any visitUntilExp(janusParser::UntilExpContext *context) = 0;

    virtual std::any visitDoExp(janusParser::DoExpContext *context) = 0;

    virtual std::any visitLoopExp(janusParser::LoopExpContext *context) = 0;

    virtual std::any visitExpression(janusParser::ExpressionContext *context) = 0;

    virtual std::any visitFunctionCall(janusParser::FunctionCallContext *context) = 0;

    virtual std::any visitSkip(janusParser::SkipContext *context) = 0;

    virtual std::any visitAssignmentOperator(janusParser::AssignmentOperatorContext *context) = 0;

    virtual std::any visitRelationalOperator(janusParser::RelationalOperatorContext *context) = 0;

    virtual std::any visitArithmeticOperator(janusParser::ArithmeticOperatorContext *context) = 0;

    virtual std::any visitBitwiseOperator(janusParser::BitwiseOperatorContext *context) = 0;

    virtual std::any visitLogicalOperator(janusParser::LogicalOperatorContext *context) = 0;

    virtual std::any visitOperator(janusParser::OperatorContext *context) = 0;

    virtual std::any visitCall(janusParser::CallContext *context) = 0;

    virtual std::any visitVariableName(janusParser::VariableNameContext *context) = 0;

    virtual std::any visitFunctionName(janusParser::FunctionNameContext *context) = 0;


};

