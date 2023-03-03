
// Generated from ASPCore2Facts.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "ASPCore2FactsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ASPCore2FactsParser.
 */
class  ASPCore2FactsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterInstance(ASPCore2FactsParser::InstanceContext *ctx) = 0;
  virtual void exitInstance(ASPCore2FactsParser::InstanceContext *ctx) = 0;

  virtual void enterFact(ASPCore2FactsParser::FactContext *ctx) = 0;
  virtual void exitFact(ASPCore2FactsParser::FactContext *ctx) = 0;

  virtual void enterHead(ASPCore2FactsParser::HeadContext *ctx) = 0;
  virtual void exitHead(ASPCore2FactsParser::HeadContext *ctx) = 0;

  virtual void enterDisjunction(ASPCore2FactsParser::DisjunctionContext *ctx) = 0;
  virtual void exitDisjunction(ASPCore2FactsParser::DisjunctionContext *ctx) = 0;

  virtual void enterClassic_literal(ASPCore2FactsParser::Classic_literalContext *ctx) = 0;
  virtual void exitClassic_literal(ASPCore2FactsParser::Classic_literalContext *ctx) = 0;

  virtual void enterAtom(ASPCore2FactsParser::AtomContext *ctx) = 0;
  virtual void exitAtom(ASPCore2FactsParser::AtomContext *ctx) = 0;

  virtual void enterTerms(ASPCore2FactsParser::TermsContext *ctx) = 0;
  virtual void exitTerms(ASPCore2FactsParser::TermsContext *ctx) = 0;

  virtual void enterTerm_(ASPCore2FactsParser::Term_Context *ctx) = 0;
  virtual void exitTerm_(ASPCore2FactsParser::Term_Context *ctx) = 0;

  virtual void enterTerm(ASPCore2FactsParser::TermContext *ctx) = 0;
  virtual void exitTerm(ASPCore2FactsParser::TermContext *ctx) = 0;

  virtual void enterIdentifier(ASPCore2FactsParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(ASPCore2FactsParser::IdentifierContext *ctx) = 0;


};

