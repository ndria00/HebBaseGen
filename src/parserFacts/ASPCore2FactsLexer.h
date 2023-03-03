
// Generated from ASPCore2Facts.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"




class  ASPCore2FactsLexer : public antlr4::Lexer {
public:
  enum {
    SYMBOLIC_CONSTANT = 1, STRING = 2, NUMBER = 3, WS = 4, DOT = 5, DDOT = 6, 
    COMMA = 7, HEAD_SEPARATOR = 8, COLON = 9, CONS = 10, PARAM_OPEN = 11, 
    PARAM_CLOSE = 12, ANON_VAR = 13, EMPTY_COMMENT = 14, COMMENT = 15
  };

  explicit ASPCore2FactsLexer(antlr4::CharStream *input);

  ~ASPCore2FactsLexer() override;


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

