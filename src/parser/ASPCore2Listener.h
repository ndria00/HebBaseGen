
// Generated from ../ASPCore2.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ASPCore2Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ASPCore2Parser.
 */
class  ASPCore2Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ASPCore2Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ASPCore2Parser::ProgramContext *ctx) = 0;

  virtual void enterRule(ASPCore2Parser::RuleContext *ctx) = 0;
  virtual void exitRule(ASPCore2Parser::RuleContext *ctx) = 0;

  virtual void enterSimple_rule(ASPCore2Parser::Simple_ruleContext *ctx) = 0;
  virtual void exitSimple_rule(ASPCore2Parser::Simple_ruleContext *ctx) = 0;

  virtual void enterHead(ASPCore2Parser::HeadContext *ctx) = 0;
  virtual void exitHead(ASPCore2Parser::HeadContext *ctx) = 0;

  virtual void enterBody(ASPCore2Parser::BodyContext *ctx) = 0;
  virtual void exitBody(ASPCore2Parser::BodyContext *ctx) = 0;

  virtual void enterWeight_at_levels(ASPCore2Parser::Weight_at_levelsContext *ctx) = 0;
  virtual void exitWeight_at_levels(ASPCore2Parser::Weight_at_levelsContext *ctx) = 0;

  virtual void enterLevels_and_terms(ASPCore2Parser::Levels_and_termsContext *ctx) = 0;
  virtual void exitLevels_and_terms(ASPCore2Parser::Levels_and_termsContext *ctx) = 0;

  virtual void enterDisjunction(ASPCore2Parser::DisjunctionContext *ctx) = 0;
  virtual void exitDisjunction(ASPCore2Parser::DisjunctionContext *ctx) = 0;

  virtual void enterConjunction(ASPCore2Parser::ConjunctionContext *ctx) = 0;
  virtual void exitConjunction(ASPCore2Parser::ConjunctionContext *ctx) = 0;

  virtual void enterClassic_literal(ASPCore2Parser::Classic_literalContext *ctx) = 0;
  virtual void exitClassic_literal(ASPCore2Parser::Classic_literalContext *ctx) = 0;

  virtual void enterNaf_literals(ASPCore2Parser::Naf_literalsContext *ctx) = 0;
  virtual void exitNaf_literals(ASPCore2Parser::Naf_literalsContext *ctx) = 0;

  virtual void enterNaf_literal(ASPCore2Parser::Naf_literalContext *ctx) = 0;
  virtual void exitNaf_literal(ASPCore2Parser::Naf_literalContext *ctx) = 0;

  virtual void enterNaf_literal_aggregate(ASPCore2Parser::Naf_literal_aggregateContext *ctx) = 0;
  virtual void exitNaf_literal_aggregate(ASPCore2Parser::Naf_literal_aggregateContext *ctx) = 0;

  virtual void enterExistential_atom(ASPCore2Parser::Existential_atomContext *ctx) = 0;
  virtual void exitExistential_atom(ASPCore2Parser::Existential_atomContext *ctx) = 0;

  virtual void enterAtom(ASPCore2Parser::AtomContext *ctx) = 0;
  virtual void exitAtom(ASPCore2Parser::AtomContext *ctx) = 0;

  virtual void enterExtAtom(ASPCore2Parser::ExtAtomContext *ctx) = 0;
  virtual void exitExtAtom(ASPCore2Parser::ExtAtomContext *ctx) = 0;

  virtual void enterExtSemicol(ASPCore2Parser::ExtSemicolContext *ctx) = 0;
  virtual void exitExtSemicol(ASPCore2Parser::ExtSemicolContext *ctx) = 0;

  virtual void enterIdentifier(ASPCore2Parser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(ASPCore2Parser::IdentifierContext *ctx) = 0;

  virtual void enterQuery(ASPCore2Parser::QueryContext *ctx) = 0;
  virtual void exitQuery(ASPCore2Parser::QueryContext *ctx) = 0;

  virtual void enterLower_guard_compare_aggregate(ASPCore2Parser::Lower_guard_compare_aggregateContext *ctx) = 0;
  virtual void exitLower_guard_compare_aggregate(ASPCore2Parser::Lower_guard_compare_aggregateContext *ctx) = 0;

  virtual void enterUpper_guard_compare_aggregate(ASPCore2Parser::Upper_guard_compare_aggregateContext *ctx) = 0;
  virtual void exitUpper_guard_compare_aggregate(ASPCore2Parser::Upper_guard_compare_aggregateContext *ctx) = 0;

  virtual void enterCompare_aggregate(ASPCore2Parser::Compare_aggregateContext *ctx) = 0;
  virtual void exitCompare_aggregate(ASPCore2Parser::Compare_aggregateContext *ctx) = 0;

  virtual void enterLower_guard_leftward_left_aggregate(ASPCore2Parser::Lower_guard_leftward_left_aggregateContext *ctx) = 0;
  virtual void exitLower_guard_leftward_left_aggregate(ASPCore2Parser::Lower_guard_leftward_left_aggregateContext *ctx) = 0;

  virtual void enterLeftward_left_aggregate(ASPCore2Parser::Leftward_left_aggregateContext *ctx) = 0;
  virtual void exitLeftward_left_aggregate(ASPCore2Parser::Leftward_left_aggregateContext *ctx) = 0;

  virtual void enterLeft_aggregate(ASPCore2Parser::Left_aggregateContext *ctx) = 0;
  virtual void exitLeft_aggregate(ASPCore2Parser::Left_aggregateContext *ctx) = 0;

  virtual void enterLower_guard_rightward_left_aggregate(ASPCore2Parser::Lower_guard_rightward_left_aggregateContext *ctx) = 0;
  virtual void exitLower_guard_rightward_left_aggregate(ASPCore2Parser::Lower_guard_rightward_left_aggregateContext *ctx) = 0;

  virtual void enterRightward_left_aggregate(ASPCore2Parser::Rightward_left_aggregateContext *ctx) = 0;
  virtual void exitRightward_left_aggregate(ASPCore2Parser::Rightward_left_aggregateContext *ctx) = 0;

  virtual void enterUpper_guard_leftward_right_aggregate(ASPCore2Parser::Upper_guard_leftward_right_aggregateContext *ctx) = 0;
  virtual void exitUpper_guard_leftward_right_aggregate(ASPCore2Parser::Upper_guard_leftward_right_aggregateContext *ctx) = 0;

  virtual void enterUpper_guard_rightward_right_aggregate(ASPCore2Parser::Upper_guard_rightward_right_aggregateContext *ctx) = 0;
  virtual void exitUpper_guard_rightward_right_aggregate(ASPCore2Parser::Upper_guard_rightward_right_aggregateContext *ctx) = 0;

  virtual void enterRight_aggregate(ASPCore2Parser::Right_aggregateContext *ctx) = 0;
  virtual void exitRight_aggregate(ASPCore2Parser::Right_aggregateContext *ctx) = 0;

  virtual void enterAggregate_atom(ASPCore2Parser::Aggregate_atomContext *ctx) = 0;
  virtual void exitAggregate_atom(ASPCore2Parser::Aggregate_atomContext *ctx) = 0;

  virtual void enterLeftwardop(ASPCore2Parser::LeftwardopContext *ctx) = 0;
  virtual void exitLeftwardop(ASPCore2Parser::LeftwardopContext *ctx) = 0;

  virtual void enterRightwardop(ASPCore2Parser::RightwardopContext *ctx) = 0;
  virtual void exitRightwardop(ASPCore2Parser::RightwardopContext *ctx) = 0;

  virtual void enterAggregate(ASPCore2Parser::AggregateContext *ctx) = 0;
  virtual void exitAggregate(ASPCore2Parser::AggregateContext *ctx) = 0;

  virtual void enterAggregate_elements(ASPCore2Parser::Aggregate_elementsContext *ctx) = 0;
  virtual void exitAggregate_elements(ASPCore2Parser::Aggregate_elementsContext *ctx) = 0;

  virtual void enterAggregate_element(ASPCore2Parser::Aggregate_elementContext *ctx) = 0;
  virtual void exitAggregate_element(ASPCore2Parser::Aggregate_elementContext *ctx) = 0;

  virtual void enterAggregate_function(ASPCore2Parser::Aggregate_functionContext *ctx) = 0;
  virtual void exitAggregate_function(ASPCore2Parser::Aggregate_functionContext *ctx) = 0;

  virtual void enterTerms(ASPCore2Parser::TermsContext *ctx) = 0;
  virtual void exitTerms(ASPCore2Parser::TermsContext *ctx) = 0;

  virtual void enterBasic_terms(ASPCore2Parser::Basic_termsContext *ctx) = 0;
  virtual void exitBasic_terms(ASPCore2Parser::Basic_termsContext *ctx) = 0;

  virtual void enterBuiltin_atom(ASPCore2Parser::Builtin_atomContext *ctx) = 0;
  virtual void exitBuiltin_atom(ASPCore2Parser::Builtin_atomContext *ctx) = 0;

  virtual void enterCompareop(ASPCore2Parser::CompareopContext *ctx) = 0;
  virtual void exitCompareop(ASPCore2Parser::CompareopContext *ctx) = 0;

  virtual void enterBinop(ASPCore2Parser::BinopContext *ctx) = 0;
  virtual void exitBinop(ASPCore2Parser::BinopContext *ctx) = 0;

  virtual void enterFactor(ASPCore2Parser::FactorContext *ctx) = 0;
  virtual void exitFactor(ASPCore2Parser::FactorContext *ctx) = 0;

  virtual void enterBasic_term(ASPCore2Parser::Basic_termContext *ctx) = 0;
  virtual void exitBasic_term(ASPCore2Parser::Basic_termContext *ctx) = 0;

  virtual void enterGround_term(ASPCore2Parser::Ground_termContext *ctx) = 0;
  virtual void exitGround_term(ASPCore2Parser::Ground_termContext *ctx) = 0;

  virtual void enterVariable_term(ASPCore2Parser::Variable_termContext *ctx) = 0;
  virtual void exitVariable_term(ASPCore2Parser::Variable_termContext *ctx) = 0;

  virtual void enterFunctional_term(ASPCore2Parser::Functional_termContext *ctx) = 0;
  virtual void exitFunctional_term(ASPCore2Parser::Functional_termContext *ctx) = 0;

  virtual void enterExpr(ASPCore2Parser::ExprContext *ctx) = 0;
  virtual void exitExpr(ASPCore2Parser::ExprContext *ctx) = 0;

  virtual void enterArithop2(ASPCore2Parser::Arithop2Context *ctx) = 0;
  virtual void exitArithop2(ASPCore2Parser::Arithop2Context *ctx) = 0;

  virtual void enterArithop1(ASPCore2Parser::Arithop1Context *ctx) = 0;
  virtual void exitArithop1(ASPCore2Parser::Arithop1Context *ctx) = 0;

  virtual void enterTerm_(ASPCore2Parser::Term_Context *ctx) = 0;
  virtual void exitTerm_(ASPCore2Parser::Term_Context *ctx) = 0;

  virtual void enterTerm__(ASPCore2Parser::Term__Context *ctx) = 0;
  virtual void exitTerm__(ASPCore2Parser::Term__Context *ctx) = 0;

  virtual void enterTerm(ASPCore2Parser::TermContext *ctx) = 0;
  virtual void exitTerm(ASPCore2Parser::TermContext *ctx) = 0;

  virtual void enterVars(ASPCore2Parser::VarsContext *ctx) = 0;
  virtual void exitVars(ASPCore2Parser::VarsContext *ctx) = 0;


};

