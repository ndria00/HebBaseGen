#ifndef TERM_H_
#define TERM_H_
#include <string>
#include "TermBase.h"

class Term : public TermBase{
    private:
        std::string value;
        
    public:
        Term();
        Term(std::string&);
        virtual const std::string& getValue()const override;
        virtual void setValue(std::string&) override;
        virtual void print()const override;
        ~Term();
};
#endif