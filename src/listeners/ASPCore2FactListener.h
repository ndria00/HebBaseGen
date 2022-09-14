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
        //void enterIdentifier(ASPCore2Parser::IdentifierContext * /*ctx*/) override;
        void enterTerm(ASPCore2Parser::TermContext * /*ctx*/) override;
        // void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override;

    private:
        Executor* executor;
        bool disjunctiveFact;
        int atomName;
        std::vector<int> terms;
};
#endif /*ASPCORE2FACTLISTENER_H*/