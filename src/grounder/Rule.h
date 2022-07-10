#ifndef RULE_H
#define RULE_H

#include "Head.h"
#include "Body.h"
#include "Aggregate.h"
class Rule{
    private: 
        Head head;
        Body body;
   
    public:
        Head getHead()const;
        Body getBody()const;
        void addAtomInHead(Literal*);
        void addAtomInBody(Literal*);
        void addAggregateInBody(Aggregate*);
        void setHead(Head);
        void setBody(Body);
        void print()const;
        void clearRule();
};

#endif