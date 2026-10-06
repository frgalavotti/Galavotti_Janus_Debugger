
// Generated from janus.g4 by ANTLR 4.10


#include "janusListener.h"
#include "janusVisitor.h"

#include "janusParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct JanusParserStaticData final {
  JanusParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JanusParserStaticData(const JanusParserStaticData&) = delete;
  JanusParserStaticData(JanusParserStaticData&&) = delete;
  JanusParserStaticData& operator=(const JanusParserStaticData&) = delete;
  JanusParserStaticData& operator=(JanusParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag janusParserOnceFlag;
JanusParserStaticData *janusParserStaticData = nullptr;

void janusParserInitialize() {
  assert(janusParserStaticData == nullptr);
  auto staticData = std::make_unique<JanusParserStaticData>(
    std::vector<std::string>{
      "program", "variables", "functions", "function", "statements", "assignmentExpression", 
      "ifConstructor", "ifExpression", "elseExpression", "fiExpression", 
      "loopConstructor", "fromExp", "untilExp", "doExp", "loopExp", "expression", 
      "functionCall", "skip", "assignmentOperator", "relationalOperator", 
      "arithmeticOperator", "bitwiseOperator", "logicalOperator", "operator", 
      "call", "variableName", "functionName"
    },
    std::vector<std::string>{
      "", "'['", "']'", "'procedure'", "'if'", "'('", "')'", "'then'", "'else'", 
      "'fi'", "'from'", "'until'", "'do'", "'loop'", "'skip'", "'+='", "'-='", 
      "'<=>'", "'^='", "'='", "'!='", "'<'", "'>'", "'<='", "'>='", "'*'", 
      "'+'", "'-'", "'/'", "'%'", "'&'", "'|'", "'^'", "'&&'", "'||'", "'call'", 
      "'uncall'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "Digit", "TextDigit", "WS", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,208,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,3,0,56,8,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,65,8,1,1,1,1,1,5,1,69,8,1,10,1,12,1,72,
  	9,1,1,2,1,2,1,2,1,2,3,2,78,8,2,1,3,1,3,1,3,3,3,83,8,3,1,4,1,4,1,4,1,4,
  	1,4,1,4,3,4,91,8,4,1,4,1,4,5,4,95,8,4,10,4,12,4,98,9,4,1,5,1,5,1,5,1,
  	5,1,5,3,5,105,8,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,117,8,6,
  	1,7,1,7,3,7,121,8,7,1,7,1,7,3,7,125,8,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,
  	9,1,9,1,10,1,10,3,10,138,8,10,1,10,3,10,141,8,10,1,10,1,10,1,11,1,11,
  	1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,3,15,164,8,15,1,15,1,15,1,15,1,15,3,15,170,8,15,1,15,1,
  	15,1,15,1,15,5,15,176,8,15,10,15,12,15,179,9,15,1,16,1,16,1,16,1,17,1,
  	17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,
  	23,3,23,200,8,23,1,24,1,24,1,25,1,25,1,26,1,26,1,26,0,3,2,8,30,27,0,2,
  	4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,0,6,1,0,15,18,1,0,19,24,1,0,25,29,1,0,30,32,1,0,33,34,1,0,35,36,203,
  	0,55,1,0,0,0,2,59,1,0,0,0,4,77,1,0,0,0,6,79,1,0,0,0,8,90,1,0,0,0,10,99,
  	1,0,0,0,12,116,1,0,0,0,14,118,1,0,0,0,16,129,1,0,0,0,18,132,1,0,0,0,20,
  	135,1,0,0,0,22,144,1,0,0,0,24,147,1,0,0,0,26,150,1,0,0,0,28,153,1,0,0,
  	0,30,169,1,0,0,0,32,180,1,0,0,0,34,183,1,0,0,0,36,185,1,0,0,0,38,187,
  	1,0,0,0,40,189,1,0,0,0,42,191,1,0,0,0,44,193,1,0,0,0,46,199,1,0,0,0,48,
  	201,1,0,0,0,50,203,1,0,0,0,52,205,1,0,0,0,54,56,3,2,1,0,55,54,1,0,0,0,
  	55,56,1,0,0,0,56,57,1,0,0,0,57,58,3,4,2,0,58,1,1,0,0,0,59,60,6,1,-1,0,
  	60,64,3,50,25,0,61,62,5,1,0,0,62,63,5,37,0,0,63,65,5,2,0,0,64,61,1,0,
  	0,0,64,65,1,0,0,0,65,70,1,0,0,0,66,67,10,1,0,0,67,69,3,2,1,2,68,66,1,
  	0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,3,1,0,0,0,72,70,1,
  	0,0,0,73,78,3,6,3,0,74,75,3,6,3,0,75,76,3,4,2,0,76,78,1,0,0,0,77,73,1,
  	0,0,0,77,74,1,0,0,0,78,5,1,0,0,0,79,80,5,3,0,0,80,82,3,52,26,0,81,83,
  	3,8,4,0,82,81,1,0,0,0,82,83,1,0,0,0,83,7,1,0,0,0,84,85,6,4,-1,0,85,91,
  	3,10,5,0,86,91,3,12,6,0,87,91,3,20,10,0,88,91,3,32,16,0,89,91,3,34,17,
  	0,90,84,1,0,0,0,90,86,1,0,0,0,90,87,1,0,0,0,90,88,1,0,0,0,90,89,1,0,0,
  	0,91,96,1,0,0,0,92,93,10,1,0,0,93,95,3,8,4,2,94,92,1,0,0,0,95,98,1,0,
  	0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,9,1,0,0,0,98,96,1,0,0,0,99,104,3,50,
  	25,0,100,101,5,1,0,0,101,102,3,30,15,0,102,103,5,2,0,0,103,105,1,0,0,
  	0,104,100,1,0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,107,3,36,18,0,107,
  	108,3,30,15,0,108,11,1,0,0,0,109,110,3,14,7,0,110,111,3,18,9,0,111,117,
  	1,0,0,0,112,113,3,14,7,0,113,114,3,16,8,0,114,115,3,18,9,0,115,117,1,
  	0,0,0,116,109,1,0,0,0,116,112,1,0,0,0,117,13,1,0,0,0,118,120,5,4,0,0,
  	119,121,5,5,0,0,120,119,1,0,0,0,120,121,1,0,0,0,121,122,1,0,0,0,122,124,
  	3,30,15,0,123,125,5,6,0,0,124,123,1,0,0,0,124,125,1,0,0,0,125,126,1,0,
  	0,0,126,127,5,7,0,0,127,128,3,8,4,0,128,15,1,0,0,0,129,130,5,8,0,0,130,
  	131,3,8,4,0,131,17,1,0,0,0,132,133,5,9,0,0,133,134,3,30,15,0,134,19,1,
  	0,0,0,135,137,3,22,11,0,136,138,3,26,13,0,137,136,1,0,0,0,137,138,1,0,
  	0,0,138,140,1,0,0,0,139,141,3,28,14,0,140,139,1,0,0,0,140,141,1,0,0,0,
  	141,142,1,0,0,0,142,143,3,24,12,0,143,21,1,0,0,0,144,145,5,10,0,0,145,
  	146,3,30,15,0,146,23,1,0,0,0,147,148,5,11,0,0,148,149,3,30,15,0,149,25,
  	1,0,0,0,150,151,5,12,0,0,151,152,3,8,4,0,152,27,1,0,0,0,153,154,5,13,
  	0,0,154,155,3,8,4,0,155,29,1,0,0,0,156,157,6,15,-1,0,157,170,5,37,0,0,
  	158,163,5,38,0,0,159,160,5,1,0,0,160,161,3,30,15,0,161,162,5,2,0,0,162,
  	164,1,0,0,0,163,159,1,0,0,0,163,164,1,0,0,0,164,170,1,0,0,0,165,166,5,
  	5,0,0,166,167,3,30,15,0,167,168,5,6,0,0,168,170,1,0,0,0,169,156,1,0,0,
  	0,169,158,1,0,0,0,169,165,1,0,0,0,170,177,1,0,0,0,171,172,10,2,0,0,172,
  	173,3,46,23,0,173,174,3,30,15,3,174,176,1,0,0,0,175,171,1,0,0,0,176,179,
  	1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,31,1,0,0,0,179,177,1,0,0,
  	0,180,181,3,48,24,0,181,182,3,52,26,0,182,33,1,0,0,0,183,184,5,14,0,0,
  	184,35,1,0,0,0,185,186,7,0,0,0,186,37,1,0,0,0,187,188,7,1,0,0,188,39,
  	1,0,0,0,189,190,7,2,0,0,190,41,1,0,0,0,191,192,7,3,0,0,192,43,1,0,0,0,
  	193,194,7,4,0,0,194,45,1,0,0,0,195,200,3,40,20,0,196,200,3,42,21,0,197,
  	200,3,38,19,0,198,200,3,44,22,0,199,195,1,0,0,0,199,196,1,0,0,0,199,197,
  	1,0,0,0,199,198,1,0,0,0,200,47,1,0,0,0,201,202,7,5,0,0,202,49,1,0,0,0,
  	203,204,5,38,0,0,204,51,1,0,0,0,205,206,5,38,0,0,206,53,1,0,0,0,17,55,
  	64,70,77,82,90,96,104,116,120,124,137,140,163,169,177,199
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  janusParserStaticData = staticData.release();
}

}

janusParser::janusParser(TokenStream *input) : janusParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

janusParser::janusParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  janusParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *janusParserStaticData->atn, janusParserStaticData->decisionToDFA, janusParserStaticData->sharedContextCache, options);
}

janusParser::~janusParser() {
  delete _interpreter;
}

const atn::ATN& janusParser::getATN() const {
  return *janusParserStaticData->atn;
}

std::string janusParser::getGrammarFileName() const {
  return "janus.g4";
}

const std::vector<std::string>& janusParser::getRuleNames() const {
  return janusParserStaticData->ruleNames;
}

const dfa::Vocabulary& janusParser::getVocabulary() const {
  return janusParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView janusParser::getSerializedATN() const {
  return janusParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

janusParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::FunctionsContext* janusParser::ProgramContext::functions() {
  return getRuleContext<janusParser::FunctionsContext>(0);
}

janusParser::VariablesContext* janusParser::ProgramContext::variables() {
  return getRuleContext<janusParser::VariablesContext>(0);
}


size_t janusParser::ProgramContext::getRuleIndex() const {
  return janusParser::RuleProgram;
}

void janusParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void janusParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any janusParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

janusParser::ProgramContext* janusParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, janusParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == janusParser::TextDigit) {
      setState(54);
      variables(0);
    }
    setState(57);
    functions();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

janusParser::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::VariableNameContext* janusParser::VariablesContext::variableName() {
  return getRuleContext<janusParser::VariableNameContext>(0);
}

tree::TerminalNode* janusParser::VariablesContext::Digit() {
  return getToken(janusParser::Digit, 0);
}

std::vector<janusParser::VariablesContext *> janusParser::VariablesContext::variables() {
  return getRuleContexts<janusParser::VariablesContext>();
}

janusParser::VariablesContext* janusParser::VariablesContext::variables(size_t i) {
  return getRuleContext<janusParser::VariablesContext>(i);
}


size_t janusParser::VariablesContext::getRuleIndex() const {
  return janusParser::RuleVariables;
}

void janusParser::VariablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariables(this);
}

void janusParser::VariablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariables(this);
}


std::any janusParser::VariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitVariables(this);
  else
    return visitor->visitChildren(this);
}


janusParser::VariablesContext* janusParser::variables() {
   return variables(0);
}

janusParser::VariablesContext* janusParser::variables(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  janusParser::VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, parentState);
  janusParser::VariablesContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, janusParser::RuleVariables, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(60);
    variableName();
    setState(64);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(61);
      match(janusParser::T__0);
      setState(62);
      match(janusParser::Digit);
      setState(63);
      match(janusParser::T__1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(70);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VariablesContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleVariables);
        setState(66);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(67);
        variables(2); 
      }
      setState(72);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FunctionsContext ------------------------------------------------------------------

janusParser::FunctionsContext::FunctionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::FunctionContext* janusParser::FunctionsContext::function() {
  return getRuleContext<janusParser::FunctionContext>(0);
}

janusParser::FunctionsContext* janusParser::FunctionsContext::functions() {
  return getRuleContext<janusParser::FunctionsContext>(0);
}


size_t janusParser::FunctionsContext::getRuleIndex() const {
  return janusParser::RuleFunctions;
}

void janusParser::FunctionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctions(this);
}

void janusParser::FunctionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctions(this);
}


std::any janusParser::FunctionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFunctions(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FunctionsContext* janusParser::functions() {
  FunctionsContext *_localctx = _tracker.createInstance<FunctionsContext>(_ctx, getState());
  enterRule(_localctx, 4, janusParser::RuleFunctions);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(73);
      function();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      function();
      setState(75);
      functions();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

janusParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::FunctionNameContext* janusParser::FunctionContext::functionName() {
  return getRuleContext<janusParser::FunctionNameContext>(0);
}

janusParser::StatementsContext* janusParser::FunctionContext::statements() {
  return getRuleContext<janusParser::StatementsContext>(0);
}


size_t janusParser::FunctionContext::getRuleIndex() const {
  return janusParser::RuleFunction;
}

void janusParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void janusParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any janusParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FunctionContext* janusParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, janusParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(janusParser::T__2);
    setState(80);
    functionName();
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << janusParser::T__3)
      | (1ULL << janusParser::T__9)
      | (1ULL << janusParser::T__13)
      | (1ULL << janusParser::T__34)
      | (1ULL << janusParser::T__35)
      | (1ULL << janusParser::TextDigit))) != 0)) {
      setState(81);
      statements(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

janusParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::AssignmentExpressionContext* janusParser::StatementsContext::assignmentExpression() {
  return getRuleContext<janusParser::AssignmentExpressionContext>(0);
}

janusParser::IfConstructorContext* janusParser::StatementsContext::ifConstructor() {
  return getRuleContext<janusParser::IfConstructorContext>(0);
}

janusParser::LoopConstructorContext* janusParser::StatementsContext::loopConstructor() {
  return getRuleContext<janusParser::LoopConstructorContext>(0);
}

janusParser::FunctionCallContext* janusParser::StatementsContext::functionCall() {
  return getRuleContext<janusParser::FunctionCallContext>(0);
}

janusParser::SkipContext* janusParser::StatementsContext::skip() {
  return getRuleContext<janusParser::SkipContext>(0);
}

std::vector<janusParser::StatementsContext *> janusParser::StatementsContext::statements() {
  return getRuleContexts<janusParser::StatementsContext>();
}

janusParser::StatementsContext* janusParser::StatementsContext::statements(size_t i) {
  return getRuleContext<janusParser::StatementsContext>(i);
}


size_t janusParser::StatementsContext::getRuleIndex() const {
  return janusParser::RuleStatements;
}

void janusParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void janusParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


std::any janusParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}


janusParser::StatementsContext* janusParser::statements() {
   return statements(0);
}

janusParser::StatementsContext* janusParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  janusParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  janusParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, janusParser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case janusParser::TextDigit: {
        setState(85);
        assignmentExpression();
        break;
      }

      case janusParser::T__3: {
        setState(86);
        ifConstructor();
        break;
      }

      case janusParser::T__9: {
        setState(87);
        loopConstructor();
        break;
      }

      case janusParser::T__34:
      case janusParser::T__35: {
        setState(88);
        functionCall();
        break;
      }

      case janusParser::T__13: {
        setState(89);
        skip();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(96);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(92);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(93);
        statements(2); 
      }
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

janusParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::VariableNameContext* janusParser::AssignmentExpressionContext::variableName() {
  return getRuleContext<janusParser::VariableNameContext>(0);
}

janusParser::AssignmentOperatorContext* janusParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<janusParser::AssignmentOperatorContext>(0);
}

std::vector<janusParser::ExpressionContext *> janusParser::AssignmentExpressionContext::expression() {
  return getRuleContexts<janusParser::ExpressionContext>();
}

janusParser::ExpressionContext* janusParser::AssignmentExpressionContext::expression(size_t i) {
  return getRuleContext<janusParser::ExpressionContext>(i);
}


size_t janusParser::AssignmentExpressionContext::getRuleIndex() const {
  return janusParser::RuleAssignmentExpression;
}

void janusParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void janusParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


std::any janusParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

janusParser::AssignmentExpressionContext* janusParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, janusParser::RuleAssignmentExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    variableName();
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == janusParser::T__0) {
      setState(100);
      match(janusParser::T__0);
      setState(101);
      expression(0);
      setState(102);
      match(janusParser::T__1);
    }
    setState(106);
    assignmentOperator();
    setState(107);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfConstructorContext ------------------------------------------------------------------

janusParser::IfConstructorContext::IfConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::IfExpressionContext* janusParser::IfConstructorContext::ifExpression() {
  return getRuleContext<janusParser::IfExpressionContext>(0);
}

janusParser::FiExpressionContext* janusParser::IfConstructorContext::fiExpression() {
  return getRuleContext<janusParser::FiExpressionContext>(0);
}

janusParser::ElseExpressionContext* janusParser::IfConstructorContext::elseExpression() {
  return getRuleContext<janusParser::ElseExpressionContext>(0);
}


size_t janusParser::IfConstructorContext::getRuleIndex() const {
  return janusParser::RuleIfConstructor;
}

void janusParser::IfConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfConstructor(this);
}

void janusParser::IfConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfConstructor(this);
}


std::any janusParser::IfConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitIfConstructor(this);
  else
    return visitor->visitChildren(this);
}

janusParser::IfConstructorContext* janusParser::ifConstructor() {
  IfConstructorContext *_localctx = _tracker.createInstance<IfConstructorContext>(_ctx, getState());
  enterRule(_localctx, 12, janusParser::RuleIfConstructor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      ifExpression();
      setState(110);
      fiExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      ifExpression();
      setState(113);
      elseExpression();
      setState(114);
      fiExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExpressionContext ------------------------------------------------------------------

janusParser::IfExpressionContext::IfExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::ExpressionContext* janusParser::IfExpressionContext::expression() {
  return getRuleContext<janusParser::ExpressionContext>(0);
}

janusParser::StatementsContext* janusParser::IfExpressionContext::statements() {
  return getRuleContext<janusParser::StatementsContext>(0);
}


size_t janusParser::IfExpressionContext::getRuleIndex() const {
  return janusParser::RuleIfExpression;
}

void janusParser::IfExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpression(this);
}

void janusParser::IfExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpression(this);
}


std::any janusParser::IfExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitIfExpression(this);
  else
    return visitor->visitChildren(this);
}

janusParser::IfExpressionContext* janusParser::ifExpression() {
  IfExpressionContext *_localctx = _tracker.createInstance<IfExpressionContext>(_ctx, getState());
  enterRule(_localctx, 14, janusParser::RuleIfExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(janusParser::T__3);
    setState(120);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(119);
      match(janusParser::T__4);
      break;
    }

    default:
      break;
    }
    setState(122);
    expression(0);
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == janusParser::T__5) {
      setState(123);
      match(janusParser::T__5);
    }
    setState(126);
    match(janusParser::T__6);
    setState(127);
    statements(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseExpressionContext ------------------------------------------------------------------

janusParser::ElseExpressionContext::ElseExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::StatementsContext* janusParser::ElseExpressionContext::statements() {
  return getRuleContext<janusParser::StatementsContext>(0);
}


size_t janusParser::ElseExpressionContext::getRuleIndex() const {
  return janusParser::RuleElseExpression;
}

void janusParser::ElseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseExpression(this);
}

void janusParser::ElseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseExpression(this);
}


std::any janusParser::ElseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitElseExpression(this);
  else
    return visitor->visitChildren(this);
}

janusParser::ElseExpressionContext* janusParser::elseExpression() {
  ElseExpressionContext *_localctx = _tracker.createInstance<ElseExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, janusParser::RuleElseExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(janusParser::T__7);
    setState(130);
    statements(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FiExpressionContext ------------------------------------------------------------------

janusParser::FiExpressionContext::FiExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::ExpressionContext* janusParser::FiExpressionContext::expression() {
  return getRuleContext<janusParser::ExpressionContext>(0);
}


size_t janusParser::FiExpressionContext::getRuleIndex() const {
  return janusParser::RuleFiExpression;
}

void janusParser::FiExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFiExpression(this);
}

void janusParser::FiExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFiExpression(this);
}


std::any janusParser::FiExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFiExpression(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FiExpressionContext* janusParser::fiExpression() {
  FiExpressionContext *_localctx = _tracker.createInstance<FiExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, janusParser::RuleFiExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(janusParser::T__8);
    setState(133);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopConstructorContext ------------------------------------------------------------------

janusParser::LoopConstructorContext::LoopConstructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::FromExpContext* janusParser::LoopConstructorContext::fromExp() {
  return getRuleContext<janusParser::FromExpContext>(0);
}

janusParser::UntilExpContext* janusParser::LoopConstructorContext::untilExp() {
  return getRuleContext<janusParser::UntilExpContext>(0);
}

janusParser::DoExpContext* janusParser::LoopConstructorContext::doExp() {
  return getRuleContext<janusParser::DoExpContext>(0);
}

janusParser::LoopExpContext* janusParser::LoopConstructorContext::loopExp() {
  return getRuleContext<janusParser::LoopExpContext>(0);
}


size_t janusParser::LoopConstructorContext::getRuleIndex() const {
  return janusParser::RuleLoopConstructor;
}

void janusParser::LoopConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopConstructor(this);
}

void janusParser::LoopConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopConstructor(this);
}


std::any janusParser::LoopConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitLoopConstructor(this);
  else
    return visitor->visitChildren(this);
}

janusParser::LoopConstructorContext* janusParser::loopConstructor() {
  LoopConstructorContext *_localctx = _tracker.createInstance<LoopConstructorContext>(_ctx, getState());
  enterRule(_localctx, 20, janusParser::RuleLoopConstructor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    fromExp();
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == janusParser::T__11) {
      setState(136);
      doExp();
    }
    setState(140);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == janusParser::T__12) {
      setState(139);
      loopExp();
    }
    setState(142);
    untilExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FromExpContext ------------------------------------------------------------------

janusParser::FromExpContext::FromExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::ExpressionContext* janusParser::FromExpContext::expression() {
  return getRuleContext<janusParser::ExpressionContext>(0);
}


size_t janusParser::FromExpContext::getRuleIndex() const {
  return janusParser::RuleFromExp;
}

void janusParser::FromExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFromExp(this);
}

void janusParser::FromExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFromExp(this);
}


std::any janusParser::FromExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFromExp(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FromExpContext* janusParser::fromExp() {
  FromExpContext *_localctx = _tracker.createInstance<FromExpContext>(_ctx, getState());
  enterRule(_localctx, 22, janusParser::RuleFromExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(janusParser::T__9);
    setState(145);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UntilExpContext ------------------------------------------------------------------

janusParser::UntilExpContext::UntilExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::ExpressionContext* janusParser::UntilExpContext::expression() {
  return getRuleContext<janusParser::ExpressionContext>(0);
}


size_t janusParser::UntilExpContext::getRuleIndex() const {
  return janusParser::RuleUntilExp;
}

void janusParser::UntilExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUntilExp(this);
}

void janusParser::UntilExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUntilExp(this);
}


std::any janusParser::UntilExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitUntilExp(this);
  else
    return visitor->visitChildren(this);
}

janusParser::UntilExpContext* janusParser::untilExp() {
  UntilExpContext *_localctx = _tracker.createInstance<UntilExpContext>(_ctx, getState());
  enterRule(_localctx, 24, janusParser::RuleUntilExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(janusParser::T__10);
    setState(148);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoExpContext ------------------------------------------------------------------

janusParser::DoExpContext::DoExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::StatementsContext* janusParser::DoExpContext::statements() {
  return getRuleContext<janusParser::StatementsContext>(0);
}


size_t janusParser::DoExpContext::getRuleIndex() const {
  return janusParser::RuleDoExp;
}

void janusParser::DoExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoExp(this);
}

void janusParser::DoExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoExp(this);
}


std::any janusParser::DoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitDoExp(this);
  else
    return visitor->visitChildren(this);
}

janusParser::DoExpContext* janusParser::doExp() {
  DoExpContext *_localctx = _tracker.createInstance<DoExpContext>(_ctx, getState());
  enterRule(_localctx, 26, janusParser::RuleDoExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(janusParser::T__11);
    setState(151);
    statements(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopExpContext ------------------------------------------------------------------

janusParser::LoopExpContext::LoopExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::StatementsContext* janusParser::LoopExpContext::statements() {
  return getRuleContext<janusParser::StatementsContext>(0);
}


size_t janusParser::LoopExpContext::getRuleIndex() const {
  return janusParser::RuleLoopExp;
}

void janusParser::LoopExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopExp(this);
}

void janusParser::LoopExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopExp(this);
}


std::any janusParser::LoopExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitLoopExp(this);
  else
    return visitor->visitChildren(this);
}

janusParser::LoopExpContext* janusParser::loopExp() {
  LoopExpContext *_localctx = _tracker.createInstance<LoopExpContext>(_ctx, getState());
  enterRule(_localctx, 28, janusParser::RuleLoopExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(janusParser::T__12);
    setState(154);
    statements(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

janusParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* janusParser::ExpressionContext::Digit() {
  return getToken(janusParser::Digit, 0);
}

tree::TerminalNode* janusParser::ExpressionContext::TextDigit() {
  return getToken(janusParser::TextDigit, 0);
}

std::vector<janusParser::ExpressionContext *> janusParser::ExpressionContext::expression() {
  return getRuleContexts<janusParser::ExpressionContext>();
}

janusParser::ExpressionContext* janusParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<janusParser::ExpressionContext>(i);
}

janusParser::OperatorContext* janusParser::ExpressionContext::operator_() {
  return getRuleContext<janusParser::OperatorContext>(0);
}


size_t janusParser::ExpressionContext::getRuleIndex() const {
  return janusParser::RuleExpression;
}

void janusParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void janusParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any janusParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


janusParser::ExpressionContext* janusParser::expression() {
   return expression(0);
}

janusParser::ExpressionContext* janusParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  janusParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  janusParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, janusParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case janusParser::Digit: {
        setState(157);
        match(janusParser::Digit);
        break;
      }

      case janusParser::TextDigit: {
        setState(158);
        match(janusParser::TextDigit);
        setState(163);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          setState(159);
          match(janusParser::T__0);
          setState(160);
          expression(0);
          setState(161);
          match(janusParser::T__1);
          break;
        }

        default:
          break;
        }
        break;
      }

      case janusParser::T__4: {
        setState(165);
        match(janusParser::T__4);
        setState(166);
        expression(0);
        setState(167);
        match(janusParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(177);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(171);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(172);
        operator_();
        setState(173);
        expression(3); 
      }
      setState(179);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

janusParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::CallContext* janusParser::FunctionCallContext::call() {
  return getRuleContext<janusParser::CallContext>(0);
}

janusParser::FunctionNameContext* janusParser::FunctionCallContext::functionName() {
  return getRuleContext<janusParser::FunctionNameContext>(0);
}


size_t janusParser::FunctionCallContext::getRuleIndex() const {
  return janusParser::RuleFunctionCall;
}

void janusParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void janusParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any janusParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FunctionCallContext* janusParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 32, janusParser::RuleFunctionCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    call();
    setState(181);
    functionName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkipContext ------------------------------------------------------------------

janusParser::SkipContext::SkipContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::SkipContext::getRuleIndex() const {
  return janusParser::RuleSkip;
}

void janusParser::SkipContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkip(this);
}

void janusParser::SkipContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkip(this);
}


std::any janusParser::SkipContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitSkip(this);
  else
    return visitor->visitChildren(this);
}

janusParser::SkipContext* janusParser::skip() {
  SkipContext *_localctx = _tracker.createInstance<SkipContext>(_ctx, getState());
  enterRule(_localctx, 34, janusParser::RuleSkip);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(janusParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

janusParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::AssignmentOperatorContext::getRuleIndex() const {
  return janusParser::RuleAssignmentOperator;
}

void janusParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void janusParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


std::any janusParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::AssignmentOperatorContext* janusParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 36, janusParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << janusParser::T__14)
      | (1ULL << janusParser::T__15)
      | (1ULL << janusParser::T__16)
      | (1ULL << janusParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOperatorContext ------------------------------------------------------------------

janusParser::RelationalOperatorContext::RelationalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::RelationalOperatorContext::getRuleIndex() const {
  return janusParser::RuleRelationalOperator;
}

void janusParser::RelationalOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalOperator(this);
}

void janusParser::RelationalOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalOperator(this);
}


std::any janusParser::RelationalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitRelationalOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::RelationalOperatorContext* janusParser::relationalOperator() {
  RelationalOperatorContext *_localctx = _tracker.createInstance<RelationalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 38, janusParser::RuleRelationalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << janusParser::T__18)
      | (1ULL << janusParser::T__19)
      | (1ULL << janusParser::T__20)
      | (1ULL << janusParser::T__21)
      | (1ULL << janusParser::T__22)
      | (1ULL << janusParser::T__23))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArithmeticOperatorContext ------------------------------------------------------------------

janusParser::ArithmeticOperatorContext::ArithmeticOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::ArithmeticOperatorContext::getRuleIndex() const {
  return janusParser::RuleArithmeticOperator;
}

void janusParser::ArithmeticOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticOperator(this);
}

void janusParser::ArithmeticOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticOperator(this);
}


std::any janusParser::ArithmeticOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitArithmeticOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::ArithmeticOperatorContext* janusParser::arithmeticOperator() {
  ArithmeticOperatorContext *_localctx = _tracker.createInstance<ArithmeticOperatorContext>(_ctx, getState());
  enterRule(_localctx, 40, janusParser::RuleArithmeticOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << janusParser::T__24)
      | (1ULL << janusParser::T__25)
      | (1ULL << janusParser::T__26)
      | (1ULL << janusParser::T__27)
      | (1ULL << janusParser::T__28))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitwiseOperatorContext ------------------------------------------------------------------

janusParser::BitwiseOperatorContext::BitwiseOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::BitwiseOperatorContext::getRuleIndex() const {
  return janusParser::RuleBitwiseOperator;
}

void janusParser::BitwiseOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseOperator(this);
}

void janusParser::BitwiseOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseOperator(this);
}


std::any janusParser::BitwiseOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitBitwiseOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::BitwiseOperatorContext* janusParser::bitwiseOperator() {
  BitwiseOperatorContext *_localctx = _tracker.createInstance<BitwiseOperatorContext>(_ctx, getState());
  enterRule(_localctx, 42, janusParser::RuleBitwiseOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << janusParser::T__29)
      | (1ULL << janusParser::T__30)
      | (1ULL << janusParser::T__31))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOperatorContext ------------------------------------------------------------------

janusParser::LogicalOperatorContext::LogicalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::LogicalOperatorContext::getRuleIndex() const {
  return janusParser::RuleLogicalOperator;
}

void janusParser::LogicalOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOperator(this);
}

void janusParser::LogicalOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOperator(this);
}


std::any janusParser::LogicalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitLogicalOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::LogicalOperatorContext* janusParser::logicalOperator() {
  LogicalOperatorContext *_localctx = _tracker.createInstance<LogicalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 44, janusParser::RuleLogicalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    _la = _input->LA(1);
    if (!(_la == janusParser::T__32

    || _la == janusParser::T__33)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorContext ------------------------------------------------------------------

janusParser::OperatorContext::OperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

janusParser::ArithmeticOperatorContext* janusParser::OperatorContext::arithmeticOperator() {
  return getRuleContext<janusParser::ArithmeticOperatorContext>(0);
}

janusParser::BitwiseOperatorContext* janusParser::OperatorContext::bitwiseOperator() {
  return getRuleContext<janusParser::BitwiseOperatorContext>(0);
}

janusParser::RelationalOperatorContext* janusParser::OperatorContext::relationalOperator() {
  return getRuleContext<janusParser::RelationalOperatorContext>(0);
}

janusParser::LogicalOperatorContext* janusParser::OperatorContext::logicalOperator() {
  return getRuleContext<janusParser::LogicalOperatorContext>(0);
}


size_t janusParser::OperatorContext::getRuleIndex() const {
  return janusParser::RuleOperator;
}

void janusParser::OperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator(this);
}

void janusParser::OperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator(this);
}


std::any janusParser::OperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitOperator(this);
  else
    return visitor->visitChildren(this);
}

janusParser::OperatorContext* janusParser::operator_() {
  OperatorContext *_localctx = _tracker.createInstance<OperatorContext>(_ctx, getState());
  enterRule(_localctx, 46, janusParser::RuleOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case janusParser::T__24:
      case janusParser::T__25:
      case janusParser::T__26:
      case janusParser::T__27:
      case janusParser::T__28: {
        enterOuterAlt(_localctx, 1);
        setState(195);
        arithmeticOperator();
        break;
      }

      case janusParser::T__29:
      case janusParser::T__30:
      case janusParser::T__31: {
        enterOuterAlt(_localctx, 2);
        setState(196);
        bitwiseOperator();
        break;
      }

      case janusParser::T__18:
      case janusParser::T__19:
      case janusParser::T__20:
      case janusParser::T__21:
      case janusParser::T__22:
      case janusParser::T__23: {
        enterOuterAlt(_localctx, 3);
        setState(197);
        relationalOperator();
        break;
      }

      case janusParser::T__32:
      case janusParser::T__33: {
        enterOuterAlt(_localctx, 4);
        setState(198);
        logicalOperator();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

janusParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t janusParser::CallContext::getRuleIndex() const {
  return janusParser::RuleCall;
}

void janusParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void janusParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}


std::any janusParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

janusParser::CallContext* janusParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 48, janusParser::RuleCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    _la = _input->LA(1);
    if (!(_la == janusParser::T__34

    || _la == janusParser::T__35)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableNameContext ------------------------------------------------------------------

janusParser::VariableNameContext::VariableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* janusParser::VariableNameContext::TextDigit() {
  return getToken(janusParser::TextDigit, 0);
}


size_t janusParser::VariableNameContext::getRuleIndex() const {
  return janusParser::RuleVariableName;
}

void janusParser::VariableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableName(this);
}

void janusParser::VariableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableName(this);
}


std::any janusParser::VariableNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitVariableName(this);
  else
    return visitor->visitChildren(this);
}

janusParser::VariableNameContext* janusParser::variableName() {
  VariableNameContext *_localctx = _tracker.createInstance<VariableNameContext>(_ctx, getState());
  enterRule(_localctx, 50, janusParser::RuleVariableName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(janusParser::TextDigit);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

janusParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* janusParser::FunctionNameContext::TextDigit() {
  return getToken(janusParser::TextDigit, 0);
}


size_t janusParser::FunctionNameContext::getRuleIndex() const {
  return janusParser::RuleFunctionName;
}

void janusParser::FunctionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionName(this);
}

void janusParser::FunctionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<janusListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionName(this);
}


std::any janusParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<janusVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

janusParser::FunctionNameContext* janusParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 52, janusParser::RuleFunctionName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(janusParser::TextDigit);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool janusParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return variablesSempred(antlrcpp::downCast<VariablesContext *>(context), predicateIndex);
    case 4: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 15: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool janusParser::variablesSempred(VariablesContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool janusParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool janusParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void janusParser::initialize() {
  std::call_once(janusParserOnceFlag, janusParserInitialize);
}
