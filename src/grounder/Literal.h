#ifndef ATOM_H_
#define ATOM_H_
#include <string>
#include <vector>
#include <iostream>
#include "TermBase.h"
#include "ExpressionBase.h"
class Literal{
    private:
        std::string identifier;
        std::vector<TermBase*> terms;
        bool negative;
    public:
        Literal();
        Literal(std::string, std::vector<TermBase*>&);
        std::string getIdentifier()const;
        const std::vector<TermBase*>& getTerms()const;
        void setIdentifier(std::string);
        void setTerms (std::vector<TermBase*>&);
        void addTerm(TermBase*);
        void print()const;
        bool isNegative()const;
        void setNegative(bool);
        void clear();
};

#endif