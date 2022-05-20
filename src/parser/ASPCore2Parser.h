
// Generated from ../ASPCore2.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  ASPCore2Parser : public antlr4::Parser {
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

  enum {
    RuleProgram = 0, RuleRule = 1, RuleSimple_rule = 2, RuleHead = 3, RuleBody = 4, 
    RuleWeight_at_levels = 5, RuleLevels_and_terms = 6, RuleDisjunction = 7, 
    RuleConjunction = 8, RuleClassic_literal = 9, RuleNaf_literals = 10, 
    RuleNaf_literal = 11, RuleNaf_literal_aggregate = 12, RuleExistential_atom = 13, 
    RuleAtom = 14, RuleExtAtom = 15, RuleExtSemicol = 16, RuleIdentifier = 17, 
    RuleQuery = 18, RuleLower_guard_compare_aggregate = 19, RuleUpper_guard_compare_aggregate = 20, 
    RuleCompare_aggregate = 21, RuleLower_guard_leftward_left_aggregate = 22, 
    RuleLeftward_left_aggregate = 23, RuleLeft_aggregate = 24, RuleLower_guard_rightward_left_aggregate = 25, 
    RuleRightward_left_aggregate = 26, RuleUpper_guard_leftward_right_aggregate = 27, 
    RuleUpper_guard_rightward_right_aggregate = 28, RuleRight_aggregate = 29, 
    RuleAggregate_atom = 30, RuleLeftwardop = 31, RuleRightwardop = 32, 
    RuleAggregate = 33, RuleAggregate_elements = 34, RuleAggregate_element = 35, 
    RuleAggregate_function = 36, RuleTerms = 37, RuleBasic_terms = 38, RuleBuiltin_atom = 39, 
    RuleCompareop = 40, RuleBinop = 41, RuleFactor = 42, RuleBasic_term = 43, 
    RuleGround_term = 44, RuleVariable_term = 45, RuleFunctional_term = 46, 
    RuleExpr = 47, RuleArithop2 = 48, RuleArithop1 = 49, RuleTerm_ = 50, 
    RuleTerm__ = 51, RuleTerm = 52, RuleVars = 53
  };

  explicit ASPCore2Parser(antlr4::TokenStream *input);

  ASPCore2Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ASPCore2Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class RuleContext;
  class Simple_ruleContext;
  class HeadContext;
  class BodyContext;
  class Weight_at_levelsContext;
  class Levels_and_termsContext;
  class DisjunctionContext;
  class ConjunctionContext;
  class Classic_literalContext;
  class Naf_literalsContext;
  class Naf_literalContext;
  class Naf_literal_aggregateContext;
  class Existential_atomContext;
  class AtomContext;
  class ExtAtomContext;
  class ExtSemicolContext;
  class IdentifierContext;
  class QueryContext;
  class Lower_guard_compare_aggregateContext;
  class Upper_guard_compare_aggregateContext;
  class Compare_aggregateContext;
  class Lower_guard_leftward_left_aggregateContext;
  class Leftward_left_aggregateContext;
  class Left_aggregateContext;
  class Lower_guard_rightward_left_aggregateContext;
  class Rightward_left_aggregateContext;
  class Upper_guard_leftward_right_aggregateContext;
  class Upper_guard_rightward_right_aggregateContext;
  class Right_aggregateContext;
  class Aggregate_atomContext;
  class LeftwardopContext;
  class RightwardopContext;
  class AggregateContext;
  class Aggregate_elementsContext;
  class Aggregate_elementContext;
  class Aggregate_functionContext;
  class TermsContext;
  class Basic_termsContext;
  class Builtin_atomContext;
  class CompareopContext;
  class BinopContext;
  class FactorContext;
  class Basic_termContext;
  class Ground_termContext;
  class Variable_termContext;
  class Functional_termContext;
  class ExprContext;
  class Arithop2Context;
  class Arithop1Context;
  class Term_Context;
  class Term__Context;
  class TermContext;
  class VarsContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ASPCore2Parser::RuleContext *> rule_();
    ASPCore2Parser::RuleContext* rule_(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  RuleContext : public antlr4::ParserRuleContext {
  public:
    RuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_ruleContext *simple_rule();
    QueryContext *query();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleContext* rule_();

  class  Simple_ruleContext : public antlr4::ParserRuleContext {
  public:
    Simple_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HeadContext *head();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *CONS();
    BodyContext *body();
    antlr4::tree::TerminalNode *WCONS();
    Weight_at_levelsContext *weight_at_levels();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_ruleContext* simple_rule();

  class  HeadContext : public antlr4::ParserRuleContext {
  public:
    HeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DisjunctionContext *disjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  HeadContext* head();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConjunctionContext *conjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BodyContext* body();

  class  Weight_at_levelsContext : public antlr4::ParserRuleContext {
  public:
    Weight_at_levelsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SQUARE_OPEN();
    TermContext *term();
    antlr4::tree::TerminalNode *SQUARE_CLOSED();
    Levels_and_termsContext *levels_and_terms();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Weight_at_levelsContext* weight_at_levels();

  class  Levels_and_termsContext : public antlr4::ParserRuleContext {
  public:
    Levels_and_termsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    TermContext *term();
    antlr4::tree::TerminalNode *COMMA();
    TermsContext *terms();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Levels_and_termsContext* levels_and_terms();

  class  DisjunctionContext : public antlr4::ParserRuleContext {
  public:
    DisjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Classic_literalContext *classic_literal();
    antlr4::tree::TerminalNode *HEAD_SEPARATOR();
    DisjunctionContext *disjunction();
    Existential_atomContext *existential_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DisjunctionContext* disjunction();

  class  ConjunctionContext : public antlr4::ParserRuleContext {
  public:
    ConjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Naf_literal_aggregateContext *naf_literal_aggregate();
    antlr4::tree::TerminalNode *COMMA();
    ConjunctionContext *conjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConjunctionContext* conjunction();

  class  Classic_literalContext : public antlr4::ParserRuleContext {
  public:
    Classic_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *DASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Classic_literalContext* classic_literal();

  class  Naf_literalsContext : public antlr4::ParserRuleContext {
  public:
    Naf_literalsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Naf_literalContext *naf_literal();
    antlr4::tree::TerminalNode *COMMA();
    Naf_literalsContext *naf_literals();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Naf_literalsContext* naf_literals();

  class  Naf_literalContext : public antlr4::ParserRuleContext {
  public:
    Naf_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Classic_literalContext *classic_literal();
    antlr4::tree::TerminalNode *NAF();
    Builtin_atomContext *builtin_atom();
    ExtAtomContext *extAtom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Naf_literalContext* naf_literal();

  class  Naf_literal_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Naf_literal_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Naf_literalContext *naf_literal();
    Aggregate_atomContext *aggregate_atom();
    antlr4::tree::TerminalNode *NAF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Naf_literal_aggregateContext* naf_literal_aggregate();

  class  Existential_atomContext : public antlr4::ParserRuleContext {
  public:
    Existential_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXISTS();
    VarsContext *vars();
    AtomContext *atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Existential_atomContext* existential_atom();

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

  class  ExtAtomContext : public antlr4::ParserRuleContext {
  public:
    ExtAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AMPERSAND();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *PARAM_OPEN();
    std::vector<TermsContext *> terms();
    TermsContext* terms(size_t i);
    ExtSemicolContext *extSemicol();
    antlr4::tree::TerminalNode *PARAM_CLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExtAtomContext* extAtom();

  class  ExtSemicolContext : public antlr4::ParserRuleContext {
  public:
    ExtSemicolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExtSemicolContext* extSemicol();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOLIC_CONSTANT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdentifierContext* identifier();

  class  QueryContext : public antlr4::ParserRuleContext {
  public:
    QueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomContext *atom();
    antlr4::tree::TerminalNode *QUERY_MARK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QueryContext* query();

  class  Lower_guard_compare_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Lower_guard_compare_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    CompareopContext *compareop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lower_guard_compare_aggregateContext* lower_guard_compare_aggregate();

  class  Upper_guard_compare_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Upper_guard_compare_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompareopContext *compareop();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Upper_guard_compare_aggregateContext* upper_guard_compare_aggregate();

  class  Compare_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Compare_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lower_guard_compare_aggregateContext *lower_guard_compare_aggregate();
    AggregateContext *aggregate();
    Upper_guard_compare_aggregateContext *upper_guard_compare_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compare_aggregateContext* compare_aggregate();

  class  Lower_guard_leftward_left_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Lower_guard_leftward_left_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    LeftwardopContext *leftwardop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lower_guard_leftward_left_aggregateContext* lower_guard_leftward_left_aggregate();

  class  Leftward_left_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Leftward_left_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lower_guard_leftward_left_aggregateContext *lower_guard_leftward_left_aggregate();
    AggregateContext *aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Leftward_left_aggregateContext* leftward_left_aggregate();

  class  Left_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Left_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Leftward_left_aggregateContext *leftward_left_aggregate();
    Rightward_left_aggregateContext *rightward_left_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Left_aggregateContext* left_aggregate();

  class  Lower_guard_rightward_left_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Lower_guard_rightward_left_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    RightwardopContext *rightwardop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Lower_guard_rightward_left_aggregateContext* lower_guard_rightward_left_aggregate();

  class  Rightward_left_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Rightward_left_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Lower_guard_rightward_left_aggregateContext *lower_guard_rightward_left_aggregate();
    AggregateContext *aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rightward_left_aggregateContext* rightward_left_aggregate();

  class  Upper_guard_leftward_right_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Upper_guard_leftward_right_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LeftwardopContext *leftwardop();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Upper_guard_leftward_right_aggregateContext* upper_guard_leftward_right_aggregate();

  class  Upper_guard_rightward_right_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Upper_guard_rightward_right_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RightwardopContext *rightwardop();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Upper_guard_rightward_right_aggregateContext* upper_guard_rightward_right_aggregate();

  class  Right_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Right_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AggregateContext *aggregate();
    Upper_guard_leftward_right_aggregateContext *upper_guard_leftward_right_aggregate();
    Upper_guard_rightward_right_aggregateContext *upper_guard_rightward_right_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Right_aggregateContext* right_aggregate();

  class  Aggregate_atomContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Left_aggregateContext *left_aggregate();
    Right_aggregateContext *right_aggregate();
    Compare_aggregateContext *compare_aggregate();
    Leftward_left_aggregateContext *leftward_left_aggregate();
    Upper_guard_leftward_right_aggregateContext *upper_guard_leftward_right_aggregate();
    Rightward_left_aggregateContext *rightward_left_aggregate();
    Upper_guard_rightward_right_aggregateContext *upper_guard_rightward_right_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aggregate_atomContext* aggregate_atom();

  class  LeftwardopContext : public antlr4::ParserRuleContext {
  public:
    LeftwardopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_OR_EQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LeftwardopContext* leftwardop();

  class  RightwardopContext : public antlr4::ParserRuleContext {
  public:
    RightwardopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *GREATER_OR_EQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RightwardopContext* rightwardop();

  class  AggregateContext : public antlr4::ParserRuleContext {
  public:
    AggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Aggregate_functionContext *aggregate_function();
    antlr4::tree::TerminalNode *CURLY_OPEN();
    Aggregate_elementsContext *aggregate_elements();
    antlr4::tree::TerminalNode *CURLY_CLOSED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AggregateContext* aggregate();

  class  Aggregate_elementsContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_elementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Aggregate_elementContext *aggregate_element();
    antlr4::tree::TerminalNode *SEMICOLON();
    Aggregate_elementsContext *aggregate_elements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aggregate_elementsContext* aggregate_elements();

  class  Aggregate_elementContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_termsContext *basic_terms();
    antlr4::tree::TerminalNode *COLON();
    Naf_literalsContext *naf_literals();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aggregate_elementContext* aggregate_element();

  class  Aggregate_functionContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AGGR_COUNT();
    antlr4::tree::TerminalNode *AGGR_MAX();
    antlr4::tree::TerminalNode *AGGR_MIN();
    antlr4::tree::TerminalNode *AGGR_SUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aggregate_functionContext* aggregate_function();

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

  class  Basic_termsContext : public antlr4::ParserRuleContext {
  public:
    Basic_termsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_termContext *basic_term();
    antlr4::tree::TerminalNode *COMMA();
    Basic_termsContext *basic_terms();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Basic_termsContext* basic_terms();

  class  Builtin_atomContext : public antlr4::ParserRuleContext {
  public:
    Builtin_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    BinopContext *binop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Builtin_atomContext* builtin_atom();

  class  CompareopContext : public antlr4::ParserRuleContext {
  public:
    CompareopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *UNEQUAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompareopContext* compareop();

  class  BinopContext : public antlr4::ParserRuleContext {
  public:
    BinopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompareopContext *compareop();
    LeftwardopContext *leftwardop();
    RightwardopContext *rightwardop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinopContext* binop();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Term__Context *term__();
    Arithop2Context *arithop2();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Basic_termContext : public antlr4::ParserRuleContext {
  public:
    Basic_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ground_termContext *ground_term();
    Variable_termContext *variable_term();
    Functional_termContext *functional_term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Basic_termContext* basic_term();

  class  Ground_termContext : public antlr4::ParserRuleContext {
  public:
    Ground_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYMBOLIC_CONSTANT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *DASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ground_termContext* ground_term();

  class  Variable_termContext : public antlr4::ParserRuleContext {
  public:
    Variable_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *ANON_VAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_termContext* variable_term();

  class  Functional_termContext : public antlr4::ParserRuleContext {
  public:
    Functional_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *PARAM_OPEN();
    TermsContext *terms();
    antlr4::tree::TerminalNode *PARAM_CLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Functional_termContext* functional_term();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    Arithop1Context *arithop1();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();

  class  Arithop2Context : public antlr4::ParserRuleContext {
  public:
    Arithop2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *BACK_SLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arithop2Context* arithop2();

  class  Arithop1Context : public antlr4::ParserRuleContext {
  public:
    Arithop1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *DASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arithop1Context* arithop1();

  class  Term_Context : public antlr4::ParserRuleContext {
  public:
    Term_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANON_VAR();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *PARAM_OPEN();
    TermsContext *terms();
    antlr4::tree::TerminalNode *PARAM_CLOSE();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *DDOT();
    antlr4::tree::TerminalNode *DASH();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Term_Context* term_();

  class  Term__Context : public antlr4::ParserRuleContext {
  public:
    Term__Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *PARAM_OPEN();
    TermContext *term();
    antlr4::tree::TerminalNode *PARAM_CLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Term__Context* term__();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Term_Context *term_();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();

  class  VarsContext : public antlr4::ParserRuleContext {
  public:
    VarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *COMMA();
    VarsContext *vars();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarsContext* vars();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

