#ifndef BODY_H_
#define BODY_H_
#include "Literal.h"
#include "Aggregate.h"
#include "BuiltInTerm.h"

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
        void getBodyVariables(std::set<std::string>&)const;
        void removeBodySafeVariables(std::set<std::string>&)const;
        bool isEmpty();
        void print()const;
};

#endif