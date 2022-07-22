#ifndef RULE_H
#define RULE_H

#include "Head.h"
#include "Body.h"
#include "Aggregate.h"
#include <set>
class Rule{
    private: 
        Head* head;
        Body* body;
        bool safe;
   
    public:
        Rule();
        const Head* getHead();
        const Body* getBody();
        void addAtomInHead(Literal*);
        void addAtomInBody(Literal*);
        void addBuiltInInBody(BuiltInTerm*);
        void addAggregateInBody(Aggregate*);
        void setHead(Head*);
        void setBody(Body*);
        void print()const;
        bool isSafe()const;
        void setSafetyStatus(bool);
        ~Rule();
};

#endif