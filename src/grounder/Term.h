#ifndef TERM_H_
#define TERM_H_
#include <string>
#include <vector>
#include "TermBase.h"

class Term : public TermBase{
    private:
        std::string value;
        bool variable;
    public:
        Term();
        Term(std::string&);
        virtual const std::string& getValue()const override;
        virtual void setValue(std::string&) override;
        virtual void print()const override;
        virtual bool isVariable()const override;
        virtual void setVariable(bool) override;
        virtual void getAllVariables(std::set<std::string>&) override;
        virtual void removeSafeVariables(std::set<std::string>&) override;
        ~Term();
};
#endif