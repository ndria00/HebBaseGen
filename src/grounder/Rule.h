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
        unsigned id;
        std::unordered_map<int, std::vector<unsigned>> starterToBodyIndexes;
   
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
        void setID(unsigned);
        unsigned getID()const;
        bool containsLiteralInHead(Literal*)const;
        bool containsLiteralInHead(unsigned id)const;
        bool containsLiteralInBody(std::string&)const;
        void sortLiteralsInBody(int);
        std::vector<unsigned>& getOrderedBodyByStarter(int );
        std::unordered_map<int, std::vector<unsigned>>& getStartersAndBody();
        void removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& it) override;
        void getRecursiveIndexes(std::vector<unsigned>&)const;
        ~Rule();
};

#endif