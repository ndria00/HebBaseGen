#ifndef FUNCTIONALTERM_H
#define FUNCTIONALTERM_H

#include "TermBase.h"
#include <iostream>
class FunctionalTerm: public TermBase{
    private:
        std::string identifier;
        std::vector<TermBase*> terms;
    public:
        FunctionalTerm();
        virtual const std::string& getValue()const override;
        virtual void setValue(std::string&) override;
        virtual void print() const override;
        virtual bool isVariable()const override;
        virtual void setVariable(bool) override;
        virtual void getAllVariables(std::unordered_set<std::string>&) override;
        virtual void removeSafeVariables(std::unordered_set<std::string>&) override;
        void addTerm(TermBase*);
        std::string getFunctionName()const;
        const std::vector<TermBase*>& getTerms()const;
        void setFunctionName(std::string);
        virtual std::string getRepresentation()const override;
        ~FunctionalTerm();
};
#endif