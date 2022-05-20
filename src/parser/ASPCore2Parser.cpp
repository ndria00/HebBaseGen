
// Generated from ../ASPCore2.g4 by ANTLR 4.10.1


#include "ASPCore2Listener.h"

#include "ASPCore2Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ASPCore2ParserStaticData final {
  ASPCore2ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ASPCore2ParserStaticData(const ASPCore2ParserStaticData&) = delete;
  ASPCore2ParserStaticData(ASPCore2ParserStaticData&&) = delete;
  ASPCore2ParserStaticData& operator=(const ASPCore2ParserStaticData&) = delete;
  ASPCore2ParserStaticData& operator=(ASPCore2ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag aspcore2ParserOnceFlag;
ASPCore2ParserStaticData *aspcore2ParserStaticData = nullptr;

void aspcore2ParserInitialize() {
  assert(aspcore2ParserStaticData == nullptr);
  auto staticData = std::make_unique<ASPCore2ParserStaticData>(
    std::vector<std::string>{
      "program", "rule", "simple_rule", "head", "body", "weight_at_levels", 
      "levels_and_terms", "disjunction", "conjunction", "classic_literal", 
      "naf_literals", "naf_literal", "naf_literal_aggregate", "existential_atom", 
      "atom", "extAtom", "extSemicol", "identifier", "query", "lower_guard_compare_aggregate", 
      "upper_guard_compare_aggregate", "compare_aggregate", "lower_guard_leftward_left_aggregate", 
      "leftward_left_aggregate", "left_aggregate", "lower_guard_rightward_left_aggregate", 
      "rightward_left_aggregate", "upper_guard_leftward_right_aggregate", 
      "upper_guard_rightward_right_aggregate", "right_aggregate", "aggregate_atom", 
      "leftwardop", "rightwardop", "aggregate", "aggregate_elements", "aggregate_element", 
      "aggregate_function", "terms", "basic_terms", "builtin_atom", "compareop", 
      "binop", "factor", "basic_term", "ground_term", "variable_term", "functional_term", 
      "expr", "arithop2", "arithop1", "term_", "term__", "term", "vars"
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
  	4,1,42,442,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,1,0,4,0,110,8,0,11,0,12,0,
  	111,1,1,1,1,3,1,116,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,139,8,2,1,3,1,3,1,4,1,4,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,154,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,3,6,165,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,177,
  	8,7,1,8,1,8,1,8,1,8,1,8,3,8,184,8,8,1,9,1,9,1,9,3,9,189,8,9,1,10,1,10,
  	1,10,1,10,1,10,3,10,196,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	205,8,11,1,12,1,12,1,12,1,12,3,12,211,8,12,1,13,1,13,1,13,1,13,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,227,8,14,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,256,8,15,1,
  	16,1,16,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,
  	21,1,21,1,21,1,21,1,21,3,21,277,8,21,1,22,1,22,1,22,1,23,1,23,1,23,1,
  	24,1,24,3,24,287,8,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,
  	28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,3,29,307,8,29,1,30,1,30,1,
  	30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,318,8,30,1,31,1,31,1,32,1,32,1,
  	33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,333,8,33,1,34,1,34,1,
  	34,1,34,1,34,3,34,340,8,34,1,35,1,35,1,35,1,35,1,36,1,36,1,37,1,37,1,
  	37,1,37,1,37,3,37,353,8,37,1,38,1,38,1,38,1,38,1,38,3,38,360,8,38,1,39,
  	1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,41,1,41,3,41,372,8,41,1,42,1,42,
  	1,42,1,42,1,42,3,42,379,8,42,1,43,1,43,1,43,3,43,384,8,43,1,44,1,44,1,
  	44,1,44,1,44,3,44,391,8,44,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,47,1,
  	47,1,47,1,47,1,47,3,47,405,8,47,1,48,1,48,1,49,1,49,1,50,1,50,1,50,1,
  	50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,3,50,422,8,50,1,51,1,51,1,51,1,
  	51,1,51,1,51,3,51,430,8,51,1,52,1,52,3,52,434,8,52,1,53,1,53,1,53,1,53,
  	3,53,440,8,53,1,53,0,0,54,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,
  	78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,0,8,1,0,4,6,2,0,33,33,
  	35,35,2,0,34,34,36,36,1,0,39,42,1,0,31,32,2,0,5,5,30,30,1,0,20,22,1,0,
  	18,19,441,0,109,1,0,0,0,2,115,1,0,0,0,4,138,1,0,0,0,6,140,1,0,0,0,8,142,
  	1,0,0,0,10,153,1,0,0,0,12,164,1,0,0,0,14,176,1,0,0,0,16,183,1,0,0,0,18,
  	188,1,0,0,0,20,195,1,0,0,0,22,204,1,0,0,0,24,210,1,0,0,0,26,212,1,0,0,
  	0,28,226,1,0,0,0,30,255,1,0,0,0,32,257,1,0,0,0,34,259,1,0,0,0,36,261,
  	1,0,0,0,38,264,1,0,0,0,40,267,1,0,0,0,42,276,1,0,0,0,44,278,1,0,0,0,46,
  	281,1,0,0,0,48,286,1,0,0,0,50,288,1,0,0,0,52,291,1,0,0,0,54,294,1,0,0,
  	0,56,297,1,0,0,0,58,306,1,0,0,0,60,317,1,0,0,0,62,319,1,0,0,0,64,321,
  	1,0,0,0,66,332,1,0,0,0,68,339,1,0,0,0,70,341,1,0,0,0,72,345,1,0,0,0,74,
  	352,1,0,0,0,76,359,1,0,0,0,78,361,1,0,0,0,80,365,1,0,0,0,82,371,1,0,0,
  	0,84,378,1,0,0,0,86,383,1,0,0,0,88,390,1,0,0,0,90,392,1,0,0,0,92,394,
  	1,0,0,0,94,404,1,0,0,0,96,406,1,0,0,0,98,408,1,0,0,0,100,421,1,0,0,0,
  	102,429,1,0,0,0,104,433,1,0,0,0,106,439,1,0,0,0,108,110,3,2,1,0,109,108,
  	1,0,0,0,110,111,1,0,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,1,1,0,0,0,
  	113,116,3,4,2,0,114,116,3,36,18,0,115,113,1,0,0,0,115,114,1,0,0,0,116,
  	3,1,0,0,0,117,118,3,6,3,0,118,119,5,9,0,0,119,139,1,0,0,0,120,121,3,6,
  	3,0,121,122,5,16,0,0,122,123,5,9,0,0,123,139,1,0,0,0,124,125,3,6,3,0,
  	125,126,5,16,0,0,126,127,3,8,4,0,127,128,5,9,0,0,128,139,1,0,0,0,129,
  	130,5,16,0,0,130,131,3,8,4,0,131,132,5,9,0,0,132,139,1,0,0,0,133,134,
  	5,17,0,0,134,135,3,8,4,0,135,136,5,9,0,0,136,137,3,10,5,0,137,139,1,0,
  	0,0,138,117,1,0,0,0,138,120,1,0,0,0,138,124,1,0,0,0,138,129,1,0,0,0,138,
  	133,1,0,0,0,139,5,1,0,0,0,140,141,3,14,7,0,141,7,1,0,0,0,142,143,3,16,
  	8,0,143,9,1,0,0,0,144,145,5,25,0,0,145,146,3,104,52,0,146,147,5,26,0,
  	0,147,154,1,0,0,0,148,149,5,25,0,0,149,150,3,104,52,0,150,151,3,12,6,
  	0,151,152,5,26,0,0,152,154,1,0,0,0,153,144,1,0,0,0,153,148,1,0,0,0,154,
  	11,1,0,0,0,155,156,5,15,0,0,156,165,3,104,52,0,157,158,5,15,0,0,158,159,
  	3,104,52,0,159,160,5,11,0,0,160,161,3,74,37,0,161,165,1,0,0,0,162,163,
  	5,11,0,0,163,165,3,74,37,0,164,155,1,0,0,0,164,157,1,0,0,0,164,162,1,
  	0,0,0,165,13,1,0,0,0,166,177,3,18,9,0,167,168,3,18,9,0,168,169,5,12,0,
  	0,169,170,3,14,7,0,170,177,1,0,0,0,171,177,3,26,13,0,172,173,3,26,13,
  	0,173,174,5,12,0,0,174,175,3,14,7,0,175,177,1,0,0,0,176,166,1,0,0,0,176,
  	167,1,0,0,0,176,171,1,0,0,0,176,172,1,0,0,0,177,15,1,0,0,0,178,184,3,
  	24,12,0,179,180,3,24,12,0,180,181,5,11,0,0,181,182,3,16,8,0,182,184,1,
  	0,0,0,183,178,1,0,0,0,183,179,1,0,0,0,184,17,1,0,0,0,185,189,3,28,14,
  	0,186,187,5,19,0,0,187,189,3,28,14,0,188,185,1,0,0,0,188,186,1,0,0,0,
  	189,19,1,0,0,0,190,196,3,22,11,0,191,192,3,22,11,0,192,193,5,11,0,0,193,
  	194,3,20,10,0,194,196,1,0,0,0,195,190,1,0,0,0,195,191,1,0,0,0,196,21,
  	1,0,0,0,197,205,3,18,9,0,198,199,5,1,0,0,199,205,3,18,9,0,200,205,3,78,
  	39,0,201,205,3,30,15,0,202,203,5,1,0,0,203,205,3,30,15,0,204,197,1,0,
  	0,0,204,198,1,0,0,0,204,200,1,0,0,0,204,201,1,0,0,0,204,202,1,0,0,0,205,
  	23,1,0,0,0,206,211,3,22,11,0,207,211,3,60,30,0,208,209,5,1,0,0,209,211,
  	3,60,30,0,210,206,1,0,0,0,210,207,1,0,0,0,210,208,1,0,0,0,211,25,1,0,
  	0,0,212,213,5,38,0,0,213,214,3,106,53,0,214,215,3,28,14,0,215,27,1,0,
  	0,0,216,227,3,34,17,0,217,218,3,34,17,0,218,219,5,23,0,0,219,220,3,74,
  	37,0,220,221,5,24,0,0,221,227,1,0,0,0,222,223,3,34,17,0,223,224,5,23,
  	0,0,224,225,5,24,0,0,225,227,1,0,0,0,226,216,1,0,0,0,226,217,1,0,0,0,
  	226,222,1,0,0,0,227,29,1,0,0,0,228,229,5,37,0,0,229,230,3,34,17,0,230,
  	231,5,23,0,0,231,232,3,74,37,0,232,233,3,32,16,0,233,234,3,74,37,0,234,
  	235,5,24,0,0,235,256,1,0,0,0,236,237,5,37,0,0,237,238,3,34,17,0,238,239,
  	5,23,0,0,239,240,3,32,16,0,240,241,3,74,37,0,241,242,5,24,0,0,242,256,
  	1,0,0,0,243,244,5,37,0,0,244,245,3,34,17,0,245,246,5,23,0,0,246,247,3,
  	74,37,0,247,248,3,32,16,0,248,249,5,24,0,0,249,256,1,0,0,0,250,251,5,
  	37,0,0,251,252,3,34,17,0,252,253,5,23,0,0,253,254,5,24,0,0,254,256,1,
  	0,0,0,255,228,1,0,0,0,255,236,1,0,0,0,255,243,1,0,0,0,255,250,1,0,0,0,
  	256,31,1,0,0,0,257,258,5,13,0,0,258,33,1,0,0,0,259,260,7,0,0,0,260,35,
  	1,0,0,0,261,262,3,28,14,0,262,263,5,29,0,0,263,37,1,0,0,0,264,265,3,104,
  	52,0,265,266,3,80,40,0,266,39,1,0,0,0,267,268,3,80,40,0,268,269,3,104,
  	52,0,269,41,1,0,0,0,270,271,3,38,19,0,271,272,3,66,33,0,272,277,1,0,0,
  	0,273,274,3,66,33,0,274,275,3,40,20,0,275,277,1,0,0,0,276,270,1,0,0,0,
  	276,273,1,0,0,0,277,43,1,0,0,0,278,279,3,104,52,0,279,280,3,62,31,0,280,
  	45,1,0,0,0,281,282,3,44,22,0,282,283,3,66,33,0,283,47,1,0,0,0,284,287,
  	3,46,23,0,285,287,3,52,26,0,286,284,1,0,0,0,286,285,1,0,0,0,287,49,1,
  	0,0,0,288,289,3,104,52,0,289,290,3,64,32,0,290,51,1,0,0,0,291,292,3,50,
  	25,0,292,293,3,66,33,0,293,53,1,0,0,0,294,295,3,62,31,0,295,296,3,104,
  	52,0,296,55,1,0,0,0,297,298,3,64,32,0,298,299,3,104,52,0,299,57,1,0,0,
  	0,300,301,3,66,33,0,301,302,3,54,27,0,302,307,1,0,0,0,303,304,3,66,33,
  	0,304,305,3,56,28,0,305,307,1,0,0,0,306,300,1,0,0,0,306,303,1,0,0,0,307,
  	59,1,0,0,0,308,318,3,48,24,0,309,318,3,58,29,0,310,318,3,42,21,0,311,
  	312,3,46,23,0,312,313,3,54,27,0,313,318,1,0,0,0,314,315,3,52,26,0,315,
  	316,3,56,28,0,316,318,1,0,0,0,317,308,1,0,0,0,317,309,1,0,0,0,317,310,
  	1,0,0,0,317,311,1,0,0,0,317,314,1,0,0,0,318,61,1,0,0,0,319,320,7,1,0,
  	0,320,63,1,0,0,0,321,322,7,2,0,0,322,65,1,0,0,0,323,324,3,72,36,0,324,
  	325,5,27,0,0,325,326,3,68,34,0,326,327,5,28,0,0,327,333,1,0,0,0,328,329,
  	3,72,36,0,329,330,5,27,0,0,330,331,5,28,0,0,331,333,1,0,0,0,332,323,1,
  	0,0,0,332,328,1,0,0,0,333,67,1,0,0,0,334,335,3,70,35,0,335,336,5,13,0,
  	0,336,337,3,68,34,0,337,340,1,0,0,0,338,340,3,70,35,0,339,334,1,0,0,0,
  	339,338,1,0,0,0,340,69,1,0,0,0,341,342,3,76,38,0,342,343,5,14,0,0,343,
  	344,3,20,10,0,344,71,1,0,0,0,345,346,7,3,0,0,346,73,1,0,0,0,347,353,3,
  	104,52,0,348,349,3,104,52,0,349,350,5,11,0,0,350,351,3,74,37,0,351,353,
  	1,0,0,0,352,347,1,0,0,0,352,348,1,0,0,0,353,75,1,0,0,0,354,360,3,86,43,
  	0,355,356,3,86,43,0,356,357,5,11,0,0,357,358,3,76,38,0,358,360,1,0,0,
  	0,359,354,1,0,0,0,359,355,1,0,0,0,360,77,1,0,0,0,361,362,3,104,52,0,362,
  	363,3,82,41,0,363,364,3,104,52,0,364,79,1,0,0,0,365,366,7,4,0,0,366,81,
  	1,0,0,0,367,372,3,80,40,0,368,372,3,80,40,0,369,372,3,62,31,0,370,372,
  	3,64,32,0,371,367,1,0,0,0,371,368,1,0,0,0,371,369,1,0,0,0,371,370,1,0,
  	0,0,372,83,1,0,0,0,373,379,3,102,51,0,374,375,3,102,51,0,375,376,3,96,
  	48,0,376,377,3,84,42,0,377,379,1,0,0,0,378,373,1,0,0,0,378,374,1,0,0,
  	0,379,85,1,0,0,0,380,384,3,88,44,0,381,384,3,90,45,0,382,384,3,92,46,
  	0,383,380,1,0,0,0,383,381,1,0,0,0,383,382,1,0,0,0,384,87,1,0,0,0,385,
  	391,5,4,0,0,386,391,5,6,0,0,387,391,5,7,0,0,388,389,5,19,0,0,389,391,
  	5,7,0,0,390,385,1,0,0,0,390,386,1,0,0,0,390,387,1,0,0,0,390,388,1,0,0,
  	0,391,89,1,0,0,0,392,393,7,5,0,0,393,91,1,0,0,0,394,395,3,34,17,0,395,
  	396,5,23,0,0,396,397,3,74,37,0,397,398,5,24,0,0,398,93,1,0,0,0,399,405,
  	3,84,42,0,400,401,3,84,42,0,401,402,3,98,49,0,402,403,3,94,47,0,403,405,
  	1,0,0,0,404,399,1,0,0,0,404,400,1,0,0,0,405,95,1,0,0,0,406,407,7,6,0,
  	0,407,97,1,0,0,0,408,409,7,7,0,0,409,99,1,0,0,0,410,422,5,30,0,0,411,
  	412,3,34,17,0,412,413,5,23,0,0,413,414,3,74,37,0,414,415,5,24,0,0,415,
  	422,1,0,0,0,416,417,5,7,0,0,417,418,5,10,0,0,418,422,5,7,0,0,419,420,
  	5,19,0,0,420,422,3,104,52,0,421,410,1,0,0,0,421,411,1,0,0,0,421,416,1,
  	0,0,0,421,419,1,0,0,0,422,101,1,0,0,0,423,430,3,34,17,0,424,430,5,7,0,
  	0,425,426,5,23,0,0,426,427,3,104,52,0,427,428,5,24,0,0,428,430,1,0,0,
  	0,429,423,1,0,0,0,429,424,1,0,0,0,429,425,1,0,0,0,430,103,1,0,0,0,431,
  	434,3,100,50,0,432,434,3,94,47,0,433,431,1,0,0,0,433,432,1,0,0,0,434,
  	105,1,0,0,0,435,440,5,5,0,0,436,437,5,5,0,0,437,438,5,11,0,0,438,440,
  	3,106,53,0,439,435,1,0,0,0,439,436,1,0,0,0,440,107,1,0,0,0,30,111,115,
  	138,153,164,176,183,188,195,204,210,226,255,276,286,306,317,332,339,352,
  	359,371,378,383,390,404,421,429,433,439
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aspcore2ParserStaticData = staticData.release();
}

}

ASPCore2Parser::ASPCore2Parser(TokenStream *input) : ASPCore2Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ASPCore2Parser::ASPCore2Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ASPCore2Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *aspcore2ParserStaticData->atn, aspcore2ParserStaticData->decisionToDFA, aspcore2ParserStaticData->sharedContextCache, options);
}

ASPCore2Parser::~ASPCore2Parser() {
  delete _interpreter;
}

const atn::ATN& ASPCore2Parser::getATN() const {
  return *aspcore2ParserStaticData->atn;
}

std::string ASPCore2Parser::getGrammarFileName() const {
  return "ASPCore2.g4";
}

const std::vector<std::string>& ASPCore2Parser::getRuleNames() const {
  return aspcore2ParserStaticData->ruleNames;
}

const dfa::Vocabulary& ASPCore2Parser::getVocabulary() const {
  return aspcore2ParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ASPCore2Parser::getSerializedATN() const {
  return aspcore2ParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

ASPCore2Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ASPCore2Parser::RuleContext *> ASPCore2Parser::ProgramContext::rule_() {
  return getRuleContexts<ASPCore2Parser::RuleContext>();
}

ASPCore2Parser::RuleContext* ASPCore2Parser::ProgramContext::rule_(size_t i) {
  return getRuleContext<ASPCore2Parser::RuleContext>(i);
}


size_t ASPCore2Parser::ProgramContext::getRuleIndex() const {
  return ASPCore2Parser::RuleProgram;
}

void ASPCore2Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void ASPCore2Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

ASPCore2Parser::ProgramContext* ASPCore2Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ASPCore2Parser::RuleProgram);
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
    setState(109); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(108);
      rule_();
      setState(111); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASPCore2Parser::SYMBOLIC_CONSTANT)
      | (1ULL << ASPCore2Parser::VARIABLE)
      | (1ULL << ASPCore2Parser::STRING)
      | (1ULL << ASPCore2Parser::CONS)
      | (1ULL << ASPCore2Parser::WCONS)
      | (1ULL << ASPCore2Parser::DASH)
      | (1ULL << ASPCore2Parser::EXISTS))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleContext ------------------------------------------------------------------

ASPCore2Parser::RuleContext::RuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Simple_ruleContext* ASPCore2Parser::RuleContext::simple_rule() {
  return getRuleContext<ASPCore2Parser::Simple_ruleContext>(0);
}

ASPCore2Parser::QueryContext* ASPCore2Parser::RuleContext::query() {
  return getRuleContext<ASPCore2Parser::QueryContext>(0);
}


size_t ASPCore2Parser::RuleContext::getRuleIndex() const {
  return ASPCore2Parser::RuleRule;
}

void ASPCore2Parser::RuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRule(this);
}

void ASPCore2Parser::RuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRule(this);
}

ASPCore2Parser::RuleContext* ASPCore2Parser::rule_() {
  RuleContext *_localctx = _tracker.createInstance<RuleContext>(_ctx, getState());
  enterRule(_localctx, 2, ASPCore2Parser::RuleRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      simple_rule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
      query();
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

//----------------- Simple_ruleContext ------------------------------------------------------------------

ASPCore2Parser::Simple_ruleContext::Simple_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::HeadContext* ASPCore2Parser::Simple_ruleContext::head() {
  return getRuleContext<ASPCore2Parser::HeadContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Simple_ruleContext::DOT() {
  return getToken(ASPCore2Parser::DOT, 0);
}

tree::TerminalNode* ASPCore2Parser::Simple_ruleContext::CONS() {
  return getToken(ASPCore2Parser::CONS, 0);
}

ASPCore2Parser::BodyContext* ASPCore2Parser::Simple_ruleContext::body() {
  return getRuleContext<ASPCore2Parser::BodyContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Simple_ruleContext::WCONS() {
  return getToken(ASPCore2Parser::WCONS, 0);
}

ASPCore2Parser::Weight_at_levelsContext* ASPCore2Parser::Simple_ruleContext::weight_at_levels() {
  return getRuleContext<ASPCore2Parser::Weight_at_levelsContext>(0);
}


size_t ASPCore2Parser::Simple_ruleContext::getRuleIndex() const {
  return ASPCore2Parser::RuleSimple_rule;
}

void ASPCore2Parser::Simple_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_rule(this);
}

void ASPCore2Parser::Simple_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_rule(this);
}

ASPCore2Parser::Simple_ruleContext* ASPCore2Parser::simple_rule() {
  Simple_ruleContext *_localctx = _tracker.createInstance<Simple_ruleContext>(_ctx, getState());
  enterRule(_localctx, 4, ASPCore2Parser::RuleSimple_rule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(117);
      head();
      setState(118);
      match(ASPCore2Parser::DOT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
      head();
      setState(121);
      match(ASPCore2Parser::CONS);
      setState(122);
      match(ASPCore2Parser::DOT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(124);
      head();
      setState(125);
      match(ASPCore2Parser::CONS);
      setState(126);
      body();
      setState(127);
      match(ASPCore2Parser::DOT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(129);
      match(ASPCore2Parser::CONS);
      setState(130);
      body();
      setState(131);
      match(ASPCore2Parser::DOT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(133);
      match(ASPCore2Parser::WCONS);
      setState(134);
      body();
      setState(135);
      match(ASPCore2Parser::DOT);
      setState(136);
      weight_at_levels();
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

//----------------- HeadContext ------------------------------------------------------------------

ASPCore2Parser::HeadContext::HeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::DisjunctionContext* ASPCore2Parser::HeadContext::disjunction() {
  return getRuleContext<ASPCore2Parser::DisjunctionContext>(0);
}


size_t ASPCore2Parser::HeadContext::getRuleIndex() const {
  return ASPCore2Parser::RuleHead;
}

void ASPCore2Parser::HeadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHead(this);
}

void ASPCore2Parser::HeadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHead(this);
}

ASPCore2Parser::HeadContext* ASPCore2Parser::head() {
  HeadContext *_localctx = _tracker.createInstance<HeadContext>(_ctx, getState());
  enterRule(_localctx, 6, ASPCore2Parser::RuleHead);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    disjunction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

ASPCore2Parser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::ConjunctionContext* ASPCore2Parser::BodyContext::conjunction() {
  return getRuleContext<ASPCore2Parser::ConjunctionContext>(0);
}


size_t ASPCore2Parser::BodyContext::getRuleIndex() const {
  return ASPCore2Parser::RuleBody;
}

void ASPCore2Parser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void ASPCore2Parser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}

ASPCore2Parser::BodyContext* ASPCore2Parser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 8, ASPCore2Parser::RuleBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    conjunction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Weight_at_levelsContext ------------------------------------------------------------------

ASPCore2Parser::Weight_at_levelsContext::Weight_at_levelsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Weight_at_levelsContext::SQUARE_OPEN() {
  return getToken(ASPCore2Parser::SQUARE_OPEN, 0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Weight_at_levelsContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Weight_at_levelsContext::SQUARE_CLOSED() {
  return getToken(ASPCore2Parser::SQUARE_CLOSED, 0);
}

ASPCore2Parser::Levels_and_termsContext* ASPCore2Parser::Weight_at_levelsContext::levels_and_terms() {
  return getRuleContext<ASPCore2Parser::Levels_and_termsContext>(0);
}


size_t ASPCore2Parser::Weight_at_levelsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleWeight_at_levels;
}

void ASPCore2Parser::Weight_at_levelsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWeight_at_levels(this);
}

void ASPCore2Parser::Weight_at_levelsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWeight_at_levels(this);
}

ASPCore2Parser::Weight_at_levelsContext* ASPCore2Parser::weight_at_levels() {
  Weight_at_levelsContext *_localctx = _tracker.createInstance<Weight_at_levelsContext>(_ctx, getState());
  enterRule(_localctx, 10, ASPCore2Parser::RuleWeight_at_levels);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      match(ASPCore2Parser::SQUARE_OPEN);
      setState(145);
      term();
      setState(146);
      match(ASPCore2Parser::SQUARE_CLOSED);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(148);
      match(ASPCore2Parser::SQUARE_OPEN);
      setState(149);
      term();
      setState(150);
      levels_and_terms();
      setState(151);
      match(ASPCore2Parser::SQUARE_CLOSED);
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

//----------------- Levels_and_termsContext ------------------------------------------------------------------

ASPCore2Parser::Levels_and_termsContext::Levels_and_termsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Levels_and_termsContext::AT() {
  return getToken(ASPCore2Parser::AT, 0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Levels_and_termsContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Levels_and_termsContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::Levels_and_termsContext::terms() {
  return getRuleContext<ASPCore2Parser::TermsContext>(0);
}


size_t ASPCore2Parser::Levels_and_termsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLevels_and_terms;
}

void ASPCore2Parser::Levels_and_termsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLevels_and_terms(this);
}

void ASPCore2Parser::Levels_and_termsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLevels_and_terms(this);
}

ASPCore2Parser::Levels_and_termsContext* ASPCore2Parser::levels_and_terms() {
  Levels_and_termsContext *_localctx = _tracker.createInstance<Levels_and_termsContext>(_ctx, getState());
  enterRule(_localctx, 12, ASPCore2Parser::RuleLevels_and_terms);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(ASPCore2Parser::AT);
      setState(156);
      term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      match(ASPCore2Parser::AT);
      setState(158);
      term();
      setState(159);
      match(ASPCore2Parser::COMMA);
      setState(160);
      terms();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
      match(ASPCore2Parser::COMMA);
      setState(163);
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

//----------------- DisjunctionContext ------------------------------------------------------------------

ASPCore2Parser::DisjunctionContext::DisjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Classic_literalContext* ASPCore2Parser::DisjunctionContext::classic_literal() {
  return getRuleContext<ASPCore2Parser::Classic_literalContext>(0);
}

tree::TerminalNode* ASPCore2Parser::DisjunctionContext::HEAD_SEPARATOR() {
  return getToken(ASPCore2Parser::HEAD_SEPARATOR, 0);
}

ASPCore2Parser::DisjunctionContext* ASPCore2Parser::DisjunctionContext::disjunction() {
  return getRuleContext<ASPCore2Parser::DisjunctionContext>(0);
}

ASPCore2Parser::Existential_atomContext* ASPCore2Parser::DisjunctionContext::existential_atom() {
  return getRuleContext<ASPCore2Parser::Existential_atomContext>(0);
}


size_t ASPCore2Parser::DisjunctionContext::getRuleIndex() const {
  return ASPCore2Parser::RuleDisjunction;
}

void ASPCore2Parser::DisjunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDisjunction(this);
}

void ASPCore2Parser::DisjunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDisjunction(this);
}

ASPCore2Parser::DisjunctionContext* ASPCore2Parser::disjunction() {
  DisjunctionContext *_localctx = _tracker.createInstance<DisjunctionContext>(_ctx, getState());
  enterRule(_localctx, 14, ASPCore2Parser::RuleDisjunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      classic_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      classic_literal();
      setState(168);
      match(ASPCore2Parser::HEAD_SEPARATOR);
      setState(169);
      disjunction();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(171);
      existential_atom();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(172);
      existential_atom();
      setState(173);
      match(ASPCore2Parser::HEAD_SEPARATOR);
      setState(174);
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

//----------------- ConjunctionContext ------------------------------------------------------------------

ASPCore2Parser::ConjunctionContext::ConjunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Naf_literal_aggregateContext* ASPCore2Parser::ConjunctionContext::naf_literal_aggregate() {
  return getRuleContext<ASPCore2Parser::Naf_literal_aggregateContext>(0);
}

tree::TerminalNode* ASPCore2Parser::ConjunctionContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::ConjunctionContext* ASPCore2Parser::ConjunctionContext::conjunction() {
  return getRuleContext<ASPCore2Parser::ConjunctionContext>(0);
}


size_t ASPCore2Parser::ConjunctionContext::getRuleIndex() const {
  return ASPCore2Parser::RuleConjunction;
}

void ASPCore2Parser::ConjunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConjunction(this);
}

void ASPCore2Parser::ConjunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConjunction(this);
}

ASPCore2Parser::ConjunctionContext* ASPCore2Parser::conjunction() {
  ConjunctionContext *_localctx = _tracker.createInstance<ConjunctionContext>(_ctx, getState());
  enterRule(_localctx, 16, ASPCore2Parser::RuleConjunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(178);
      naf_literal_aggregate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(179);
      naf_literal_aggregate();
      setState(180);
      match(ASPCore2Parser::COMMA);
      setState(181);
      conjunction();
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

ASPCore2Parser::Classic_literalContext::Classic_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::AtomContext* ASPCore2Parser::Classic_literalContext::atom() {
  return getRuleContext<ASPCore2Parser::AtomContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Classic_literalContext::DASH() {
  return getToken(ASPCore2Parser::DASH, 0);
}


size_t ASPCore2Parser::Classic_literalContext::getRuleIndex() const {
  return ASPCore2Parser::RuleClassic_literal;
}

void ASPCore2Parser::Classic_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassic_literal(this);
}

void ASPCore2Parser::Classic_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassic_literal(this);
}

ASPCore2Parser::Classic_literalContext* ASPCore2Parser::classic_literal() {
  Classic_literalContext *_localctx = _tracker.createInstance<Classic_literalContext>(_ctx, getState());
  enterRule(_localctx, 18, ASPCore2Parser::RuleClassic_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2Parser::SYMBOLIC_CONSTANT:
      case ASPCore2Parser::VARIABLE:
      case ASPCore2Parser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(185);
        atom();
        break;
      }

      case ASPCore2Parser::DASH: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        match(ASPCore2Parser::DASH);
        setState(187);
        atom();
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

//----------------- Naf_literalsContext ------------------------------------------------------------------

ASPCore2Parser::Naf_literalsContext::Naf_literalsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Naf_literalContext* ASPCore2Parser::Naf_literalsContext::naf_literal() {
  return getRuleContext<ASPCore2Parser::Naf_literalContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Naf_literalsContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::Naf_literalsContext* ASPCore2Parser::Naf_literalsContext::naf_literals() {
  return getRuleContext<ASPCore2Parser::Naf_literalsContext>(0);
}


size_t ASPCore2Parser::Naf_literalsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleNaf_literals;
}

void ASPCore2Parser::Naf_literalsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNaf_literals(this);
}

void ASPCore2Parser::Naf_literalsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNaf_literals(this);
}

ASPCore2Parser::Naf_literalsContext* ASPCore2Parser::naf_literals() {
  Naf_literalsContext *_localctx = _tracker.createInstance<Naf_literalsContext>(_ctx, getState());
  enterRule(_localctx, 20, ASPCore2Parser::RuleNaf_literals);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(190);
      naf_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(191);
      naf_literal();
      setState(192);
      match(ASPCore2Parser::COMMA);
      setState(193);
      naf_literals();
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

//----------------- Naf_literalContext ------------------------------------------------------------------

ASPCore2Parser::Naf_literalContext::Naf_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Classic_literalContext* ASPCore2Parser::Naf_literalContext::classic_literal() {
  return getRuleContext<ASPCore2Parser::Classic_literalContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Naf_literalContext::NAF() {
  return getToken(ASPCore2Parser::NAF, 0);
}

ASPCore2Parser::Builtin_atomContext* ASPCore2Parser::Naf_literalContext::builtin_atom() {
  return getRuleContext<ASPCore2Parser::Builtin_atomContext>(0);
}

ASPCore2Parser::ExtAtomContext* ASPCore2Parser::Naf_literalContext::extAtom() {
  return getRuleContext<ASPCore2Parser::ExtAtomContext>(0);
}


size_t ASPCore2Parser::Naf_literalContext::getRuleIndex() const {
  return ASPCore2Parser::RuleNaf_literal;
}

void ASPCore2Parser::Naf_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNaf_literal(this);
}

void ASPCore2Parser::Naf_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNaf_literal(this);
}

ASPCore2Parser::Naf_literalContext* ASPCore2Parser::naf_literal() {
  Naf_literalContext *_localctx = _tracker.createInstance<Naf_literalContext>(_ctx, getState());
  enterRule(_localctx, 22, ASPCore2Parser::RuleNaf_literal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(197);
      classic_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(198);
      match(ASPCore2Parser::NAF);
      setState(199);
      classic_literal();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      builtin_atom();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(201);
      extAtom();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(202);
      match(ASPCore2Parser::NAF);
      setState(203);
      extAtom();
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

//----------------- Naf_literal_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Naf_literal_aggregateContext::Naf_literal_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Naf_literalContext* ASPCore2Parser::Naf_literal_aggregateContext::naf_literal() {
  return getRuleContext<ASPCore2Parser::Naf_literalContext>(0);
}

ASPCore2Parser::Aggregate_atomContext* ASPCore2Parser::Naf_literal_aggregateContext::aggregate_atom() {
  return getRuleContext<ASPCore2Parser::Aggregate_atomContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Naf_literal_aggregateContext::NAF() {
  return getToken(ASPCore2Parser::NAF, 0);
}


size_t ASPCore2Parser::Naf_literal_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleNaf_literal_aggregate;
}

void ASPCore2Parser::Naf_literal_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNaf_literal_aggregate(this);
}

void ASPCore2Parser::Naf_literal_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNaf_literal_aggregate(this);
}

ASPCore2Parser::Naf_literal_aggregateContext* ASPCore2Parser::naf_literal_aggregate() {
  Naf_literal_aggregateContext *_localctx = _tracker.createInstance<Naf_literal_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 24, ASPCore2Parser::RuleNaf_literal_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(206);
      naf_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(207);
      aggregate_atom();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(208);
      match(ASPCore2Parser::NAF);
      setState(209);
      aggregate_atom();
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

//----------------- Existential_atomContext ------------------------------------------------------------------

ASPCore2Parser::Existential_atomContext::Existential_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Existential_atomContext::EXISTS() {
  return getToken(ASPCore2Parser::EXISTS, 0);
}

ASPCore2Parser::VarsContext* ASPCore2Parser::Existential_atomContext::vars() {
  return getRuleContext<ASPCore2Parser::VarsContext>(0);
}

ASPCore2Parser::AtomContext* ASPCore2Parser::Existential_atomContext::atom() {
  return getRuleContext<ASPCore2Parser::AtomContext>(0);
}


size_t ASPCore2Parser::Existential_atomContext::getRuleIndex() const {
  return ASPCore2Parser::RuleExistential_atom;
}

void ASPCore2Parser::Existential_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExistential_atom(this);
}

void ASPCore2Parser::Existential_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExistential_atom(this);
}

ASPCore2Parser::Existential_atomContext* ASPCore2Parser::existential_atom() {
  Existential_atomContext *_localctx = _tracker.createInstance<Existential_atomContext>(_ctx, getState());
  enterRule(_localctx, 26, ASPCore2Parser::RuleExistential_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(ASPCore2Parser::EXISTS);
    setState(213);
    vars();
    setState(214);
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

ASPCore2Parser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::AtomContext::identifier() {
  return getRuleContext<ASPCore2Parser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2Parser::AtomContext::PARAM_OPEN() {
  return getToken(ASPCore2Parser::PARAM_OPEN, 0);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::AtomContext::terms() {
  return getRuleContext<ASPCore2Parser::TermsContext>(0);
}

tree::TerminalNode* ASPCore2Parser::AtomContext::PARAM_CLOSE() {
  return getToken(ASPCore2Parser::PARAM_CLOSE, 0);
}


size_t ASPCore2Parser::AtomContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAtom;
}

void ASPCore2Parser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void ASPCore2Parser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

ASPCore2Parser::AtomContext* ASPCore2Parser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 28, ASPCore2Parser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(216);
      identifier();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
      identifier();
      setState(218);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(219);
      terms();
      setState(220);
      match(ASPCore2Parser::PARAM_CLOSE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(222);
      identifier();
      setState(223);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(224);
      match(ASPCore2Parser::PARAM_CLOSE);
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

//----------------- ExtAtomContext ------------------------------------------------------------------

ASPCore2Parser::ExtAtomContext::ExtAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::ExtAtomContext::AMPERSAND() {
  return getToken(ASPCore2Parser::AMPERSAND, 0);
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::ExtAtomContext::identifier() {
  return getRuleContext<ASPCore2Parser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2Parser::ExtAtomContext::PARAM_OPEN() {
  return getToken(ASPCore2Parser::PARAM_OPEN, 0);
}

std::vector<ASPCore2Parser::TermsContext *> ASPCore2Parser::ExtAtomContext::terms() {
  return getRuleContexts<ASPCore2Parser::TermsContext>();
}

ASPCore2Parser::TermsContext* ASPCore2Parser::ExtAtomContext::terms(size_t i) {
  return getRuleContext<ASPCore2Parser::TermsContext>(i);
}

ASPCore2Parser::ExtSemicolContext* ASPCore2Parser::ExtAtomContext::extSemicol() {
  return getRuleContext<ASPCore2Parser::ExtSemicolContext>(0);
}

tree::TerminalNode* ASPCore2Parser::ExtAtomContext::PARAM_CLOSE() {
  return getToken(ASPCore2Parser::PARAM_CLOSE, 0);
}


size_t ASPCore2Parser::ExtAtomContext::getRuleIndex() const {
  return ASPCore2Parser::RuleExtAtom;
}

void ASPCore2Parser::ExtAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtAtom(this);
}

void ASPCore2Parser::ExtAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtAtom(this);
}

ASPCore2Parser::ExtAtomContext* ASPCore2Parser::extAtom() {
  ExtAtomContext *_localctx = _tracker.createInstance<ExtAtomContext>(_ctx, getState());
  enterRule(_localctx, 30, ASPCore2Parser::RuleExtAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      match(ASPCore2Parser::AMPERSAND);
      setState(229);
      identifier();
      setState(230);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(231);
      terms();
      setState(232);
      extSemicol();
      setState(233);
      terms();
      setState(234);
      match(ASPCore2Parser::PARAM_CLOSE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(236);
      match(ASPCore2Parser::AMPERSAND);
      setState(237);
      identifier();
      setState(238);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(239);
      extSemicol();
      setState(240);
      terms();
      setState(241);
      match(ASPCore2Parser::PARAM_CLOSE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(243);
      match(ASPCore2Parser::AMPERSAND);
      setState(244);
      identifier();
      setState(245);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(246);
      terms();
      setState(247);
      extSemicol();
      setState(248);
      match(ASPCore2Parser::PARAM_CLOSE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(250);
      match(ASPCore2Parser::AMPERSAND);
      setState(251);
      identifier();
      setState(252);
      match(ASPCore2Parser::PARAM_OPEN);
      setState(253);
      match(ASPCore2Parser::PARAM_CLOSE);
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

//----------------- ExtSemicolContext ------------------------------------------------------------------

ASPCore2Parser::ExtSemicolContext::ExtSemicolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::ExtSemicolContext::SEMICOLON() {
  return getToken(ASPCore2Parser::SEMICOLON, 0);
}


size_t ASPCore2Parser::ExtSemicolContext::getRuleIndex() const {
  return ASPCore2Parser::RuleExtSemicol;
}

void ASPCore2Parser::ExtSemicolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtSemicol(this);
}

void ASPCore2Parser::ExtSemicolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtSemicol(this);
}

ASPCore2Parser::ExtSemicolContext* ASPCore2Parser::extSemicol() {
  ExtSemicolContext *_localctx = _tracker.createInstance<ExtSemicolContext>(_ctx, getState());
  enterRule(_localctx, 32, ASPCore2Parser::RuleExtSemicol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(ASPCore2Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

ASPCore2Parser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::IdentifierContext::SYMBOLIC_CONSTANT() {
  return getToken(ASPCore2Parser::SYMBOLIC_CONSTANT, 0);
}

tree::TerminalNode* ASPCore2Parser::IdentifierContext::STRING() {
  return getToken(ASPCore2Parser::STRING, 0);
}

tree::TerminalNode* ASPCore2Parser::IdentifierContext::VARIABLE() {
  return getToken(ASPCore2Parser::VARIABLE, 0);
}


size_t ASPCore2Parser::IdentifierContext::getRuleIndex() const {
  return ASPCore2Parser::RuleIdentifier;
}

void ASPCore2Parser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void ASPCore2Parser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 34, ASPCore2Parser::RuleIdentifier);
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
    setState(259);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASPCore2Parser::SYMBOLIC_CONSTANT)
      | (1ULL << ASPCore2Parser::VARIABLE)
      | (1ULL << ASPCore2Parser::STRING))) != 0))) {
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

//----------------- QueryContext ------------------------------------------------------------------

ASPCore2Parser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::AtomContext* ASPCore2Parser::QueryContext::atom() {
  return getRuleContext<ASPCore2Parser::AtomContext>(0);
}

tree::TerminalNode* ASPCore2Parser::QueryContext::QUERY_MARK() {
  return getToken(ASPCore2Parser::QUERY_MARK, 0);
}


size_t ASPCore2Parser::QueryContext::getRuleIndex() const {
  return ASPCore2Parser::RuleQuery;
}

void ASPCore2Parser::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void ASPCore2Parser::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}

ASPCore2Parser::QueryContext* ASPCore2Parser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 36, ASPCore2Parser::RuleQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    atom();
    setState(262);
    match(ASPCore2Parser::QUERY_MARK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lower_guard_compare_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Lower_guard_compare_aggregateContext::Lower_guard_compare_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::TermContext* ASPCore2Parser::Lower_guard_compare_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

ASPCore2Parser::CompareopContext* ASPCore2Parser::Lower_guard_compare_aggregateContext::compareop() {
  return getRuleContext<ASPCore2Parser::CompareopContext>(0);
}


size_t ASPCore2Parser::Lower_guard_compare_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLower_guard_compare_aggregate;
}

void ASPCore2Parser::Lower_guard_compare_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_guard_compare_aggregate(this);
}

void ASPCore2Parser::Lower_guard_compare_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_guard_compare_aggregate(this);
}

ASPCore2Parser::Lower_guard_compare_aggregateContext* ASPCore2Parser::lower_guard_compare_aggregate() {
  Lower_guard_compare_aggregateContext *_localctx = _tracker.createInstance<Lower_guard_compare_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 38, ASPCore2Parser::RuleLower_guard_compare_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    term();
    setState(265);
    compareop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Upper_guard_compare_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Upper_guard_compare_aggregateContext::Upper_guard_compare_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::CompareopContext* ASPCore2Parser::Upper_guard_compare_aggregateContext::compareop() {
  return getRuleContext<ASPCore2Parser::CompareopContext>(0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Upper_guard_compare_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}


size_t ASPCore2Parser::Upper_guard_compare_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleUpper_guard_compare_aggregate;
}

void ASPCore2Parser::Upper_guard_compare_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_guard_compare_aggregate(this);
}

void ASPCore2Parser::Upper_guard_compare_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_guard_compare_aggregate(this);
}

ASPCore2Parser::Upper_guard_compare_aggregateContext* ASPCore2Parser::upper_guard_compare_aggregate() {
  Upper_guard_compare_aggregateContext *_localctx = _tracker.createInstance<Upper_guard_compare_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 40, ASPCore2Parser::RuleUpper_guard_compare_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    compareop();
    setState(268);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compare_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Compare_aggregateContext::Compare_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Lower_guard_compare_aggregateContext* ASPCore2Parser::Compare_aggregateContext::lower_guard_compare_aggregate() {
  return getRuleContext<ASPCore2Parser::Lower_guard_compare_aggregateContext>(0);
}

ASPCore2Parser::AggregateContext* ASPCore2Parser::Compare_aggregateContext::aggregate() {
  return getRuleContext<ASPCore2Parser::AggregateContext>(0);
}

ASPCore2Parser::Upper_guard_compare_aggregateContext* ASPCore2Parser::Compare_aggregateContext::upper_guard_compare_aggregate() {
  return getRuleContext<ASPCore2Parser::Upper_guard_compare_aggregateContext>(0);
}


size_t ASPCore2Parser::Compare_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleCompare_aggregate;
}

void ASPCore2Parser::Compare_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompare_aggregate(this);
}

void ASPCore2Parser::Compare_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompare_aggregate(this);
}

ASPCore2Parser::Compare_aggregateContext* ASPCore2Parser::compare_aggregate() {
  Compare_aggregateContext *_localctx = _tracker.createInstance<Compare_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 42, ASPCore2Parser::RuleCompare_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2Parser::SYMBOLIC_CONSTANT:
      case ASPCore2Parser::VARIABLE:
      case ASPCore2Parser::STRING:
      case ASPCore2Parser::NUMBER:
      case ASPCore2Parser::DASH:
      case ASPCore2Parser::PARAM_OPEN:
      case ASPCore2Parser::ANON_VAR: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        lower_guard_compare_aggregate();
        setState(271);
        aggregate();
        break;
      }

      case ASPCore2Parser::AGGR_COUNT:
      case ASPCore2Parser::AGGR_MAX:
      case ASPCore2Parser::AGGR_MIN:
      case ASPCore2Parser::AGGR_SUM: {
        enterOuterAlt(_localctx, 2);
        setState(273);
        aggregate();
        setState(274);
        upper_guard_compare_aggregate();
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

//----------------- Lower_guard_leftward_left_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::Lower_guard_leftward_left_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::TermContext* ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

ASPCore2Parser::LeftwardopContext* ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::leftwardop() {
  return getRuleContext<ASPCore2Parser::LeftwardopContext>(0);
}


size_t ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLower_guard_leftward_left_aggregate;
}

void ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_guard_leftward_left_aggregate(this);
}

void ASPCore2Parser::Lower_guard_leftward_left_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_guard_leftward_left_aggregate(this);
}

ASPCore2Parser::Lower_guard_leftward_left_aggregateContext* ASPCore2Parser::lower_guard_leftward_left_aggregate() {
  Lower_guard_leftward_left_aggregateContext *_localctx = _tracker.createInstance<Lower_guard_leftward_left_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 44, ASPCore2Parser::RuleLower_guard_leftward_left_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    term();
    setState(279);
    leftwardop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Leftward_left_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Leftward_left_aggregateContext::Leftward_left_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Lower_guard_leftward_left_aggregateContext* ASPCore2Parser::Leftward_left_aggregateContext::lower_guard_leftward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Lower_guard_leftward_left_aggregateContext>(0);
}

ASPCore2Parser::AggregateContext* ASPCore2Parser::Leftward_left_aggregateContext::aggregate() {
  return getRuleContext<ASPCore2Parser::AggregateContext>(0);
}


size_t ASPCore2Parser::Leftward_left_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLeftward_left_aggregate;
}

void ASPCore2Parser::Leftward_left_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftward_left_aggregate(this);
}

void ASPCore2Parser::Leftward_left_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftward_left_aggregate(this);
}

ASPCore2Parser::Leftward_left_aggregateContext* ASPCore2Parser::leftward_left_aggregate() {
  Leftward_left_aggregateContext *_localctx = _tracker.createInstance<Leftward_left_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 46, ASPCore2Parser::RuleLeftward_left_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    lower_guard_leftward_left_aggregate();
    setState(282);
    aggregate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Left_aggregateContext::Left_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Leftward_left_aggregateContext* ASPCore2Parser::Left_aggregateContext::leftward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Leftward_left_aggregateContext>(0);
}

ASPCore2Parser::Rightward_left_aggregateContext* ASPCore2Parser::Left_aggregateContext::rightward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Rightward_left_aggregateContext>(0);
}


size_t ASPCore2Parser::Left_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLeft_aggregate;
}

void ASPCore2Parser::Left_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_aggregate(this);
}

void ASPCore2Parser::Left_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_aggregate(this);
}

ASPCore2Parser::Left_aggregateContext* ASPCore2Parser::left_aggregate() {
  Left_aggregateContext *_localctx = _tracker.createInstance<Left_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 48, ASPCore2Parser::RuleLeft_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(284);
      leftward_left_aggregate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(285);
      rightward_left_aggregate();
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

//----------------- Lower_guard_rightward_left_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::Lower_guard_rightward_left_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::TermContext* ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

ASPCore2Parser::RightwardopContext* ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::rightwardop() {
  return getRuleContext<ASPCore2Parser::RightwardopContext>(0);
}


size_t ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLower_guard_rightward_left_aggregate;
}

void ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLower_guard_rightward_left_aggregate(this);
}

void ASPCore2Parser::Lower_guard_rightward_left_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLower_guard_rightward_left_aggregate(this);
}

ASPCore2Parser::Lower_guard_rightward_left_aggregateContext* ASPCore2Parser::lower_guard_rightward_left_aggregate() {
  Lower_guard_rightward_left_aggregateContext *_localctx = _tracker.createInstance<Lower_guard_rightward_left_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 50, ASPCore2Parser::RuleLower_guard_rightward_left_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    term();
    setState(289);
    rightwardop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rightward_left_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Rightward_left_aggregateContext::Rightward_left_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Lower_guard_rightward_left_aggregateContext* ASPCore2Parser::Rightward_left_aggregateContext::lower_guard_rightward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Lower_guard_rightward_left_aggregateContext>(0);
}

ASPCore2Parser::AggregateContext* ASPCore2Parser::Rightward_left_aggregateContext::aggregate() {
  return getRuleContext<ASPCore2Parser::AggregateContext>(0);
}


size_t ASPCore2Parser::Rightward_left_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleRightward_left_aggregate;
}

void ASPCore2Parser::Rightward_left_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightward_left_aggregate(this);
}

void ASPCore2Parser::Rightward_left_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightward_left_aggregate(this);
}

ASPCore2Parser::Rightward_left_aggregateContext* ASPCore2Parser::rightward_left_aggregate() {
  Rightward_left_aggregateContext *_localctx = _tracker.createInstance<Rightward_left_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 52, ASPCore2Parser::RuleRightward_left_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    lower_guard_rightward_left_aggregate();
    setState(292);
    aggregate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Upper_guard_leftward_right_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::Upper_guard_leftward_right_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::LeftwardopContext* ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::leftwardop() {
  return getRuleContext<ASPCore2Parser::LeftwardopContext>(0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}


size_t ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleUpper_guard_leftward_right_aggregate;
}

void ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_guard_leftward_right_aggregate(this);
}

void ASPCore2Parser::Upper_guard_leftward_right_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_guard_leftward_right_aggregate(this);
}

ASPCore2Parser::Upper_guard_leftward_right_aggregateContext* ASPCore2Parser::upper_guard_leftward_right_aggregate() {
  Upper_guard_leftward_right_aggregateContext *_localctx = _tracker.createInstance<Upper_guard_leftward_right_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 54, ASPCore2Parser::RuleUpper_guard_leftward_right_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    leftwardop();
    setState(295);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Upper_guard_rightward_right_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::Upper_guard_rightward_right_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::RightwardopContext* ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::rightwardop() {
  return getRuleContext<ASPCore2Parser::RightwardopContext>(0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}


size_t ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleUpper_guard_rightward_right_aggregate;
}

void ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpper_guard_rightward_right_aggregate(this);
}

void ASPCore2Parser::Upper_guard_rightward_right_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpper_guard_rightward_right_aggregate(this);
}

ASPCore2Parser::Upper_guard_rightward_right_aggregateContext* ASPCore2Parser::upper_guard_rightward_right_aggregate() {
  Upper_guard_rightward_right_aggregateContext *_localctx = _tracker.createInstance<Upper_guard_rightward_right_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 56, ASPCore2Parser::RuleUpper_guard_rightward_right_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    rightwardop();
    setState(298);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Right_aggregateContext ------------------------------------------------------------------

ASPCore2Parser::Right_aggregateContext::Right_aggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::AggregateContext* ASPCore2Parser::Right_aggregateContext::aggregate() {
  return getRuleContext<ASPCore2Parser::AggregateContext>(0);
}

ASPCore2Parser::Upper_guard_leftward_right_aggregateContext* ASPCore2Parser::Right_aggregateContext::upper_guard_leftward_right_aggregate() {
  return getRuleContext<ASPCore2Parser::Upper_guard_leftward_right_aggregateContext>(0);
}

ASPCore2Parser::Upper_guard_rightward_right_aggregateContext* ASPCore2Parser::Right_aggregateContext::upper_guard_rightward_right_aggregate() {
  return getRuleContext<ASPCore2Parser::Upper_guard_rightward_right_aggregateContext>(0);
}


size_t ASPCore2Parser::Right_aggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleRight_aggregate;
}

void ASPCore2Parser::Right_aggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRight_aggregate(this);
}

void ASPCore2Parser::Right_aggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRight_aggregate(this);
}

ASPCore2Parser::Right_aggregateContext* ASPCore2Parser::right_aggregate() {
  Right_aggregateContext *_localctx = _tracker.createInstance<Right_aggregateContext>(_ctx, getState());
  enterRule(_localctx, 58, ASPCore2Parser::RuleRight_aggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(300);
      aggregate();
      setState(301);
      upper_guard_leftward_right_aggregate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(303);
      aggregate();
      setState(304);
      upper_guard_rightward_right_aggregate();
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

//----------------- Aggregate_atomContext ------------------------------------------------------------------

ASPCore2Parser::Aggregate_atomContext::Aggregate_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Left_aggregateContext* ASPCore2Parser::Aggregate_atomContext::left_aggregate() {
  return getRuleContext<ASPCore2Parser::Left_aggregateContext>(0);
}

ASPCore2Parser::Right_aggregateContext* ASPCore2Parser::Aggregate_atomContext::right_aggregate() {
  return getRuleContext<ASPCore2Parser::Right_aggregateContext>(0);
}

ASPCore2Parser::Compare_aggregateContext* ASPCore2Parser::Aggregate_atomContext::compare_aggregate() {
  return getRuleContext<ASPCore2Parser::Compare_aggregateContext>(0);
}

ASPCore2Parser::Leftward_left_aggregateContext* ASPCore2Parser::Aggregate_atomContext::leftward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Leftward_left_aggregateContext>(0);
}

ASPCore2Parser::Upper_guard_leftward_right_aggregateContext* ASPCore2Parser::Aggregate_atomContext::upper_guard_leftward_right_aggregate() {
  return getRuleContext<ASPCore2Parser::Upper_guard_leftward_right_aggregateContext>(0);
}

ASPCore2Parser::Rightward_left_aggregateContext* ASPCore2Parser::Aggregate_atomContext::rightward_left_aggregate() {
  return getRuleContext<ASPCore2Parser::Rightward_left_aggregateContext>(0);
}

ASPCore2Parser::Upper_guard_rightward_right_aggregateContext* ASPCore2Parser::Aggregate_atomContext::upper_guard_rightward_right_aggregate() {
  return getRuleContext<ASPCore2Parser::Upper_guard_rightward_right_aggregateContext>(0);
}


size_t ASPCore2Parser::Aggregate_atomContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAggregate_atom;
}

void ASPCore2Parser::Aggregate_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_atom(this);
}

void ASPCore2Parser::Aggregate_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_atom(this);
}

ASPCore2Parser::Aggregate_atomContext* ASPCore2Parser::aggregate_atom() {
  Aggregate_atomContext *_localctx = _tracker.createInstance<Aggregate_atomContext>(_ctx, getState());
  enterRule(_localctx, 60, ASPCore2Parser::RuleAggregate_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
      left_aggregate();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(309);
      right_aggregate();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(310);
      compare_aggregate();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(311);
      leftward_left_aggregate();
      setState(312);
      upper_guard_leftward_right_aggregate();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(314);
      rightward_left_aggregate();
      setState(315);
      upper_guard_rightward_right_aggregate();
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

//----------------- LeftwardopContext ------------------------------------------------------------------

ASPCore2Parser::LeftwardopContext::LeftwardopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::LeftwardopContext::LESS() {
  return getToken(ASPCore2Parser::LESS, 0);
}

tree::TerminalNode* ASPCore2Parser::LeftwardopContext::LESS_OR_EQ() {
  return getToken(ASPCore2Parser::LESS_OR_EQ, 0);
}


size_t ASPCore2Parser::LeftwardopContext::getRuleIndex() const {
  return ASPCore2Parser::RuleLeftwardop;
}

void ASPCore2Parser::LeftwardopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftwardop(this);
}

void ASPCore2Parser::LeftwardopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftwardop(this);
}

ASPCore2Parser::LeftwardopContext* ASPCore2Parser::leftwardop() {
  LeftwardopContext *_localctx = _tracker.createInstance<LeftwardopContext>(_ctx, getState());
  enterRule(_localctx, 62, ASPCore2Parser::RuleLeftwardop);
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
    setState(319);
    _la = _input->LA(1);
    if (!(_la == ASPCore2Parser::LESS

    || _la == ASPCore2Parser::LESS_OR_EQ)) {
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

//----------------- RightwardopContext ------------------------------------------------------------------

ASPCore2Parser::RightwardopContext::RightwardopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::RightwardopContext::GREATER() {
  return getToken(ASPCore2Parser::GREATER, 0);
}

tree::TerminalNode* ASPCore2Parser::RightwardopContext::GREATER_OR_EQ() {
  return getToken(ASPCore2Parser::GREATER_OR_EQ, 0);
}


size_t ASPCore2Parser::RightwardopContext::getRuleIndex() const {
  return ASPCore2Parser::RuleRightwardop;
}

void ASPCore2Parser::RightwardopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightwardop(this);
}

void ASPCore2Parser::RightwardopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightwardop(this);
}

ASPCore2Parser::RightwardopContext* ASPCore2Parser::rightwardop() {
  RightwardopContext *_localctx = _tracker.createInstance<RightwardopContext>(_ctx, getState());
  enterRule(_localctx, 64, ASPCore2Parser::RuleRightwardop);
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
    setState(321);
    _la = _input->LA(1);
    if (!(_la == ASPCore2Parser::GREATER

    || _la == ASPCore2Parser::GREATER_OR_EQ)) {
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

//----------------- AggregateContext ------------------------------------------------------------------

ASPCore2Parser::AggregateContext::AggregateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Aggregate_functionContext* ASPCore2Parser::AggregateContext::aggregate_function() {
  return getRuleContext<ASPCore2Parser::Aggregate_functionContext>(0);
}

tree::TerminalNode* ASPCore2Parser::AggregateContext::CURLY_OPEN() {
  return getToken(ASPCore2Parser::CURLY_OPEN, 0);
}

ASPCore2Parser::Aggregate_elementsContext* ASPCore2Parser::AggregateContext::aggregate_elements() {
  return getRuleContext<ASPCore2Parser::Aggregate_elementsContext>(0);
}

tree::TerminalNode* ASPCore2Parser::AggregateContext::CURLY_CLOSED() {
  return getToken(ASPCore2Parser::CURLY_CLOSED, 0);
}


size_t ASPCore2Parser::AggregateContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAggregate;
}

void ASPCore2Parser::AggregateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate(this);
}

void ASPCore2Parser::AggregateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate(this);
}

ASPCore2Parser::AggregateContext* ASPCore2Parser::aggregate() {
  AggregateContext *_localctx = _tracker.createInstance<AggregateContext>(_ctx, getState());
  enterRule(_localctx, 66, ASPCore2Parser::RuleAggregate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      aggregate_function();
      setState(324);
      match(ASPCore2Parser::CURLY_OPEN);
      setState(325);
      aggregate_elements();
      setState(326);
      match(ASPCore2Parser::CURLY_CLOSED);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(328);
      aggregate_function();
      setState(329);
      match(ASPCore2Parser::CURLY_OPEN);
      setState(330);
      match(ASPCore2Parser::CURLY_CLOSED);
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

//----------------- Aggregate_elementsContext ------------------------------------------------------------------

ASPCore2Parser::Aggregate_elementsContext::Aggregate_elementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Aggregate_elementContext* ASPCore2Parser::Aggregate_elementsContext::aggregate_element() {
  return getRuleContext<ASPCore2Parser::Aggregate_elementContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Aggregate_elementsContext::SEMICOLON() {
  return getToken(ASPCore2Parser::SEMICOLON, 0);
}

ASPCore2Parser::Aggregate_elementsContext* ASPCore2Parser::Aggregate_elementsContext::aggregate_elements() {
  return getRuleContext<ASPCore2Parser::Aggregate_elementsContext>(0);
}


size_t ASPCore2Parser::Aggregate_elementsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAggregate_elements;
}

void ASPCore2Parser::Aggregate_elementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_elements(this);
}

void ASPCore2Parser::Aggregate_elementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_elements(this);
}

ASPCore2Parser::Aggregate_elementsContext* ASPCore2Parser::aggregate_elements() {
  Aggregate_elementsContext *_localctx = _tracker.createInstance<Aggregate_elementsContext>(_ctx, getState());
  enterRule(_localctx, 68, ASPCore2Parser::RuleAggregate_elements);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(339);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      aggregate_element();
      setState(335);
      match(ASPCore2Parser::SEMICOLON);
      setState(336);
      aggregate_elements();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(338);
      aggregate_element();
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

//----------------- Aggregate_elementContext ------------------------------------------------------------------

ASPCore2Parser::Aggregate_elementContext::Aggregate_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Basic_termsContext* ASPCore2Parser::Aggregate_elementContext::basic_terms() {
  return getRuleContext<ASPCore2Parser::Basic_termsContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Aggregate_elementContext::COLON() {
  return getToken(ASPCore2Parser::COLON, 0);
}

ASPCore2Parser::Naf_literalsContext* ASPCore2Parser::Aggregate_elementContext::naf_literals() {
  return getRuleContext<ASPCore2Parser::Naf_literalsContext>(0);
}


size_t ASPCore2Parser::Aggregate_elementContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAggregate_element;
}

void ASPCore2Parser::Aggregate_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_element(this);
}

void ASPCore2Parser::Aggregate_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_element(this);
}

ASPCore2Parser::Aggregate_elementContext* ASPCore2Parser::aggregate_element() {
  Aggregate_elementContext *_localctx = _tracker.createInstance<Aggregate_elementContext>(_ctx, getState());
  enterRule(_localctx, 70, ASPCore2Parser::RuleAggregate_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    basic_terms();
    setState(342);
    match(ASPCore2Parser::COLON);
    setState(343);
    naf_literals();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregate_functionContext ------------------------------------------------------------------

ASPCore2Parser::Aggregate_functionContext::Aggregate_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Aggregate_functionContext::AGGR_COUNT() {
  return getToken(ASPCore2Parser::AGGR_COUNT, 0);
}

tree::TerminalNode* ASPCore2Parser::Aggregate_functionContext::AGGR_MAX() {
  return getToken(ASPCore2Parser::AGGR_MAX, 0);
}

tree::TerminalNode* ASPCore2Parser::Aggregate_functionContext::AGGR_MIN() {
  return getToken(ASPCore2Parser::AGGR_MIN, 0);
}

tree::TerminalNode* ASPCore2Parser::Aggregate_functionContext::AGGR_SUM() {
  return getToken(ASPCore2Parser::AGGR_SUM, 0);
}


size_t ASPCore2Parser::Aggregate_functionContext::getRuleIndex() const {
  return ASPCore2Parser::RuleAggregate_function;
}

void ASPCore2Parser::Aggregate_functionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_function(this);
}

void ASPCore2Parser::Aggregate_functionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_function(this);
}

ASPCore2Parser::Aggregate_functionContext* ASPCore2Parser::aggregate_function() {
  Aggregate_functionContext *_localctx = _tracker.createInstance<Aggregate_functionContext>(_ctx, getState());
  enterRule(_localctx, 72, ASPCore2Parser::RuleAggregate_function);
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
    setState(345);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASPCore2Parser::AGGR_COUNT)
      | (1ULL << ASPCore2Parser::AGGR_MAX)
      | (1ULL << ASPCore2Parser::AGGR_MIN)
      | (1ULL << ASPCore2Parser::AGGR_SUM))) != 0))) {
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

//----------------- TermsContext ------------------------------------------------------------------

ASPCore2Parser::TermsContext::TermsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::TermContext* ASPCore2Parser::TermsContext::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

tree::TerminalNode* ASPCore2Parser::TermsContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::TermsContext::terms() {
  return getRuleContext<ASPCore2Parser::TermsContext>(0);
}


size_t ASPCore2Parser::TermsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleTerms;
}

void ASPCore2Parser::TermsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerms(this);
}

void ASPCore2Parser::TermsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerms(this);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::terms() {
  TermsContext *_localctx = _tracker.createInstance<TermsContext>(_ctx, getState());
  enterRule(_localctx, 74, ASPCore2Parser::RuleTerms);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(347);
      term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(348);
      term();
      setState(349);
      match(ASPCore2Parser::COMMA);
      setState(350);
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

//----------------- Basic_termsContext ------------------------------------------------------------------

ASPCore2Parser::Basic_termsContext::Basic_termsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Basic_termContext* ASPCore2Parser::Basic_termsContext::basic_term() {
  return getRuleContext<ASPCore2Parser::Basic_termContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Basic_termsContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::Basic_termsContext* ASPCore2Parser::Basic_termsContext::basic_terms() {
  return getRuleContext<ASPCore2Parser::Basic_termsContext>(0);
}


size_t ASPCore2Parser::Basic_termsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleBasic_terms;
}

void ASPCore2Parser::Basic_termsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasic_terms(this);
}

void ASPCore2Parser::Basic_termsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasic_terms(this);
}

ASPCore2Parser::Basic_termsContext* ASPCore2Parser::basic_terms() {
  Basic_termsContext *_localctx = _tracker.createInstance<Basic_termsContext>(_ctx, getState());
  enterRule(_localctx, 76, ASPCore2Parser::RuleBasic_terms);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(359);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(354);
      basic_term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(355);
      basic_term();
      setState(356);
      match(ASPCore2Parser::COMMA);
      setState(357);
      basic_terms();
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

//----------------- Builtin_atomContext ------------------------------------------------------------------

ASPCore2Parser::Builtin_atomContext::Builtin_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ASPCore2Parser::TermContext *> ASPCore2Parser::Builtin_atomContext::term() {
  return getRuleContexts<ASPCore2Parser::TermContext>();
}

ASPCore2Parser::TermContext* ASPCore2Parser::Builtin_atomContext::term(size_t i) {
  return getRuleContext<ASPCore2Parser::TermContext>(i);
}

ASPCore2Parser::BinopContext* ASPCore2Parser::Builtin_atomContext::binop() {
  return getRuleContext<ASPCore2Parser::BinopContext>(0);
}


size_t ASPCore2Parser::Builtin_atomContext::getRuleIndex() const {
  return ASPCore2Parser::RuleBuiltin_atom;
}

void ASPCore2Parser::Builtin_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltin_atom(this);
}

void ASPCore2Parser::Builtin_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltin_atom(this);
}

ASPCore2Parser::Builtin_atomContext* ASPCore2Parser::builtin_atom() {
  Builtin_atomContext *_localctx = _tracker.createInstance<Builtin_atomContext>(_ctx, getState());
  enterRule(_localctx, 78, ASPCore2Parser::RuleBuiltin_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    term();
    setState(362);
    binop();
    setState(363);
    term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareopContext ------------------------------------------------------------------

ASPCore2Parser::CompareopContext::CompareopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::CompareopContext::EQUAL() {
  return getToken(ASPCore2Parser::EQUAL, 0);
}

tree::TerminalNode* ASPCore2Parser::CompareopContext::UNEQUAL() {
  return getToken(ASPCore2Parser::UNEQUAL, 0);
}


size_t ASPCore2Parser::CompareopContext::getRuleIndex() const {
  return ASPCore2Parser::RuleCompareop;
}

void ASPCore2Parser::CompareopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompareop(this);
}

void ASPCore2Parser::CompareopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompareop(this);
}

ASPCore2Parser::CompareopContext* ASPCore2Parser::compareop() {
  CompareopContext *_localctx = _tracker.createInstance<CompareopContext>(_ctx, getState());
  enterRule(_localctx, 80, ASPCore2Parser::RuleCompareop);
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
    setState(365);
    _la = _input->LA(1);
    if (!(_la == ASPCore2Parser::EQUAL

    || _la == ASPCore2Parser::UNEQUAL)) {
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

//----------------- BinopContext ------------------------------------------------------------------

ASPCore2Parser::BinopContext::BinopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::CompareopContext* ASPCore2Parser::BinopContext::compareop() {
  return getRuleContext<ASPCore2Parser::CompareopContext>(0);
}

ASPCore2Parser::LeftwardopContext* ASPCore2Parser::BinopContext::leftwardop() {
  return getRuleContext<ASPCore2Parser::LeftwardopContext>(0);
}

ASPCore2Parser::RightwardopContext* ASPCore2Parser::BinopContext::rightwardop() {
  return getRuleContext<ASPCore2Parser::RightwardopContext>(0);
}


size_t ASPCore2Parser::BinopContext::getRuleIndex() const {
  return ASPCore2Parser::RuleBinop;
}

void ASPCore2Parser::BinopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinop(this);
}

void ASPCore2Parser::BinopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinop(this);
}

ASPCore2Parser::BinopContext* ASPCore2Parser::binop() {
  BinopContext *_localctx = _tracker.createInstance<BinopContext>(_ctx, getState());
  enterRule(_localctx, 82, ASPCore2Parser::RuleBinop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(367);
      compareop();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(368);
      compareop();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(369);
      leftwardop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(370);
      rightwardop();
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

//----------------- FactorContext ------------------------------------------------------------------

ASPCore2Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Term__Context* ASPCore2Parser::FactorContext::term__() {
  return getRuleContext<ASPCore2Parser::Term__Context>(0);
}

ASPCore2Parser::Arithop2Context* ASPCore2Parser::FactorContext::arithop2() {
  return getRuleContext<ASPCore2Parser::Arithop2Context>(0);
}

ASPCore2Parser::FactorContext* ASPCore2Parser::FactorContext::factor() {
  return getRuleContext<ASPCore2Parser::FactorContext>(0);
}


size_t ASPCore2Parser::FactorContext::getRuleIndex() const {
  return ASPCore2Parser::RuleFactor;
}

void ASPCore2Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void ASPCore2Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

ASPCore2Parser::FactorContext* ASPCore2Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 84, ASPCore2Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(373);
      term__();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(374);
      term__();
      setState(375);
      arithop2();
      setState(376);
      factor();
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

//----------------- Basic_termContext ------------------------------------------------------------------

ASPCore2Parser::Basic_termContext::Basic_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Ground_termContext* ASPCore2Parser::Basic_termContext::ground_term() {
  return getRuleContext<ASPCore2Parser::Ground_termContext>(0);
}

ASPCore2Parser::Variable_termContext* ASPCore2Parser::Basic_termContext::variable_term() {
  return getRuleContext<ASPCore2Parser::Variable_termContext>(0);
}

ASPCore2Parser::Functional_termContext* ASPCore2Parser::Basic_termContext::functional_term() {
  return getRuleContext<ASPCore2Parser::Functional_termContext>(0);
}


size_t ASPCore2Parser::Basic_termContext::getRuleIndex() const {
  return ASPCore2Parser::RuleBasic_term;
}

void ASPCore2Parser::Basic_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasic_term(this);
}

void ASPCore2Parser::Basic_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasic_term(this);
}

ASPCore2Parser::Basic_termContext* ASPCore2Parser::basic_term() {
  Basic_termContext *_localctx = _tracker.createInstance<Basic_termContext>(_ctx, getState());
  enterRule(_localctx, 86, ASPCore2Parser::RuleBasic_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(383);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(380);
      ground_term();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      variable_term();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(382);
      functional_term();
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

//----------------- Ground_termContext ------------------------------------------------------------------

ASPCore2Parser::Ground_termContext::Ground_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Ground_termContext::SYMBOLIC_CONSTANT() {
  return getToken(ASPCore2Parser::SYMBOLIC_CONSTANT, 0);
}

tree::TerminalNode* ASPCore2Parser::Ground_termContext::STRING() {
  return getToken(ASPCore2Parser::STRING, 0);
}

tree::TerminalNode* ASPCore2Parser::Ground_termContext::NUMBER() {
  return getToken(ASPCore2Parser::NUMBER, 0);
}

tree::TerminalNode* ASPCore2Parser::Ground_termContext::DASH() {
  return getToken(ASPCore2Parser::DASH, 0);
}


size_t ASPCore2Parser::Ground_termContext::getRuleIndex() const {
  return ASPCore2Parser::RuleGround_term;
}

void ASPCore2Parser::Ground_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGround_term(this);
}

void ASPCore2Parser::Ground_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGround_term(this);
}

ASPCore2Parser::Ground_termContext* ASPCore2Parser::ground_term() {
  Ground_termContext *_localctx = _tracker.createInstance<Ground_termContext>(_ctx, getState());
  enterRule(_localctx, 88, ASPCore2Parser::RuleGround_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2Parser::SYMBOLIC_CONSTANT: {
        enterOuterAlt(_localctx, 1);
        setState(385);
        match(ASPCore2Parser::SYMBOLIC_CONSTANT);
        break;
      }

      case ASPCore2Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(386);
        match(ASPCore2Parser::STRING);
        break;
      }

      case ASPCore2Parser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(387);
        match(ASPCore2Parser::NUMBER);
        break;
      }

      case ASPCore2Parser::DASH: {
        enterOuterAlt(_localctx, 4);
        setState(388);
        match(ASPCore2Parser::DASH);
        setState(389);
        match(ASPCore2Parser::NUMBER);
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

//----------------- Variable_termContext ------------------------------------------------------------------

ASPCore2Parser::Variable_termContext::Variable_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Variable_termContext::VARIABLE() {
  return getToken(ASPCore2Parser::VARIABLE, 0);
}

tree::TerminalNode* ASPCore2Parser::Variable_termContext::ANON_VAR() {
  return getToken(ASPCore2Parser::ANON_VAR, 0);
}


size_t ASPCore2Parser::Variable_termContext::getRuleIndex() const {
  return ASPCore2Parser::RuleVariable_term;
}

void ASPCore2Parser::Variable_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_term(this);
}

void ASPCore2Parser::Variable_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_term(this);
}

ASPCore2Parser::Variable_termContext* ASPCore2Parser::variable_term() {
  Variable_termContext *_localctx = _tracker.createInstance<Variable_termContext>(_ctx, getState());
  enterRule(_localctx, 90, ASPCore2Parser::RuleVariable_term);
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
    setState(392);
    _la = _input->LA(1);
    if (!(_la == ASPCore2Parser::VARIABLE

    || _la == ASPCore2Parser::ANON_VAR)) {
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

//----------------- Functional_termContext ------------------------------------------------------------------

ASPCore2Parser::Functional_termContext::Functional_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::Functional_termContext::identifier() {
  return getRuleContext<ASPCore2Parser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Functional_termContext::PARAM_OPEN() {
  return getToken(ASPCore2Parser::PARAM_OPEN, 0);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::Functional_termContext::terms() {
  return getRuleContext<ASPCore2Parser::TermsContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Functional_termContext::PARAM_CLOSE() {
  return getToken(ASPCore2Parser::PARAM_CLOSE, 0);
}


size_t ASPCore2Parser::Functional_termContext::getRuleIndex() const {
  return ASPCore2Parser::RuleFunctional_term;
}

void ASPCore2Parser::Functional_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctional_term(this);
}

void ASPCore2Parser::Functional_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctional_term(this);
}

ASPCore2Parser::Functional_termContext* ASPCore2Parser::functional_term() {
  Functional_termContext *_localctx = _tracker.createInstance<Functional_termContext>(_ctx, getState());
  enterRule(_localctx, 92, ASPCore2Parser::RuleFunctional_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    identifier();
    setState(395);
    match(ASPCore2Parser::PARAM_OPEN);
    setState(396);
    terms();
    setState(397);
    match(ASPCore2Parser::PARAM_CLOSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ASPCore2Parser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::FactorContext* ASPCore2Parser::ExprContext::factor() {
  return getRuleContext<ASPCore2Parser::FactorContext>(0);
}

ASPCore2Parser::Arithop1Context* ASPCore2Parser::ExprContext::arithop1() {
  return getRuleContext<ASPCore2Parser::Arithop1Context>(0);
}

ASPCore2Parser::ExprContext* ASPCore2Parser::ExprContext::expr() {
  return getRuleContext<ASPCore2Parser::ExprContext>(0);
}


size_t ASPCore2Parser::ExprContext::getRuleIndex() const {
  return ASPCore2Parser::RuleExpr;
}

void ASPCore2Parser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ASPCore2Parser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

ASPCore2Parser::ExprContext* ASPCore2Parser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 94, ASPCore2Parser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(404);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(399);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(400);
      factor();
      setState(401);
      arithop1();
      setState(402);
      expr();
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

//----------------- Arithop2Context ------------------------------------------------------------------

ASPCore2Parser::Arithop2Context::Arithop2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Arithop2Context::TIMES() {
  return getToken(ASPCore2Parser::TIMES, 0);
}

tree::TerminalNode* ASPCore2Parser::Arithop2Context::SLASH() {
  return getToken(ASPCore2Parser::SLASH, 0);
}

tree::TerminalNode* ASPCore2Parser::Arithop2Context::BACK_SLASH() {
  return getToken(ASPCore2Parser::BACK_SLASH, 0);
}


size_t ASPCore2Parser::Arithop2Context::getRuleIndex() const {
  return ASPCore2Parser::RuleArithop2;
}

void ASPCore2Parser::Arithop2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithop2(this);
}

void ASPCore2Parser::Arithop2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithop2(this);
}

ASPCore2Parser::Arithop2Context* ASPCore2Parser::arithop2() {
  Arithop2Context *_localctx = _tracker.createInstance<Arithop2Context>(_ctx, getState());
  enterRule(_localctx, 96, ASPCore2Parser::RuleArithop2);
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
    setState(406);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ASPCore2Parser::TIMES)
      | (1ULL << ASPCore2Parser::SLASH)
      | (1ULL << ASPCore2Parser::BACK_SLASH))) != 0))) {
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

//----------------- Arithop1Context ------------------------------------------------------------------

ASPCore2Parser::Arithop1Context::Arithop1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Arithop1Context::PLUS() {
  return getToken(ASPCore2Parser::PLUS, 0);
}

tree::TerminalNode* ASPCore2Parser::Arithop1Context::DASH() {
  return getToken(ASPCore2Parser::DASH, 0);
}


size_t ASPCore2Parser::Arithop1Context::getRuleIndex() const {
  return ASPCore2Parser::RuleArithop1;
}

void ASPCore2Parser::Arithop1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithop1(this);
}

void ASPCore2Parser::Arithop1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithop1(this);
}

ASPCore2Parser::Arithop1Context* ASPCore2Parser::arithop1() {
  Arithop1Context *_localctx = _tracker.createInstance<Arithop1Context>(_ctx, getState());
  enterRule(_localctx, 98, ASPCore2Parser::RuleArithop1);
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
    setState(408);
    _la = _input->LA(1);
    if (!(_la == ASPCore2Parser::PLUS

    || _la == ASPCore2Parser::DASH)) {
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

//----------------- Term_Context ------------------------------------------------------------------

ASPCore2Parser::Term_Context::Term_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::Term_Context::ANON_VAR() {
  return getToken(ASPCore2Parser::ANON_VAR, 0);
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::Term_Context::identifier() {
  return getRuleContext<ASPCore2Parser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Term_Context::PARAM_OPEN() {
  return getToken(ASPCore2Parser::PARAM_OPEN, 0);
}

ASPCore2Parser::TermsContext* ASPCore2Parser::Term_Context::terms() {
  return getRuleContext<ASPCore2Parser::TermsContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Term_Context::PARAM_CLOSE() {
  return getToken(ASPCore2Parser::PARAM_CLOSE, 0);
}

std::vector<tree::TerminalNode *> ASPCore2Parser::Term_Context::NUMBER() {
  return getTokens(ASPCore2Parser::NUMBER);
}

tree::TerminalNode* ASPCore2Parser::Term_Context::NUMBER(size_t i) {
  return getToken(ASPCore2Parser::NUMBER, i);
}

tree::TerminalNode* ASPCore2Parser::Term_Context::DDOT() {
  return getToken(ASPCore2Parser::DDOT, 0);
}

tree::TerminalNode* ASPCore2Parser::Term_Context::DASH() {
  return getToken(ASPCore2Parser::DASH, 0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Term_Context::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}


size_t ASPCore2Parser::Term_Context::getRuleIndex() const {
  return ASPCore2Parser::RuleTerm_;
}

void ASPCore2Parser::Term_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm_(this);
}

void ASPCore2Parser::Term_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm_(this);
}

ASPCore2Parser::Term_Context* ASPCore2Parser::term_() {
  Term_Context *_localctx = _tracker.createInstance<Term_Context>(_ctx, getState());
  enterRule(_localctx, 100, ASPCore2Parser::RuleTerm_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(421);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2Parser::ANON_VAR: {
        enterOuterAlt(_localctx, 1);
        setState(410);
        match(ASPCore2Parser::ANON_VAR);
        break;
      }

      case ASPCore2Parser::SYMBOLIC_CONSTANT:
      case ASPCore2Parser::VARIABLE:
      case ASPCore2Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(411);
        identifier();
        setState(412);
        match(ASPCore2Parser::PARAM_OPEN);
        setState(413);
        terms();
        setState(414);
        match(ASPCore2Parser::PARAM_CLOSE);
        break;
      }

      case ASPCore2Parser::NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(416);
        match(ASPCore2Parser::NUMBER);
        setState(417);
        match(ASPCore2Parser::DDOT);
        setState(418);
        match(ASPCore2Parser::NUMBER);
        break;
      }

      case ASPCore2Parser::DASH: {
        enterOuterAlt(_localctx, 4);
        setState(419);
        match(ASPCore2Parser::DASH);
        setState(420);
        term();
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

//----------------- Term__Context ------------------------------------------------------------------

ASPCore2Parser::Term__Context::Term__Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::IdentifierContext* ASPCore2Parser::Term__Context::identifier() {
  return getRuleContext<ASPCore2Parser::IdentifierContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Term__Context::NUMBER() {
  return getToken(ASPCore2Parser::NUMBER, 0);
}

tree::TerminalNode* ASPCore2Parser::Term__Context::PARAM_OPEN() {
  return getToken(ASPCore2Parser::PARAM_OPEN, 0);
}

ASPCore2Parser::TermContext* ASPCore2Parser::Term__Context::term() {
  return getRuleContext<ASPCore2Parser::TermContext>(0);
}

tree::TerminalNode* ASPCore2Parser::Term__Context::PARAM_CLOSE() {
  return getToken(ASPCore2Parser::PARAM_CLOSE, 0);
}


size_t ASPCore2Parser::Term__Context::getRuleIndex() const {
  return ASPCore2Parser::RuleTerm__;
}

void ASPCore2Parser::Term__Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm__(this);
}

void ASPCore2Parser::Term__Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm__(this);
}

ASPCore2Parser::Term__Context* ASPCore2Parser::term__() {
  Term__Context *_localctx = _tracker.createInstance<Term__Context>(_ctx, getState());
  enterRule(_localctx, 102, ASPCore2Parser::RuleTerm__);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(429);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ASPCore2Parser::SYMBOLIC_CONSTANT:
      case ASPCore2Parser::VARIABLE:
      case ASPCore2Parser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(423);
        identifier();
        break;
      }

      case ASPCore2Parser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(424);
        match(ASPCore2Parser::NUMBER);
        break;
      }

      case ASPCore2Parser::PARAM_OPEN: {
        enterOuterAlt(_localctx, 3);
        setState(425);
        match(ASPCore2Parser::PARAM_OPEN);
        setState(426);
        term();
        setState(427);
        match(ASPCore2Parser::PARAM_CLOSE);
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

ASPCore2Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ASPCore2Parser::Term_Context* ASPCore2Parser::TermContext::term_() {
  return getRuleContext<ASPCore2Parser::Term_Context>(0);
}

ASPCore2Parser::ExprContext* ASPCore2Parser::TermContext::expr() {
  return getRuleContext<ASPCore2Parser::ExprContext>(0);
}


size_t ASPCore2Parser::TermContext::getRuleIndex() const {
  return ASPCore2Parser::RuleTerm;
}

void ASPCore2Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void ASPCore2Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

ASPCore2Parser::TermContext* ASPCore2Parser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 104, ASPCore2Parser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(431);
      term_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(432);
      expr();
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

//----------------- VarsContext ------------------------------------------------------------------

ASPCore2Parser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ASPCore2Parser::VarsContext::VARIABLE() {
  return getToken(ASPCore2Parser::VARIABLE, 0);
}

tree::TerminalNode* ASPCore2Parser::VarsContext::COMMA() {
  return getToken(ASPCore2Parser::COMMA, 0);
}

ASPCore2Parser::VarsContext* ASPCore2Parser::VarsContext::vars() {
  return getRuleContext<ASPCore2Parser::VarsContext>(0);
}


size_t ASPCore2Parser::VarsContext::getRuleIndex() const {
  return ASPCore2Parser::RuleVars;
}

void ASPCore2Parser::VarsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVars(this);
}

void ASPCore2Parser::VarsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ASPCore2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVars(this);
}

ASPCore2Parser::VarsContext* ASPCore2Parser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 106, ASPCore2Parser::RuleVars);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(439);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(435);
      match(ASPCore2Parser::VARIABLE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(436);
      match(ASPCore2Parser::VARIABLE);
      setState(437);
      match(ASPCore2Parser::COMMA);
      setState(438);
      vars();
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

void ASPCore2Parser::initialize() {
  std::call_once(aspcore2ParserOnceFlag, aspcore2ParserInitialize);
}
