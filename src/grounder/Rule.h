#ifndef RULE_H
#define RULE_H

#include "Head.h"
#include "Body.h"
#include "Aggregate.h"
#include "RuleBase.h"
#include <set>
class Rule : public RuleBase{
    private: 
        Head* head;
        Body* body;
        bool safe;
   
    public:
        Rule();
        const Head* getHead() override;
        const Body* getBody()override;
        void addAtomInHead(Literal*) override;
        void addAtomInBody(Literal*) override;
        void addBuiltInInBody(BuiltInTerm*) override;
        void addAggregateInBody(Aggregate*) override;
        void setHead(Head*) override;
        void setBody(Body*)override;
        void print()const;
        bool isSafe()const override;
        bool isFact()const override;
        void setSafetyStatus(bool);
        bool containsLiteralInHead(Literal*)const override;
        bool containsLiteralInHead(unsigned)const override;
        bool containsLiteralInBody(std::string&)const override;
        void sortLiteralsInBody(int)override;
        void removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& it) override;
        void getRecursiveIndexes(std::vector<unsigned>&)const;
        bool isClassicRule()const override;
        bool isChoiceRule()const override;
        ~Rule();
};

#endif