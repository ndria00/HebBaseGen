#ifndef ASPCORE2FACTLISTENERNOTREE_H
#define ASPCORE2FACTLISTENERNOTREE_H
#include "../parser/ASPCore2BaseListener.h"
#include "../ASP2CPP/Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../parser/ASPCore2Lexer.h"
#include "../parser/ASPCore2Parser.h"
#include "../antlr4-runtime.h"
#include <climits>
const int NOT_ENCODING_ATOM = -2;
const int NO_NAME = -1;
const int INTERVAL = INT_MAX;

class ASPCore2FactListenerNoTree : public ASPCore2BaseListener{
    public:
        ASPCore2FactListenerNoTree(Executor* , antlr4::CommonTokenStream*);
        ASPCore2FactListenerNoTree(Executor*);
        void setTokenStream(antlr4::CommonTokenStream*);
        void enterSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/) override;
        void exitSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/) override;
        void enterAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
        void exitAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
        void enterTerm(ASPCore2Parser::TermContext * /*ctx*/) override;
        void enterTerm_(ASPCore2Parser::Term_Context * /*ctx*/) override;
        void enterIdentifier(ASPCore2Parser::IdentifierContext * /*ctx*/) override;
        void bindTermsAndAddToFactory();
    private:
        Executor* executor;
        bool disjunctiveFact;
        int atomName;
        int atomArity;
        int atomInsideRule;
        std::vector<int> terms;
        std::unordered_map<int, std::pair<int, int>> intervalIndexAndRanges;
        std::string nonEncodingAtomName;
        antlr4::CommonTokenStream* myTokens;
};
#endif /*ASPCORE2FACTLISTENERNOTREE_H*/