#ifndef RULE_H
#define RULE_H

#include "Head.h"
#include "Body.h"
class Rule{
    private: 
        Head head;
        Body body;
   
    public:
        Rule();
        Rule(Head, Body);
        Head getHead()const;
        Body getBody()const;
        void setHead(Head);
        void setBody(Body);
        void print()const;
};

#endif