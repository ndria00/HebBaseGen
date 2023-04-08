#ifndef RULEBASE_H
#define RULEBASE_H
#include "Head.h"
#include "Body.h"
#include <unordered_map>
class RuleBase{
    private:
        bool alreadyCompiled;
        unsigned id;
    protected:
        std::unordered_map<int, std::vector<unsigned>> starterToBodyIndexes;

    public:
        RuleBase();
        void setID(unsigned);
        unsigned getID()const;
        bool isAlreadyCompiled()const;
        void setAlreadyCompiled(bool);
        std::vector<unsigned>& getOrderedBodyByStarter(int );
        std::unordered_map<int, std::vector<unsigned>>& getStartersAndBody();
        virtual const Head* getHead() = 0;
        virtual const Body* getBody() = 0;
        virtual void addAtomInHead(Literal*) = 0;
        virtual void addAtomInBody(Literal*) = 0;
        virtual void addBuiltInInBody(BuiltInTerm*) = 0;
        virtual void addAggregateInBody(Aggregate*) = 0;
        virtual bool containsLiteralInBody(std::string&)const = 0;
        virtual bool containsLiteralInHead(unsigned) const = 0;
        virtual bool containsLiteralInHead(Literal*) const = 0;
        virtual bool containsLiteralInHead(std::string&)const = 0;
        virtual void getAllLiterals(std::unordered_set<unsigned>&)const = 0;
        virtual void sortLiteralsInBody(int) = 0;
        virtual void setHead(Head*) = 0;
        virtual void setBody(Body*) = 0;
        virtual bool isSafe()const = 0;
        virtual bool isFact()const = 0;
        virtual void removeBuiltInAt(const std::vector<BuiltInTerm*>::const_iterator& ) = 0;
        virtual bool isClassicRule()const = 0;
        virtual bool isChoiceRule()const = 0;
        virtual ~RuleBase(){}
};
#endif /*RULEBASE_H*/