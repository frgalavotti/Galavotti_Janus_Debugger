
// Generated from janus.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "janusParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by janusParser.
 */
class  janusListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(janusParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(janusParser::ProgramContext *ctx) = 0;

  virtual void enterVariables(janusParser::VariablesContext *ctx) = 0;
  virtual void exitVariables(janusParser::VariablesContext *ctx) = 0;

  virtual void enterFunctions(janusParser::FunctionsContext *ctx) = 0;
  virtual void exitFunctions(janusParser::FunctionsContext *ctx) = 0;

  virtual void enterFunction(janusParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(janusParser::FunctionContext *ctx) = 0;

  virtual void enterStatements(janusParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(janusParser::StatementsContext *ctx) = 0;

  virtual void enterAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterIfConstructor(janusParser::IfConstructorContext *ctx) = 0;
  virtual void exitIfConstructor(janusParser::IfConstructorContext *ctx) = 0;

  virtual void enterIfExpression(janusParser::IfExpressionContext *ctx) = 0;
  virtual void exitIfExpression(janusParser::IfExpressionContext *ctx) = 0;

  virtual void enterElseExpression(janusParser::ElseExpressionContext *ctx) = 0;
  virtual void exitElseExpression(janusParser::ElseExpressionContext *ctx) = 0;

  virtual void enterFiExpression(janusParser::FiExpressionContext *ctx) = 0;
  virtual void exitFiExpression(janusParser::FiExpressionContext *ctx) = 0;

  virtual void enterLoopConstructor(janusParser::LoopConstructorContext *ctx) = 0;
  virtual void exitLoopConstructor(janusParser::LoopConstructorContext *ctx) = 0;

  virtual void enterFromExp(janusParser::FromExpContext *ctx) = 0;
  virtual void exitFromExp(janusParser::FromExpContext *ctx) = 0;

  virtual void enterUntilExp(janusParser::UntilExpContext *ctx) = 0;
  virtual void exitUntilExp(janusParser::UntilExpContext *ctx) = 0;

  virtual void enterDoExp(janusParser::DoExpContext *ctx) = 0;
  virtual void exitDoExp(janusParser::DoExpContext *ctx) = 0;

  virtual void enterLoopExp(janusParser::LoopExpContext *ctx) = 0;
  virtual void exitLoopExp(janusParser::LoopExpContext *ctx) = 0;

  virtual void enterExpression(janusParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(janusParser::ExpressionContext *ctx) = 0;

  virtual void enterFunctionCall(janusParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(janusParser::FunctionCallContext *ctx) = 0;

  virtual void enterSkip(janusParser::SkipContext *ctx) = 0;
  virtual void exitSkip(janusParser::SkipContext *ctx) = 0;

  virtual void enterAssignmentOperator(janusParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(janusParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterRelationalOperator(janusParser::RelationalOperatorContext *ctx) = 0;
  virtual void exitRelationalOperator(janusParser::RelationalOperatorContext *ctx) = 0;

  virtual void enterArithmeticOperator(janusParser::ArithmeticOperatorContext *ctx) = 0;
  virtual void exitArithmeticOperator(janusParser::ArithmeticOperatorContext *ctx) = 0;

  virtual void enterBitwiseOperator(janusParser::BitwiseOperatorContext *ctx) = 0;
  virtual void exitBitwiseOperator(janusParser::BitwiseOperatorContext *ctx) = 0;

  virtual void enterLogicalOperator(janusParser::LogicalOperatorContext *ctx) = 0;
  virtual void exitLogicalOperator(janusParser::LogicalOperatorContext *ctx) = 0;

  virtual void enterOperator(janusParser::OperatorContext *ctx) = 0;
  virtual void exitOperator(janusParser::OperatorContext *ctx) = 0;

  virtual void enterCall(janusParser::CallContext *ctx) = 0;
  virtual void exitCall(janusParser::CallContext *ctx) = 0;

  virtual void enterVariableName(janusParser::VariableNameContext *ctx) = 0;
  virtual void exitVariableName(janusParser::VariableNameContext *ctx) = 0;

  virtual void enterFunctionName(janusParser::FunctionNameContext *ctx) = 0;
  virtual void exitFunctionName(janusParser::FunctionNameContext *ctx) = 0;


};

