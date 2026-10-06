
// Generated from janus.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "janusVisitor.h"


/**
 * This class provides an empty implementation of janusVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  janusBaseVisitor : public janusVisitor {
public:

  virtual std::any visitProgram(janusParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariables(janusParser::VariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctions(janusParser::FunctionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(janusParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(janusParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentExpression(janusParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfConstructor(janusParser::IfConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExpression(janusParser::IfExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseExpression(janusParser::ElseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFiExpression(janusParser::FiExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopConstructor(janusParser::LoopConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFromExp(janusParser::FromExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUntilExp(janusParser::UntilExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoExp(janusParser::DoExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopExp(janusParser::LoopExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(janusParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(janusParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSkip(janusParser::SkipContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOperator(janusParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalOperator(janusParser::RelationalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithmeticOperator(janusParser::ArithmeticOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwiseOperator(janusParser::BitwiseOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOperator(janusParser::LogicalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperator(janusParser::OperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(janusParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableName(janusParser::VariableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionName(janusParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }


};

