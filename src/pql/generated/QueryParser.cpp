
// Generated from ./Query.g4 by ANTLR 4.13.2


#include "QueryVisitor.h"

#include "QueryParser.h"


using namespace antlrcpp;
using namespace pt::PQL;

using namespace antlr4;

namespace {

struct QueryParserStaticData final {
  QueryParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  QueryParserStaticData(const QueryParserStaticData&) = delete;
  QueryParserStaticData(QueryParserStaticData&&) = delete;
  QueryParserStaticData& operator=(const QueryParserStaticData&) = delete;
  QueryParserStaticData& operator=(QueryParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag queryParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<QueryParserStaticData> queryParserStaticData = nullptr;

void queryParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (queryParserStaticData != nullptr) {
    return;
  }
#else
  assert(queryParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<QueryParserStaticData>(
    std::vector<std::string>{
      "filter", "expression", "reference", "predicate", "oper", "value"
    },
    std::vector<std::string>{
      "", "'and'", "'or'", "'='", "'~'", "'>'", "'>='", "'<'", "'<='"
    },
    std::vector<std::string>{
      "", "AND", "OR", "EQ", "CONTAINS", "GT", "GTE", "LT", "LTE", "WS", 
      "INT", "FLOAT", "STRING", "UNIT_SIZE", "UNIT_SPEED", "ID"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,15,68,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,24,8,1,10,1,12,1,27,9,1,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,3,5,39,8,5,1,5,3,5,42,8,5,1,5,1,5,3,5,46,
  	8,5,1,5,3,5,49,8,5,1,5,1,5,3,5,53,8,5,1,5,3,5,56,8,5,1,5,1,5,3,5,60,8,
  	5,1,5,3,5,63,8,5,1,5,3,5,66,8,5,1,5,0,1,2,6,0,2,4,6,8,10,0,1,1,0,3,8,
  	75,0,12,1,0,0,0,2,14,1,0,0,0,4,28,1,0,0,0,6,30,1,0,0,0,8,34,1,0,0,0,10,
  	65,1,0,0,0,12,13,3,2,1,0,13,1,1,0,0,0,14,15,6,1,-1,0,15,16,3,6,3,0,16,
  	25,1,0,0,0,17,18,10,3,0,0,18,19,5,1,0,0,19,24,3,2,1,4,20,21,10,2,0,0,
  	21,22,5,2,0,0,22,24,3,2,1,3,23,17,1,0,0,0,23,20,1,0,0,0,24,27,1,0,0,0,
  	25,23,1,0,0,0,25,26,1,0,0,0,26,3,1,0,0,0,27,25,1,0,0,0,28,29,5,15,0,0,
  	29,5,1,0,0,0,30,31,3,4,2,0,31,32,3,8,4,0,32,33,3,10,5,0,33,7,1,0,0,0,
  	34,35,7,0,0,0,35,9,1,0,0,0,36,38,5,10,0,0,37,39,5,9,0,0,38,37,1,0,0,0,
  	38,39,1,0,0,0,39,41,1,0,0,0,40,42,5,13,0,0,41,40,1,0,0,0,41,42,1,0,0,
  	0,42,66,1,0,0,0,43,45,5,10,0,0,44,46,5,9,0,0,45,44,1,0,0,0,45,46,1,0,
  	0,0,46,48,1,0,0,0,47,49,5,14,0,0,48,47,1,0,0,0,48,49,1,0,0,0,49,66,1,
  	0,0,0,50,52,5,11,0,0,51,53,5,9,0,0,52,51,1,0,0,0,52,53,1,0,0,0,53,55,
  	1,0,0,0,54,56,5,13,0,0,55,54,1,0,0,0,55,56,1,0,0,0,56,66,1,0,0,0,57,59,
  	5,11,0,0,58,60,5,9,0,0,59,58,1,0,0,0,59,60,1,0,0,0,60,62,1,0,0,0,61,63,
  	5,14,0,0,62,61,1,0,0,0,62,63,1,0,0,0,63,66,1,0,0,0,64,66,5,12,0,0,65,
  	36,1,0,0,0,65,43,1,0,0,0,65,50,1,0,0,0,65,57,1,0,0,0,65,64,1,0,0,0,66,
  	11,1,0,0,0,11,23,25,38,41,45,48,52,55,59,62,65
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  queryParserStaticData = std::move(staticData);
}

}

QueryParser::QueryParser(TokenStream *input) : QueryParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

QueryParser::QueryParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  QueryParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *queryParserStaticData->atn, queryParserStaticData->decisionToDFA, queryParserStaticData->sharedContextCache, options);
}

QueryParser::~QueryParser() {
  delete _interpreter;
}

const atn::ATN& QueryParser::getATN() const {
  return *queryParserStaticData->atn;
}

std::string QueryParser::getGrammarFileName() const {
  return "Query.g4";
}

const std::vector<std::string>& QueryParser::getRuleNames() const {
  return queryParserStaticData->ruleNames;
}

const dfa::Vocabulary& QueryParser::getVocabulary() const {
  return queryParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView QueryParser::getSerializedATN() const {
  return queryParserStaticData->serializedATN;
}


//----------------- FilterContext ------------------------------------------------------------------

QueryParser::FilterContext::FilterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

QueryParser::ExpressionContext* QueryParser::FilterContext::expression() {
  return getRuleContext<QueryParser::ExpressionContext>(0);
}


size_t QueryParser::FilterContext::getRuleIndex() const {
  return QueryParser::RuleFilter;
}


std::any QueryParser::FilterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitFilter(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::FilterContext* QueryParser::filter() {
  FilterContext *_localctx = _tracker.createInstance<FilterContext>(_ctx, getState());
  enterRule(_localctx, 0, QueryParser::RuleFilter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

QueryParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t QueryParser::ExpressionContext::getRuleIndex() const {
  return QueryParser::RuleExpression;
}

void QueryParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExpressionContext ------------------------------------------------------------------

std::vector<QueryParser::ExpressionContext *> QueryParser::AndExpressionContext::expression() {
  return getRuleContexts<QueryParser::ExpressionContext>();
}

QueryParser::ExpressionContext* QueryParser::AndExpressionContext::expression(size_t i) {
  return getRuleContext<QueryParser::ExpressionContext>(i);
}

tree::TerminalNode* QueryParser::AndExpressionContext::AND() {
  return getToken(QueryParser::AND, 0);
}

QueryParser::AndExpressionContext::AndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any QueryParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PredicateExpressionContext ------------------------------------------------------------------

QueryParser::PredicateContext* QueryParser::PredicateExpressionContext::predicate() {
  return getRuleContext<QueryParser::PredicateContext>(0);
}

QueryParser::PredicateExpressionContext::PredicateExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any QueryParser::PredicateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitPredicateExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExpressionContext ------------------------------------------------------------------

std::vector<QueryParser::ExpressionContext *> QueryParser::OrExpressionContext::expression() {
  return getRuleContexts<QueryParser::ExpressionContext>();
}

QueryParser::ExpressionContext* QueryParser::OrExpressionContext::expression(size_t i) {
  return getRuleContext<QueryParser::ExpressionContext>(i);
}

tree::TerminalNode* QueryParser::OrExpressionContext::OR() {
  return getToken(QueryParser::OR, 0);
}

QueryParser::OrExpressionContext::OrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any QueryParser::OrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitOrExpression(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::ExpressionContext* QueryParser::expression() {
   return expression(0);
}

QueryParser::ExpressionContext* QueryParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  QueryParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  QueryParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, QueryParser::RuleExpression, precedence);

    

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
    _localctx = _tracker.createInstance<PredicateExpressionContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(15);
    predicate();
    _ctx->stop = _input->LT(-1);
    setState(25);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(23);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(17);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(18);
          match(QueryParser::AND);
          setState(19);
          expression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<OrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(20);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(21);
          match(QueryParser::OR);
          setState(22);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(27);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ReferenceContext ------------------------------------------------------------------

QueryParser::ReferenceContext::ReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::ReferenceContext::ID() {
  return getToken(QueryParser::ID, 0);
}


size_t QueryParser::ReferenceContext::getRuleIndex() const {
  return QueryParser::RuleReference;
}


std::any QueryParser::ReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitReference(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::ReferenceContext* QueryParser::reference() {
  ReferenceContext *_localctx = _tracker.createInstance<ReferenceContext>(_ctx, getState());
  enterRule(_localctx, 4, QueryParser::RuleReference);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(QueryParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicateContext ------------------------------------------------------------------

QueryParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t QueryParser::PredicateContext::getRuleIndex() const {
  return QueryParser::RulePredicate;
}

void QueryParser::PredicateContext::copyFrom(PredicateContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OperatorPredicateContext ------------------------------------------------------------------

QueryParser::ReferenceContext* QueryParser::OperatorPredicateContext::reference() {
  return getRuleContext<QueryParser::ReferenceContext>(0);
}

QueryParser::OperContext* QueryParser::OperatorPredicateContext::oper() {
  return getRuleContext<QueryParser::OperContext>(0);
}

QueryParser::ValueContext* QueryParser::OperatorPredicateContext::value() {
  return getRuleContext<QueryParser::ValueContext>(0);
}

QueryParser::OperatorPredicateContext::OperatorPredicateContext(PredicateContext *ctx) { copyFrom(ctx); }


std::any QueryParser::OperatorPredicateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitOperatorPredicate(this);
  else
    return visitor->visitChildren(this);
}
QueryParser::PredicateContext* QueryParser::predicate() {
  PredicateContext *_localctx = _tracker.createInstance<PredicateContext>(_ctx, getState());
  enterRule(_localctx, 6, QueryParser::RulePredicate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<QueryParser::OperatorPredicateContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(30);
    reference();
    setState(31);
    oper();
    setState(32);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperContext ------------------------------------------------------------------

QueryParser::OperContext::OperContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::OperContext::EQ() {
  return getToken(QueryParser::EQ, 0);
}

tree::TerminalNode* QueryParser::OperContext::CONTAINS() {
  return getToken(QueryParser::CONTAINS, 0);
}

tree::TerminalNode* QueryParser::OperContext::GT() {
  return getToken(QueryParser::GT, 0);
}

tree::TerminalNode* QueryParser::OperContext::GTE() {
  return getToken(QueryParser::GTE, 0);
}

tree::TerminalNode* QueryParser::OperContext::LT() {
  return getToken(QueryParser::LT, 0);
}

tree::TerminalNode* QueryParser::OperContext::LTE() {
  return getToken(QueryParser::LTE, 0);
}


size_t QueryParser::OperContext::getRuleIndex() const {
  return QueryParser::RuleOper;
}


std::any QueryParser::OperContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitOper(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::OperContext* QueryParser::oper() {
  OperContext *_localctx = _tracker.createInstance<OperContext>(_ctx, getState());
  enterRule(_localctx, 8, QueryParser::RuleOper);
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
    setState(34);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 504) != 0))) {
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

//----------------- ValueContext ------------------------------------------------------------------

QueryParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* QueryParser::ValueContext::INT() {
  return getToken(QueryParser::INT, 0);
}

tree::TerminalNode* QueryParser::ValueContext::WS() {
  return getToken(QueryParser::WS, 0);
}

tree::TerminalNode* QueryParser::ValueContext::UNIT_SIZE() {
  return getToken(QueryParser::UNIT_SIZE, 0);
}

tree::TerminalNode* QueryParser::ValueContext::UNIT_SPEED() {
  return getToken(QueryParser::UNIT_SPEED, 0);
}

tree::TerminalNode* QueryParser::ValueContext::FLOAT() {
  return getToken(QueryParser::FLOAT, 0);
}

tree::TerminalNode* QueryParser::ValueContext::STRING() {
  return getToken(QueryParser::STRING, 0);
}


size_t QueryParser::ValueContext::getRuleIndex() const {
  return QueryParser::RuleValue;
}


std::any QueryParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<QueryVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

QueryParser::ValueContext* QueryParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 10, QueryParser::RuleValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      match(QueryParser::INT);
      setState(38);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(37);
        match(QueryParser::WS);
        break;
      }

      default:
        break;
      }
      setState(41);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(40);
        match(QueryParser::UNIT_SIZE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(43);
      match(QueryParser::INT);
      setState(45);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(44);
        match(QueryParser::WS);
        break;
      }

      default:
        break;
      }
      setState(48);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(47);
        match(QueryParser::UNIT_SPEED);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(50);
      match(QueryParser::FLOAT);
      setState(52);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(51);
        match(QueryParser::WS);
        break;
      }

      default:
        break;
      }
      setState(55);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(54);
        match(QueryParser::UNIT_SIZE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(57);
      match(QueryParser::FLOAT);
      setState(59);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(58);
        match(QueryParser::WS);
        break;
      }

      default:
        break;
      }
      setState(62);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(61);
        match(QueryParser::UNIT_SPEED);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(64);
      match(QueryParser::STRING);
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

bool QueryParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool QueryParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void QueryParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  queryParserInitialize();
#else
  ::antlr4::internal::call_once(queryParserOnceFlag, queryParserInitialize);
#endif
}
