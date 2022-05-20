
// Generated from ../ASPCore2.g4 by ANTLR 4.10.1


#include "ASPCore2Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ASPCore2LexerStaticData final {
  ASPCore2LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ASPCore2LexerStaticData(const ASPCore2LexerStaticData&) = delete;
  ASPCore2LexerStaticData(ASPCore2LexerStaticData&&) = delete;
  ASPCore2LexerStaticData& operator=(const ASPCore2LexerStaticData&) = delete;
  ASPCore2LexerStaticData& operator=(ASPCore2LexerStaticData&&) = delete;

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

std::once_flag aspcore2lexerLexerOnceFlag;
ASPCore2LexerStaticData *aspcore2lexerLexerStaticData = nullptr;

void aspcore2lexerLexerInitialize() {
  assert(aspcore2lexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ASPCore2LexerStaticData>(
    std::vector<std::string>{
      "NAF", "COMMENT_EMPTY", "COMMENT", "SYMBOLIC_CONSTANT", "VARIABLE", 
      "STRING", "NUMBER", "WS", "DOT", "DDOT", "COMMA", "HEAD_SEPARATOR", 
      "SEMICOLON", "COLON", "AT", "CONS", "WCONS", "PLUS", "DASH", "TIMES", 
      "SLASH", "BACK_SLASH", "PARAM_OPEN", "PARAM_CLOSE", "SQUARE_OPEN", 
      "SQUARE_CLOSED", "CURLY_OPEN", "CURLY_CLOSED", "QUERY_MARK", "ANON_VAR", 
      "EQUAL", "UNEQUAL", "LESS", "GREATER", "LESS_OR_EQ", "GREATER_OR_EQ", 
      "AMPERSAND", "EXISTS", "AGGR_COUNT", "AGGR_MAX", "AGGR_MIN", "AGGR_SUM"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'not'", "'%\\n'", "", "", "", "", "", "", "'.'", "'..'", "','", 
      "'|'", "';'", "':'", "'@'", "':-'", "':~'", "'+'", "'-'", "'*'", "'/'", 
      "'\\'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'\\u003F'", "'_'", 
      "", "", "'<'", "'>'", "'<='", "'>='", "'&'", "'\\E'", "'#count'", 
      "'#max'", "'#min'", "'#sum'"
    },
    std::vector<std::string>{
      "", "NAF", "COMMENT_EMPTY", "COMMENT", "SYMBOLIC_CONSTANT", "VARIABLE", 
      "STRING", "NUMBER", "WS", "DOT", "DDOT", "COMMA", "HEAD_SEPARATOR", 
      "SEMICOLON", "COLON", "AT", "CONS", "WCONS", "PLUS", "DASH", "TIMES", 
      "SLASH", "BACK_SLASH", "PARAM_OPEN", "PARAM_CLOSE", "SQUARE_OPEN", 
      "SQUARE_CLOSED", "CURLY_OPEN", "CURLY_CLOSED", "QUERY_MARK", "ANON_VAR", 
      "EQUAL", "UNEQUAL", "LESS", "GREATER", "LESS_OR_EQ", "GREATER_OR_EQ", 
      "AMPERSAND", "EXISTS", "AGGR_COUNT", "AGGR_MAX", "AGGR_MIN", "AGGR_SUM"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,42,237,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,1,0,
  	1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,5,2,97,8,2,10,2,12,2,100,9,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,5,3,108,8,3,10,3,12,3,111,9,3,1,4,1,4,5,4,115,
  	8,4,10,4,12,4,118,9,4,1,5,1,5,1,5,1,5,5,5,124,8,5,10,5,12,5,127,9,5,1,
  	5,1,5,1,6,4,6,132,8,6,11,6,12,6,133,1,7,4,7,137,8,7,11,7,12,7,138,1,7,
  	1,7,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,
  	1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,
  	1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,30,3,30,193,8,30,1,31,1,31,1,31,
  	1,31,3,31,199,8,31,1,32,1,32,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,
  	1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,
  	1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,2,98,
  	125,0,42,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,
  	13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,
  	49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,
  	36,73,37,75,38,77,39,79,40,81,41,83,42,1,0,5,1,0,97,122,4,0,48,57,65,
  	90,95,95,97,122,1,0,65,90,1,0,48,57,2,0,9,10,32,32,245,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,
  	0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,
  	25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,
  	0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,
  	0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,
  	57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,
  	0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,
  	0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,1,85,1,0,0,0,3,89,1,0,0,0,5,
  	94,1,0,0,0,7,105,1,0,0,0,9,112,1,0,0,0,11,119,1,0,0,0,13,131,1,0,0,0,
  	15,136,1,0,0,0,17,142,1,0,0,0,19,144,1,0,0,0,21,147,1,0,0,0,23,149,1,
  	0,0,0,25,151,1,0,0,0,27,153,1,0,0,0,29,155,1,0,0,0,31,157,1,0,0,0,33,
  	160,1,0,0,0,35,163,1,0,0,0,37,165,1,0,0,0,39,167,1,0,0,0,41,169,1,0,0,
  	0,43,171,1,0,0,0,45,173,1,0,0,0,47,175,1,0,0,0,49,177,1,0,0,0,51,179,
  	1,0,0,0,53,181,1,0,0,0,55,183,1,0,0,0,57,185,1,0,0,0,59,187,1,0,0,0,61,
  	192,1,0,0,0,63,198,1,0,0,0,65,200,1,0,0,0,67,202,1,0,0,0,69,204,1,0,0,
  	0,71,207,1,0,0,0,73,210,1,0,0,0,75,212,1,0,0,0,77,215,1,0,0,0,79,222,
  	1,0,0,0,81,227,1,0,0,0,83,232,1,0,0,0,85,86,5,110,0,0,86,87,5,111,0,0,
  	87,88,5,116,0,0,88,2,1,0,0,0,89,90,5,37,0,0,90,91,5,10,0,0,91,92,1,0,
  	0,0,92,93,6,1,0,0,93,4,1,0,0,0,94,98,5,37,0,0,95,97,9,0,0,0,96,95,1,0,
  	0,0,97,100,1,0,0,0,98,99,1,0,0,0,98,96,1,0,0,0,99,101,1,0,0,0,100,98,
  	1,0,0,0,101,102,5,10,0,0,102,103,1,0,0,0,103,104,6,2,0,0,104,6,1,0,0,
  	0,105,109,7,0,0,0,106,108,7,1,0,0,107,106,1,0,0,0,108,111,1,0,0,0,109,
  	107,1,0,0,0,109,110,1,0,0,0,110,8,1,0,0,0,111,109,1,0,0,0,112,116,7,2,
  	0,0,113,115,7,1,0,0,114,113,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,
  	117,1,0,0,0,117,10,1,0,0,0,118,116,1,0,0,0,119,125,5,34,0,0,120,121,5,
  	92,0,0,121,124,5,34,0,0,122,124,9,0,0,0,123,120,1,0,0,0,123,122,1,0,0,
  	0,124,127,1,0,0,0,125,126,1,0,0,0,125,123,1,0,0,0,126,128,1,0,0,0,127,
  	125,1,0,0,0,128,129,5,34,0,0,129,12,1,0,0,0,130,132,7,3,0,0,131,130,1,
  	0,0,0,132,133,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,14,1,0,0,0,
  	135,137,7,4,0,0,136,135,1,0,0,0,137,138,1,0,0,0,138,136,1,0,0,0,138,139,
  	1,0,0,0,139,140,1,0,0,0,140,141,6,7,0,0,141,16,1,0,0,0,142,143,5,46,0,
  	0,143,18,1,0,0,0,144,145,5,46,0,0,145,146,5,46,0,0,146,20,1,0,0,0,147,
  	148,5,44,0,0,148,22,1,0,0,0,149,150,5,124,0,0,150,24,1,0,0,0,151,152,
  	5,59,0,0,152,26,1,0,0,0,153,154,5,58,0,0,154,28,1,0,0,0,155,156,5,64,
  	0,0,156,30,1,0,0,0,157,158,5,58,0,0,158,159,5,45,0,0,159,32,1,0,0,0,160,
  	161,5,58,0,0,161,162,5,126,0,0,162,34,1,0,0,0,163,164,5,43,0,0,164,36,
  	1,0,0,0,165,166,5,45,0,0,166,38,1,0,0,0,167,168,5,42,0,0,168,40,1,0,0,
  	0,169,170,5,47,0,0,170,42,1,0,0,0,171,172,5,92,0,0,172,44,1,0,0,0,173,
  	174,5,40,0,0,174,46,1,0,0,0,175,176,5,41,0,0,176,48,1,0,0,0,177,178,5,
  	91,0,0,178,50,1,0,0,0,179,180,5,93,0,0,180,52,1,0,0,0,181,182,5,123,0,
  	0,182,54,1,0,0,0,183,184,5,125,0,0,184,56,1,0,0,0,185,186,5,63,0,0,186,
  	58,1,0,0,0,187,188,5,95,0,0,188,60,1,0,0,0,189,193,5,61,0,0,190,191,5,
  	61,0,0,191,193,5,61,0,0,192,189,1,0,0,0,192,190,1,0,0,0,193,62,1,0,0,
  	0,194,195,5,60,0,0,195,199,5,62,0,0,196,197,5,33,0,0,197,199,5,61,0,0,
  	198,194,1,0,0,0,198,196,1,0,0,0,199,64,1,0,0,0,200,201,5,60,0,0,201,66,
  	1,0,0,0,202,203,5,62,0,0,203,68,1,0,0,0,204,205,5,60,0,0,205,206,5,61,
  	0,0,206,70,1,0,0,0,207,208,5,62,0,0,208,209,5,61,0,0,209,72,1,0,0,0,210,
  	211,5,38,0,0,211,74,1,0,0,0,212,213,5,92,0,0,213,214,5,69,0,0,214,76,
  	1,0,0,0,215,216,5,35,0,0,216,217,5,99,0,0,217,218,5,111,0,0,218,219,5,
  	117,0,0,219,220,5,110,0,0,220,221,5,116,0,0,221,78,1,0,0,0,222,223,5,
  	35,0,0,223,224,5,109,0,0,224,225,5,97,0,0,225,226,5,120,0,0,226,80,1,
  	0,0,0,227,228,5,35,0,0,228,229,5,109,0,0,229,230,5,105,0,0,230,231,5,
  	110,0,0,231,82,1,0,0,0,232,233,5,35,0,0,233,234,5,115,0,0,234,235,5,117,
  	0,0,235,236,5,109,0,0,236,84,1,0,0,0,10,0,98,109,116,123,125,133,138,
  	192,198,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aspcore2lexerLexerStaticData = staticData.release();
}

}

ASPCore2Lexer::ASPCore2Lexer(CharStream *input) : Lexer(input) {
  ASPCore2Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *aspcore2lexerLexerStaticData->atn, aspcore2lexerLexerStaticData->decisionToDFA, aspcore2lexerLexerStaticData->sharedContextCache);
}

ASPCore2Lexer::~ASPCore2Lexer() {
  delete _interpreter;
}

std::string ASPCore2Lexer::getGrammarFileName() const {
  return "ASPCore2.g4";
}

const std::vector<std::string>& ASPCore2Lexer::getRuleNames() const {
  return aspcore2lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ASPCore2Lexer::getChannelNames() const {
  return aspcore2lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ASPCore2Lexer::getModeNames() const {
  return aspcore2lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ASPCore2Lexer::getVocabulary() const {
  return aspcore2lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ASPCore2Lexer::getSerializedATN() const {
  return aspcore2lexerLexerStaticData->serializedATN;
}

const atn::ATN& ASPCore2Lexer::getATN() const {
  return *aspcore2lexerLexerStaticData->atn;
}




void ASPCore2Lexer::initialize() {
  std::call_once(aspcore2lexerLexerOnceFlag, aspcore2lexerLexerInitialize);
}
