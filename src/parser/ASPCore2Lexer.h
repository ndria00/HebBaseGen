
// Generated from ../ASPCore2.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  ASPCore2Lexer : public antlr4::Lexer {
public:
  enum {
    NAF = 1, COMMENT_EMPTY = 2, COMMENT = 3, SYMBOLIC_CONSTANT = 4, VARIABLE = 5, 
    STRING = 6, NUMBER = 7, WS = 8, DOT = 9, DDOT = 10, COMMA = 11, HEAD_SEPARATOR = 12, 
    SEMICOLON = 13, COLON = 14, AT = 15, CONS = 16, WCONS = 17, PLUS = 18, 
    DASH = 19, TIMES = 20, SLASH = 21, BACK_SLASH = 22, PARAM_OPEN = 23, 
    PARAM_CLOSE = 24, SQUARE_OPEN = 25, SQUARE_CLOSED = 26, CURLY_OPEN = 27, 
    CURLY_CLOSED = 28, QUERY_MARK = 29, ANON_VAR = 30, EQUAL = 31, UNEQUAL = 32, 
    LESS = 33, GREATER = 34, LESS_OR_EQ = 35, GREATER_OR_EQ = 36, AMPERSAND = 37, 
    EXISTS = 38, AGGR_COUNT = 39, AGGR_MAX = 40, AGGR_MIN = 41, AGGR_SUM = 42
  };

  explicit ASPCore2Lexer(antlr4::CharStream *input);

  ~ASPCore2Lexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

