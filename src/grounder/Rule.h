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
        unsigned id;
   
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
        bool isFact()const;
        void setSafetyStatus(bool);
        void setID(unsigned);
        unsigned getID()const;
        bool containsLiteralInHead(Literal*)const;
        bool containsLiteralInHead(unsigned id)const;
        void sortLiteralsInBody();
        ~Rule();
};

#endif