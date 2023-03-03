
// Generated from ASPCore2Facts.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "ASPCore2FactsListener.h"


/**
 * This class provides an empty implementation of ASPCore2FactsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ASPCore2FactsBaseListener : public ASPCore2FactsListener {
public:

  virtual void enterInstance(ASPCore2FactsParser::InstanceContext * /*ctx*/) override { }
  virtual void exitInstance(ASPCore2FactsParser::InstanceContext * /*ctx*/) override { }

  virtual void enterFact(ASPCore2FactsParser::FactContext * /*ctx*/) override { }
  virtual void exitFact(ASPCore2FactsParser::FactContext * /*ctx*/) override { }

  virtual void enterHead(ASPCore2FactsParser::HeadContext * /*ctx*/) override { }
  virtual void exitHead(ASPCore2FactsParser::HeadContext * /*ctx*/) override { }

  virtual void enterDisjunction(ASPCore2FactsParser::DisjunctionContext * /*ctx*/) override { }
  virtual void exitDisjunction(ASPCore2FactsParser::DisjunctionContext * /*ctx*/) override { }

  virtual void enterClassic_literal(ASPCore2FactsParser::Classic_literalContext * /*ctx*/) override { }
  virtual void exitClassic_literal(ASPCore2FactsParser::Classic_literalContext * /*ctx*/) override { }

  virtual void enterAtom(ASPCore2FactsParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(ASPCore2FactsParser::AtomContext * /*ctx*/) override { }

  virtual void enterTerms(ASPCore2FactsParser::TermsContext * /*ctx*/) override { }
  virtual void exitTerms(ASPCore2FactsParser::TermsContext * /*ctx*/) override { }

  virtual void enterTerm_(ASPCore2FactsParser::Term_Context * /*ctx*/) override { }
  virtual void exitTerm_(ASPCore2FactsParser::Term_Context * /*ctx*/) override { }

  virtual void enterTerm(ASPCore2FactsParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(ASPCore2FactsParser::TermContext * /*ctx*/) override { }

  virtual void enterIdentifier(ASPCore2FactsParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(ASPCore2FactsParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

