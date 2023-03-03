
// Generated from ASPCore2Facts.g4 by ANTLR 4.10


#include "ASPCore2FactsListener.h"

#include "ASPCore2FactsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ASPCore2FactsParserStaticData final {
  ASPCore2FactsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ASPCore2FactsParserStaticData(const ASPCore2FactsParserStaticData&) = delete;
  ASPCore2FactsParserStaticData(ASPCore2FactsParserStaticData&&) = delete;
  ASPCore2FactsParserStaticData& operator=(const ASPCore2FactsParserStaticData&) = delete;
  ASPCore2FactsParserStaticData& operator=(ASPCore2FactsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag aspcore2factsParserOnceFlag;
ASPCore2FactsParserStaticData *aspcore2factsParserStaticData = nullptr;

void aspcore2factsParserInitialize() {
  assert(aspcore2factsParserStaticData == nullptr);
  auto staticData = std::make_unique<ASPCore2FactsParserStaticData>(
    std::vector<std::string>{
      "instance", "fact", "head", "disjunction", "classic_literal", "atom", 
      "terms", "term_", "term", "identifier"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'.'", "'..'", "','", "'|'", "':'", "':-'", "'('", 
      "')'", "'_'"
    },
    std::vector<std::string>{
      "", "SYMBOLIC_CONSTANT", "STRING", "NUMBER", "WS", "DOT", "DDOT", 
      "COMMA", "HEAD_SEPARATOR", "COLON", "CONS", "PARAM_OPEN", "PARAM_CLOSE", 
      "ANON_VAR", "EMPTY_COMMENT", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,15,69,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,1,1,1,1,1,1,2,1,
  	2,1,3,1,3,1,3,1,3,1,3,3,3,37,8,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,
  	47,8,5,1,6,1,6,1,6,1,6,1,6,3,6,54,8,6,1,7,1,7,1,7,1,7,3,7,60,8,7,1,8,
  	1,8,1,8,3,8,65,8,8,1,9,1,9,1,9,0,0,10,0,2,4,6,8,10,12,14,16,18,0,1,1,
  	0,1,2,65,0,23,1,0,0,0,2,26,1,0,0,0,4,29,1,0,0,0,6,36,1,0,0,0,8,38,1,0,
  	0,0,10,46,1,0,0,0,12,53,1,0,0,0,14,59,1,0,0,0,16,64,1,0,0,0,18,66,1,0,
  	0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,1,0,0,0,23,24,1,0,
  	0,0,24,1,1,0,0,0,25,23,1,0,0,0,26,27,3,4,2,0,27,28,5,5,0,0,28,3,1,0,0,
  	0,29,30,3,6,3,0,30,5,1,0,0,0,31,37,3,8,4,0,32,33,3,8,4,0,33,34,5,8,0,
  	0,34,35,3,6,3,0,35,37,1,0,0,0,36,31,1,0,0,0,36,32,1,0,0,0,37,7,1,0,0,
  	0,38,39,3,10,5,0,39,9,1,0,0,0,40,47,3,18,9,0,41,42,3,18,9,0,42,43,5,11,
  	0,0,43,44,3,12,6,0,44,45,5,12,0,0,45,47,1,0,0,0,46,40,1,0,0,0,46,41,1,
  	0,0,0,47,11,1,0,0,0,48,54,3,16,8,0,49,50,3,16,8,0,50,51,5,7,0,0,51,52,
  	3,12,6,0,52,54,1,0,0,0,53,48,1,0,0,0,53,49,1,0,0,0,54,13,1,0,0,0,55,60,
  	5,13,0,0,56,57,5,3,0,0,57,58,5,6,0,0,58,60,5,3,0,0,59,55,1,0,0,0,59,56,
  	1,0,0,0,60,15,1,0,0,0,61,65,3,14,7,0,62,65,5,3,0,0,63,65,3,18,9,0,64,
  	61,1,0,0,0,64,62,1,0,0,0,64,63,1,0,0,0,65,17,1,0,0,0,66,67,7,0,0,0,67,
  	19,1,0,0,0,6,23,36,46,53,59,64
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aspcore2factsParserStaticData = staticData.release();
}

}

ASPCore2FactsParser::ASPCore2FactsParser(TokenStream *input) : ASPCore2FactsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ASPCore2FactsParser::ASPCore2FactsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ASPCore2FactsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *aspcore2factsParserStaticData->atn, aspcore2factsParserStaticData->decisionToDFA, aspcore2factsParserStaticData->sharedContextCache, options);
}

ASPCore2FactsParser::~ASPCore2FactsParser() {
  delete _interpreter;
}

const atn::ATN& ASPCore2FactsParser::getATN() const {
  return *aspcore2factsParserStaticData->atn;
}

std::string ASPCore2FactsParser::getGrammarFileName() const {
  return "ASPCore2Facts.g4";
}

const std::vector<std::string>& ASPCore2FactsParser::getRuleNames() const {
  return aspcore2factsParserStaticData->ruleNames;
}

const dfa::Vocabulary& ASPCore2FactsParser::getVocabulary() const {
  return aspcore2factsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ASPCore2FactsParser::getSerializedATN() const {
  return aspcore2factsParserStaticData->serializedATN;
}


//----------------- InstanceContext ------------------------------------------------------------------

ASPCore2FactsParser::InstanceContext::InstanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ASPCore2FactsParser::FactContext *> ASPCore2FactsParser::InstanceContext::fact() {
  return getRuleContexts<ASPCore2FactsParser::FactContext>();
}

ASPCore2FactsParser::FactContext* ASPCore2FactsParser::InstanceContext::fact(size_t i) {
  return getRuleContext<ASPCore2FactsParser::FactContext>(i);
}


size_t ASPCore2FactsParser::InstanceContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleInstance;
}

void ASPCore2FactsParser::InstanceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstance(this);
}

void ASPCore2FactsParser::InstanceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstance(this);
}

ASPCore2FactsParser::InstanceContext* ASPCore2FactsParser::instance() {
  InstanceContext *_localctx = _tracker.createInstance<InstanceContext>(_ctx, getState());
  enterRule(_localctx, 0, ASPCore2FactsParser::RuleInstance);
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
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ASPCore2FactsParser::SYMBOLIC_CONSTANT

    || _la == ASPCore2FactsParser::STRING) {
      setState(20);
      fact();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactContext ------------------------------------------------------------------

ASPCore2FactsParser::FactContext::FactContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::HeadContext* ASPCore2FactsParser::FactContext::head() {
  return getRuleContext<ASPCore2FactsParser::HeadContext>(0);
}

tree::TerminalNode* ASPCore2FactsParser::FactContext::DOT() {
  return getToken(ASPCore2FactsParser::DOT, 0);
}


size_t ASPCore2FactsParser::FactContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleFact;
}

void ASPCore2FactsParser::FactContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFact(this);
}

void ASPCore2FactsParser::FactContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFact(this);
}

ASPCore2FactsParser::FactContext* ASPCore2FactsParser::fact() {
  FactContext *_localctx = _tracker.createInstance<FactContext>(_ctx, getState());
  enterRule(_localctx, 2, ASPCore2FactsParser::RuleFact);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    head();
    setState(27);
    match(ASPCore2FactsParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeadContext ------------------------------------------------------------------

ASPCore2FactsParser::HeadContext::HeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::DisjunctionContext* ASPCore2FactsParser::HeadContext::disjunction() {
  return getRuleContext<ASPCore2FactsParser::DisjunctionContext>(0);
}


size_t ASPCore2FactsParser::HeadContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleHead;
}

void ASPCore2FactsParser::HeadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHead(this);
}

void ASPCore2FactsParser::HeadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHead(this);
}

ASPCore2FactsParser::HeadContext* ASPCore2FactsParser::head() {
  HeadContext *_localctx = _tracker.createInstance<HeadContext>(_ctx, getState());
  enterRule(_localctx, 4, ASPCore2FactsParser::RuleHead);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    disjunction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DisjunctionContext ------------------------------------------------------------------

ASPCore2FactsParser::DisjunctionContext::DisjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::Classic_literalContext* ASPCore2FactsParser::DisjunctionContext::classic_literal() {
  return getRuleContext<ASPCore2FactsParser::Classic_literalContext>(0);
}

tree::TerminalNode* ASPCore2FactsParser::DisjunctionContext::HEAD_SEPARATOR() {
  return getToken(ASPCore2FactsParser::HEAD_SEPARATOR, 0);
}

ASPCore2FactsParser::DisjunctionContext* ASPCore2FactsParser::DisjunctionContext::disjunction() {
  return getRuleContext<ASPCore2FactsParser::DisjunctionContext>(0);
}


size_t ASPCore2FactsParser::DisjunctionContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleDisjunction;
}

void ASPCore2FactsParser::DisjunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisjunction(this);
}

void ASPCore2FactsParser::DisjunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisjunction(this);
}

ASPCore2FactsParser::DisjunctionContext* ASPCore2FactsParser::disjunction() {
  DisjunctionContext *_localctx = _tracker.createInstance<DisjunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, ASPCore2FactsParser::RuleDisjunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(31);
      classic_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(32);
      classic_literal();
      setState(33);
      match(ASPCore2FactsParser::HEAD_SEPARATOR);
      setState(34);
      disjunction();
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

//----------------- Classic_literalContext ------------------------------------------------------------------

ASPCore2FactsParser::Classic_literalContext::Classic_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::AtomContext* ASPCore2FactsParser::Classic_literalContext::atom() {
  return getRuleContext<ASPCore2FactsParser::AtomContext>(0);
}


size_t ASPCore2FactsParser::Classic_literalContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleClassic_literal;
}

void ASPCore2FactsParser::Classic_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassic_literal(this);
}

void ASPCore2FactsParser::Classic_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassic_literal(this);
}

ASPCore2FactsParser::Classic_literalContext* ASPCore2FactsParser::classic_literal() {
  Classic_literalContext *_localctx = _tracker.createInstance<Classic_literalContext>(_ctx, getState());
  enterRule(_localctx, 8, ASPCore2FactsParser::RuleClassic_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

ASPCore2FactsParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::IdentifierContext* ASPCore2FactsParser::AtomContext::identifier() {
  return getRuleContext<ASPCore2FactsParser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2FactsParser::AtomContext::PARAM_OPEN() {
  return getToken(ASPCore2FactsParser::PARAM_OPEN, 0);
}

ASPCore2FactsParser::TermsContext* ASPCore2FactsParser::AtomContext::terms() {
  return getRuleContext<ASPCore2FactsParser::TermsContext>(0);
}

tree::TerminalNode* ASPCore2FactsParser::AtomContext::PARAM_CLOSE() {
  return getToken(ASPCore2FactsParser::PARAM_CLOSE, 0);
}


size_t ASPCore2FactsParser::AtomContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleAtom;
}

void ASPCore2FactsParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void ASPCore2FactsParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

ASPCore2FactsParser::AtomContext* ASPCore2FactsParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 10, ASPCore2FactsParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(40);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(41);
      identifier();
      setState(42);
      match(ASPCore2FactsParser::PARAM_OPEN);
      setState(43);
      terms();
      setState(44);
      match(ASPCore2FactsParser::PARAM_CLOSE);
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

//----------------- TermsContext ------------------------------------------------------------------

ASPCore2FactsParser::TermsContext::TermsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::TermContext* ASPCore2FactsParser::TermsContext::term() {
  return getRuleContext<ASPCore2FactsParser::TermContext>(0);
}

tree::TerminalNode* ASPCore2FactsParser::TermsContext::COMMA() {
  return getToken(ASPCore2FactsParser::COMMA, 0);
}

ASPCore2FactsParser::TermsContext* ASPCore2FactsParser::TermsContext::terms() {
  return getRuleContext<ASPCore2FactsParser::TermsContext>(0);
}


size_t ASPCore2FactsParser::TermsContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleTerms;
}

void ASPCore2FactsParser::TermsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerms(this);
}

void ASPCore2FactsParser::TermsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerms(this);
}

ASPCore2FactsParser::TermsContext* ASPCore2FactsParser::terms() {
  TermsContext *_localctx = _tracker.createInstance<TermsContext>(_ctx, getState());
  enterRule(_localctx, 12, ASPCore2FactsParser::RuleTerms);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(49);
      term();
      setState(50);
      match(ASPCore2FactsParser::COMMA);
      setState(51);
      terms();
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

//----------------- Term_Context ------------------------------------------------------------------

ASPCore2FactsParser::Term_Context::Term_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2FactsParser::Term_Context::ANON_VAR() {
  return getToken(ASPCore2FactsParser::ANON_VAR, 0);
}

std::vector<tree::TerminalNode *> ASPCore2FactsParser::Term_Context::NUMBER() {
  return getTokens(ASPCore2FactsParser::NUMBER);
}

tree::TerminalNode* ASPCore2FactsParser::Term_Context::NUMBER(size_t i) {
  return getToken(ASPCore2FactsParser::NUMBER, i);
}

tree::TerminalNode* ASPCore2FactsParser::Term_Context::DDOT() {
  return getToken(ASPCore2FactsParser::DDOT, 0);
}


size_t ASPCore2FactsParser::Term_Context::getRuleIndex() const {
  return ASPCore2FactsParser::RuleTerm_;
}

void ASPCore2FactsParser::Term_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm_(this);
}

void ASPCore2FactsParser::Term_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm_(this);
}

ASPCore2FactsParser::Term_Context* ASPCore2FactsParser::term_() {
  Term_Context *_localctx = _tracker.createInstance<Term_Context>(_ctx, getState());
  enterRule(_localctx, 14, ASPCore2FactsParser::RuleTerm_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2FactsParser::ANON_VAR: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        match(ASPCore2FactsParser::ANON_VAR);
        break;
      }

      case ASPCore2FactsParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(56);
        match(ASPCore2FactsParser::NUMBER);
        setState(57);
        match(ASPCore2FactsParser::DDOT);
        setState(58);
        match(ASPCore2FactsParser::NUMBER);
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

//----------------- TermContext ------------------------------------------------------------------

ASPCore2FactsParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2FactsParser::Term_Context* ASPCore2FactsParser::TermContext::term_() {
  return getRuleContext<ASPCore2FactsParser::Term_Context>(0);
}

tree::TerminalNode* ASPCore2FactsParser::TermContext::NUMBER() {
  return getToken(ASPCore2FactsParser::NUMBER, 0);
}

ASPCore2FactsParser::IdentifierContext* ASPCore2FactsParser::TermContext::identifier() {
  return getRuleContext<ASPCore2FactsParser::IdentifierContext>(0);
}


size_t ASPCore2FactsParser::TermContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleTerm;
}

void ASPCore2FactsParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void ASPCore2FactsParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

ASPCore2FactsParser::TermContext* ASPCore2FactsParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 16, ASPCore2FactsParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      term_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(62);
      match(ASPCore2FactsParser::NUMBER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(63);
      identifier();
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

//----------------- IdentifierContext ------------------------------------------------------------------

ASPCore2FactsParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2FactsParser::IdentifierContext::SYMBOLIC_CONSTANT() {
  return getToken(ASPCore2FactsParser::SYMBOLIC_CONSTANT, 0);
}

tree::TerminalNode* ASPCore2FactsParser::IdentifierContext::STRING() {
  return getToken(ASPCore2FactsParser::STRING, 0);
}


size_t ASPCore2FactsParser::IdentifierContext::getRuleIndex() const {
  return ASPCore2FactsParser::RuleIdentifier;
}

void ASPCore2FactsParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void ASPCore2FactsParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2FactsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

ASPCore2FactsParser::IdentifierContext* ASPCore2FactsParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 18, ASPCore2FactsParser::RuleIdentifier);
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
    setState(66);
    _la = _input->LA(1);
    if (!(_la == ASPCore2FactsParser::SYMBOLIC_CONSTANT

    || _la == ASPCore2FactsParser::STRING)) {
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

void ASPCore2FactsParser::initialize() {
  std::call_once(aspcore2factsParserOnceFlag, aspcore2factsParserInitialize);
}
