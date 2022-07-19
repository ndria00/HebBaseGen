#ifndef RULE_H
#define RULE_H

#include "Head.h"
#include "Body.h"
#include "Aggregate.h"
class Rule{
    private:
        //TODO  
        Head head;
        Body body;
   
    public:
        Rule();
        const Head& getHead()const;
        const Body& getBody()const;
        void addAtomInHead(Literal*);
        void addAtomInBody(Literal*);
        void addBuiltInInBody(BuiltInTerm*);
        void addAggregateInBody(Aggregate*);
        void setHead(Head&);
        void setBody(Body&);
        void print()const;
};

#endif