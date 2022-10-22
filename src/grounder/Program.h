#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Rule.h"
#include "ChoiceRule.h"
#include <unordered_map>
class Program{
    private:
        std::vector<Rule*> rules;
        std::vector<ChoiceRule*> choiceRules;
        std::unordered_map<std::string, unsigned> predicateID;
        std::unordered_map<std::string, unsigned> iDBPredicates;
        std::unordered_map<unsigned, std::string> inversePredicateMap;
    public:
        Program();
        const std::vector<Rule*>& getRules()const;
        const std::vector<ChoiceRule*>& getChoiceRules()const;
        void setRules(std::vector<Rule*>&);
        void addRule(Rule*);
        void addChoiceRule(ChoiceRule*);
        RuleBase* getRuleByID(unsigned);
        void print()const;
        bool checkSafety()const;
        void mapAllConstants()const;
        bool existsPredicate(std::string)const;
        std::string& getPredicateByID(unsigned);
        bool addPredicateWithID(const std::string&, unsigned);
        std::unordered_map<std::string, unsigned>& getPredicatesID();
        void getRulesByID(std::vector<unsigned>&, std::vector<RuleBase*>&);
        unsigned getIDForPredicate(Literal* );
        void addIDBPredicate(Literal* );
        bool isIDBPredicate(Literal*) const;
        std::unordered_map<std::string, unsigned>& getIDBPredicates();
        bool containsAggregates()const;
        bool containsUnsupportedBuiltIn()const;
};

#endif /*PROGRAM_H_*/