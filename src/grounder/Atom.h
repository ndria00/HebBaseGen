#ifndef ATOM_H_
#define ATOM_H_
#include <string>
#include <vector>
#include <iostream>
#include "Term.h"
class Atom{
    private:
        std::string identifier;
        std::vector<Term*> terms;
        bool negative;
    public:
        Atom();
        Atom(std::string, std::vector<Term*>&);
        std::string getIdentifier()const;
        const std::vector<Term*>& getTerms()const;
        void setIdentifier(std::string);
        void setTerms (std::vector<Term*>);
        void print()const;
        bool isNegative()const;
        void setNegative(bool);
};

#endif