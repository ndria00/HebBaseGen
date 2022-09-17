#ifndef BODY_H_
#define BODY_H_
#include "Literal.h"
#include "Aggregate.h"
#include "BuiltInTerm.h"
#include <algorithm>

class Body{
    private: 
        std::vector<Literal*> conjunction;
        std::vector<Aggregate*> aggregates;
        std::vector<BuiltInTerm*> builtInTerms;
    
    public:
        Body();
        const std::vector<Literal*>& getConjunction()const;
        const std::vector<Aggregate*>& getAggregates()const;
        void addAggregate(Aggregate*);
        void addAtom(Literal*);
        void addBuiltIn(BuiltInTerm*);
        void setConjunction(std::vector<Literal*>&);
        void removeLiteralAt(const std::vector<Literal*>::const_iterator&);
        void getBodyVariables(std::unordered_set<std::string>&)const;
        void removeBodySafeVariables(std::unordered_set<std::string>&)const;
        bool isEmpty();
        void sortLiterals();
        void print()const;
        unsigned getNegativeSize()const;
        void reorderBodyLiterals();
};

#endif