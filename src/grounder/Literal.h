#ifndef ATOM_H_
#define ATOM_H_
#include <string>
#include <vector>
#include <iostream>
#include "TermBase.h"
#include "ExpressionBase.h"
class Literal{
    private:
        unsigned id;
        std::string identifier;
        std::vector<TermBase*> terms;
        bool negative;
    public:
        Literal();
        Literal(std::string, std::vector<TermBase*>&);
        std::string getIdentifier()const;
        const std::vector<TermBase*>& getTerms()const;
        void setIdentifier(std::string);
        void setID(unsigned);
        unsigned getID()const;
        void setTerms (std::vector<TermBase*>&);
        void addTerm(TermBase*);
        unsigned getArity()const;
        void print()const;
        bool isNegative()const;
        void setNegative(bool);
        void getLiteralVariables(std::set<std::string>&)const;
        void removeSafeLiteralVariables(std::set<std::string>&)const;
        void clear();
        std::string getRepresentation();
        std::string getIDAndArity()const;
        bool operator==(const Literal& )const;
};

#endif