
// Generated from janus.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "janusListener.h"


/**
 * This class provides an empty implementation of janusListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  janusBaseListener : public janusListener {
public:

  virtual void enterProgram(janusParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(janusParser::ProgramContext * /*ctx*/) override { }

  virtual void enterVariables(janusParser::VariablesContext * /*ctx*/) override { }
  virtual void exitVariables(janusParser::VariablesContext * /*ctx*/) override { }

  virtual void enterFunctions(janusParser::FunctionsContext * /*ctx*/) override { }
  virtual void exitFunctions(janusParser::FunctionsContext * /*ctx*/) override { }

  virtual void enterFunction(janusParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(janusParser::FunctionContext * /*ctx*/) override { }

  virtual void enterStatements(janusParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(janusParser::StatementsContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(janusParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(janusParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterIfConstructor(janusParser::IfConstructorContext * /*ctx*/) override { }
  virtual void exitIfConstructor(janusParser::IfConstructorContext * /*ctx*/) override { }

  virtual void enterIfExpression(janusParser::IfExpressionContext * /*ctx*/) override { }
  virtual void exitIfExpression(janusParser::IfExpressionContext * /*ctx*/) override { }

  virtual void enterElseExpression(janusParser::ElseExpressionContext * /*ctx*/) override { }
  virtual void exitElseExpression(janusParser::ElseExpressionContext * /*ctx*/) override { }

  virtual void enterFiExpression(janusParser::FiExpressionContext * /*ctx*/) override { }
  virtual void exitFiExpression(janusParser::FiExpressionContext * /*ctx*/) override { }

  virtual void enterLoopConstructor(janusParser::LoopConstructorContext * /*ctx*/) override { }
  virtual void exitLoopConstructor(janusParser::LoopConstructorContext * /*ctx*/) override { }

  virtual void enterFromExp(janusParser::FromExpContext * /*ctx*/) override { }
  virtual void exitFromExp(janusParser::FromExpContext * /*ctx*/) override { }

  virtual void enterUntilExp(janusParser::UntilExpContext * /*ctx*/) override { }
  virtual void exitUntilExp(janusParser::UntilExpContext * /*ctx*/) override { }

  virtual void enterDoExp(janusParser::DoExpContext * /*ctx*/) override { }
  virtual void exitDoExp(janusParser::DoExpContext * /*ctx*/) override { }

  virtual void enterLoopExp(janusParser::LoopExpContext * /*ctx*/) override { }
  virtual void exitLoopExp(janusParser::LoopExpContext * /*ctx*/) override { }

  virtual void enterExpression(janusParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(janusParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionCall(janusParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(janusParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterSkip(janusParser::SkipContext * /*ctx*/) override { }
  virtual void exitSkip(janusParser::SkipContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(janusParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(janusParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterRelationalOperator(janusParser::RelationalOperatorContext * /*ctx*/) override { }
  virtual void exitRelationalOperator(janusParser::RelationalOperatorContext * /*ctx*/) override { }

  virtual void enterArithmeticOperator(janusParser::ArithmeticOperatorContext * /*ctx*/) override { }
  virtual void exitArithmeticOperator(janusParser::ArithmeticOperatorContext * /*ctx*/) override { }

  virtual void enterBitwiseOperator(janusParser::BitwiseOperatorContext * /*ctx*/) override { }
  virtual void exitBitwiseOperator(janusParser::BitwiseOperatorContext * /*ctx*/) override { }

  virtual void enterLogicalOperator(janusParser::LogicalOperatorContext * /*ctx*/) override { }
  virtual void exitLogicalOperator(janusParser::LogicalOperatorContext * /*ctx*/) override { }

  virtual void enterOperator(janusParser::OperatorContext * /*ctx*/) override { }
  virtual void exitOperator(janusParser::OperatorContext * /*ctx*/) override { }

  virtual void enterCall(janusParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(janusParser::CallContext * /*ctx*/) override { }

  virtual void enterVariableName(janusParser::VariableNameContext * /*ctx*/) override { }
  virtual void exitVariableName(janusParser::VariableNameContext * /*ctx*/) override { }

  virtual void enterFunctionName(janusParser::FunctionNameContext * /*ctx*/) override { }
  virtual void exitFunctionName(janusParser::FunctionNameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

