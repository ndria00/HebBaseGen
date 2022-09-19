#ifndef ASPCORE2FACTLISTENER_H
#define ASPCORE2FACTLISTENER_H
#include "../parser/ASPCore2BaseListener.h"
#include "../ASP2CPP/Executor.h"
#include "../DataStructures/ConstantsManager.h"

class ASPCore2FactListener : public ASPCore2BaseListener{
    public:
        ASPCore2FactListener(Executor*);
        void enterHead(ASPCore2Parser::HeadContext * /*ctx*/) override;
        void enterAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
        void exitAtom(ASPCore2Parser::AtomContext * /*ctx*/) override;
        void exitHead(ASPCore2Parser::HeadContext * /*ctx*/) override;
        void enterTerm(ASPCore2Parser::TermContext * /*ctx*/) override;
        void enterTerm_(ASPCore2Parser::Term_Context * /*ctx*/) override;
        void bindTerms(int, std::vector<int>&, std::string&);
    private:
        Executor* executor;
        bool disjunctiveFact;
        int atomName;
        int atomArity;
        std::vector<int> terms;
        std::unordered_map<std::string, std::pair<int, int>> indexAndRange;
};
#endif /*ASPCORE2FACTLISTENER_H*/