#ifndef ATOM_H_
#define ATOM_H_
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "TermBase.h"
#include "ExpressionBase.h"
class Literal{
    private:
        unsigned id;
        std::string identifier;
        std::vector<TermBase*> terms;
        bool negative;
        bool idbPredicate;
    public:
        Literal();
        Literal(std::string, std::vector<TermBase*>&);
        const std::string& getIdentifier()const;
        const std::vector<TermBase*>& getTerms()const;
        void setIdentifier(std::string);
        void setID(unsigned);
        unsigned getID()const;
        void setTerms (std::vector<TermBase*>&);
        const std::string& getTermAt(unsigned )const;
        void addTerm(TermBase*);
        unsigned getArity()const;
        void print()const;
        bool isNegative()const;
        void setNegative(bool);
        void getLiteralVariables(std::unordered_set<std::string>&)const;
        void addVariablesToSet(std::unordered_set<std::string>&)const;
        void removeSafeLiteralVariables(std::unordered_set<std::string>&)const;
        void clear();
        bool isGround();
        std::string getRepresentation();
        std::string getIDAndArity()const;
        bool isIDBPredicate()const;
        void setIDBPredicate(bool);
        bool operator==(const Literal& )const;

        bool isBound(const std::unordered_set<std::string>&)const;
};

#endif