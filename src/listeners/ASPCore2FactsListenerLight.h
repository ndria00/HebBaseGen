#ifndef ASPCORE2FACTSLISTENERLIGHT_H
#define ASPCORE2FACTSLISTENERLIGHT_H
#include "../parserFacts/ASPCore2FactsBaseListener.h"
#include "../ASP2CPP/Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../parserFacts/ASPCore2FactsLexer.h"
#include "../parserFacts/ASPCore2FactsParser.h"
#include "../antlr4-runtime.h"
#include <climits>

const int NOT_ENCODING_ATOM = -2;
const int NO_NAME = -1;
const int INTERVAL = INT_MAX;

class ASPCore2FactsListenerLight : public ASPCore2FactsBaseListener{
  
  public:
    ASPCore2FactsListenerLight(Executor*);

    //void enterFact(ASPCore2FactsParser::FactContext * /*ctx*/) override;
    void exitFact(ASPCore2FactsParser::FactContext * /*ctx*/) override;
    
    void enterAtom(ASPCore2FactsParser::AtomContext * /*ctx*/) override;
    //void exitAtom(ASPCore2FactsParser::AtomContext * /*ctx*/) override;

    void enterTerm(ASPCore2FactsParser::TermContext * /*ctx*/) override;
    //void exitTerm(ASPCore2FactsParser::TermContext * /*ctx*/) override;

    //void enterTerm_(ASPCore2FactsParser::Term_Context * /*ctx*/) override;
    //void exitTerm_(ASPCore2FactsParser::Term_Context * /*ctx*/) override;
    void enterIdentifier(ASPCore2FactsParser::IdentifierContext * /*ctx*/) override;

    private:
        Executor* executor;
        bool disjunctiveFact;
        int atomName;
        int atomInsideRule;
        std::vector<int> terms;
        std::unordered_map<int, std::pair<int, int>> intervalIndexAndRanges;
        std::string nonEncodingAtomName;
};

#endif /*ASPCORE2FACTSLISTENERLIGHT_H*/