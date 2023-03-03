
// Generated from ASPCore2Facts.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"




class  ASPCore2FactsParser : public antlr4::Parser {
public:
  enum {
    SYMBOLIC_CONSTANT = 1, STRING = 2, NUMBER = 3, WS = 4, DOT = 5, DDOT = 6, 
    COMMA = 7, HEAD_SEPARATOR = 8, COLON = 9, CONS = 10, PARAM_OPEN = 11, 
    PARAM_CLOSE = 12, ANON_VAR = 13, EMPTY_COMMENT = 14, COMMENT = 15
  };

  enum {
    RuleInstance = 0, RuleFact = 1, RuleHead = 2, RuleDisjunction = 3, RuleClassic_literal = 4, 
    RuleAtom = 5, RuleTerms = 6, RuleTerm_ = 7, RuleTerm = 8, RuleIdentifier = 9
  };

  explicit ASPCore2FactsParser(antlr4::TokenStream *input);

  ASPCore2FactsParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ASPCore2FactsParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class InstanceContext;
  class FactContext;
  class HeadContext;
  class DisjunctionContext;
  class Classic_literalContext;
  class AtomContext;
  class TermsContext;
  class Term_Context;
  class TermContext;
  class IdentifierContext; 

  class  InstanceContext : public antlr4::ParserRuleContext {
  public:
    InstanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactContext *> fact();
    FactContext* fact(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InstanceContext* instance();

  class  FactContext : public antlr4::ParserRuleContext {
  public:
    FactContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HeadContext *head();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactContext* fact();

  class  HeadContext : public antlr4::ParserRuleContext {
  public:
    HeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DisjunctionContext *disjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  HeadContext* head();

  class  DisjunctionContext : public antlr4::ParserRuleContext {
  public:
    DisjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Classic_literalContext *classic_literal();
    antlr4::tree::TerminalNode *HEAD_SEPARATOR();
    DisjunctionContext *disjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DisjunctionContext* disjunction();

  class  Classic_literalContext : public antlr4::ParserRuleContext {
  public:
    Classic_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Classic_literalContext* classic_literal();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *PARAM_OPEN();
    TermsContext *terms();
    antlr4::tree::TerminalNode *PARAM_CLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomContext* atom();

  class  TermsContext : public antlr4::ParserRuleContext {
  public:
    TermsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *COMMA();
    TermsContext *terms();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermsContext* terms();

  class  Term_Context : public antlr4::ParserRuleContext {
  public:
    Term_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANON_VAR();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *DDOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Term_Context* term_();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Term_Context *term_();
    antlr4::tree::TerminalNode *NUMBER();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOLIC_CONSTANT();
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdentifierContext* identifier();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

