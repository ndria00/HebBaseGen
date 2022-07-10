#ifndef BODY_H_
#define BODY_H_
#include "Literal.h"
#include "Aggregate.h"

class Body{
    private: 
        std::vector<Literal*> conjunction;
        std::vector<Aggregate*> aggregates;
    
    public:
        const std::vector<Literal*>& getConjunction()const;
        const std::vector<Aggregate*>& getAggregates()const;
        void addAggregate(Aggregate*);
        void addAtom(Literal*);
        void setConjunction(std::vector<Literal*>&);
        void clear();
        void print()const;
};

#endif