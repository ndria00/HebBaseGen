
// Generated from ASPCore2Facts.g4 by ANTLR 4.10


#include "ASPCore2FactsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ASPCore2FactsLexerStaticData final {
  ASPCore2FactsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ASPCore2FactsLexerStaticData(const ASPCore2FactsLexerStaticData&) = delete;
  ASPCore2FactsLexerStaticData(ASPCore2FactsLexerStaticData&&) = delete;
  ASPCore2FactsLexerStaticData& operator=(const ASPCore2FactsLexerStaticData&) = delete;
  ASPCore2FactsLexerStaticData& operator=(ASPCore2FactsLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag aspcore2factslexerLexerOnceFlag;
ASPCore2FactsLexerStaticData *aspcore2factslexerLexerStaticData = nullptr;

void aspcore2factslexerLexerInitialize() {
  assert(aspcore2factslexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ASPCore2FactsLexerStaticData>(
    std::vector<std::string>{
      "SYMBOLIC_CONSTANT", "STRING", "NUMBER", "WS", "DOT", "DDOT", "COMMA", 
      "HEAD_SEPARATOR", "COLON", "CONS", "PARAM_OPEN", "PARAM_CLOSE", "ANON_VAR", 
      "EMPTY_COMMENT", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,15,98,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,5,0,34,8,0,10,0,12,0,37,9,0,1,1,1,1,1,1,1,1,5,1,43,8,1,10,
  	1,12,1,46,9,1,1,1,1,1,1,2,4,2,51,8,2,11,2,12,2,52,1,3,4,3,56,8,3,11,3,
  	12,3,57,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,
  	9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,
  	14,5,14,90,8,14,10,14,12,14,93,9,14,1,14,1,14,1,14,1,14,2,44,91,0,15,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,1,0,5,1,0,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,9,10,
  	32,32,2,0,10,10,64,64,103,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,
  	0,0,0,1,31,1,0,0,0,3,38,1,0,0,0,5,50,1,0,0,0,7,55,1,0,0,0,9,61,1,0,0,
  	0,11,63,1,0,0,0,13,66,1,0,0,0,15,68,1,0,0,0,17,70,1,0,0,0,19,72,1,0,0,
  	0,21,75,1,0,0,0,23,77,1,0,0,0,25,79,1,0,0,0,27,81,1,0,0,0,29,86,1,0,0,
  	0,31,35,7,0,0,0,32,34,7,1,0,0,33,32,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,
  	0,35,36,1,0,0,0,36,2,1,0,0,0,37,35,1,0,0,0,38,44,5,34,0,0,39,40,5,92,
  	0,0,40,43,5,34,0,0,41,43,9,0,0,0,42,39,1,0,0,0,42,41,1,0,0,0,43,46,1,
  	0,0,0,44,45,1,0,0,0,44,42,1,0,0,0,45,47,1,0,0,0,46,44,1,0,0,0,47,48,5,
  	34,0,0,48,4,1,0,0,0,49,51,7,2,0,0,50,49,1,0,0,0,51,52,1,0,0,0,52,50,1,
  	0,0,0,52,53,1,0,0,0,53,6,1,0,0,0,54,56,7,3,0,0,55,54,1,0,0,0,56,57,1,
  	0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,0,59,60,6,3,0,0,60,8,1,
  	0,0,0,61,62,5,46,0,0,62,10,1,0,0,0,63,64,5,46,0,0,64,65,5,46,0,0,65,12,
  	1,0,0,0,66,67,5,44,0,0,67,14,1,0,0,0,68,69,5,124,0,0,69,16,1,0,0,0,70,
  	71,5,58,0,0,71,18,1,0,0,0,72,73,5,58,0,0,73,74,5,45,0,0,74,20,1,0,0,0,
  	75,76,5,40,0,0,76,22,1,0,0,0,77,78,5,41,0,0,78,24,1,0,0,0,79,80,5,95,
  	0,0,80,26,1,0,0,0,81,82,5,37,0,0,82,83,5,10,0,0,83,84,1,0,0,0,84,85,6,
  	13,0,0,85,28,1,0,0,0,86,87,5,37,0,0,87,91,8,4,0,0,88,90,9,0,0,0,89,88,
  	1,0,0,0,90,93,1,0,0,0,91,92,1,0,0,0,91,89,1,0,0,0,92,94,1,0,0,0,93,91,
  	1,0,0,0,94,95,5,10,0,0,95,96,1,0,0,0,96,97,6,14,0,0,97,30,1,0,0,0,7,0,
  	35,42,44,52,57,91,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aspcore2factslexerLexerStaticData = staticData.release();
}

}

ASPCore2FactsLexer::ASPCore2FactsLexer(CharStream *input) : Lexer(input) {
  ASPCore2FactsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *aspcore2factslexerLexerStaticData->atn, aspcore2factslexerLexerStaticData->decisionToDFA, aspcore2factslexerLexerStaticData->sharedContextCache);
}

ASPCore2FactsLexer::~ASPCore2FactsLexer() {
  delete _interpreter;
}

std::string ASPCore2FactsLexer::getGrammarFileName() const {
  return "ASPCore2Facts.g4";
}

const std::vector<std::string>& ASPCore2FactsLexer::getRuleNames() const {
  return aspcore2factslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ASPCore2FactsLexer::getChannelNames() const {
  return aspcore2factslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ASPCore2FactsLexer::getModeNames() const {
  return aspcore2factslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ASPCore2FactsLexer::getVocabulary() const {
  return aspcore2factslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ASPCore2FactsLexer::getSerializedATN() const {
  return aspcore2factslexerLexerStaticData->serializedATN;
}

const atn::ATN& ASPCore2FactsLexer::getATN() const {
  return *aspcore2factslexerLexerStaticData->atn;
}




void ASPCore2FactsLexer::initialize() {
  std::call_once(aspcore2factslexerLexerOnceFlag, aspcore2factslexerLexerInitialize);
}
