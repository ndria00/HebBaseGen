#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Rule.h"
#include <unordered_map>
class Program{
    private:
        std::vector<Rule*> rules;
        std::unordered_map<std::string, unsigned> predicateID;
        std::unordered_map<std::string, unsigned> iDBPredicates;
    public:
        Program();
        const std::vector<Rule*>& getRules()const;
        void setRules(std::vector<Rule*>&);
        void addRule(Rule*);
        Rule* getRuleByID(unsigned);
        void print()const;
        bool checkSafety()const;
        void mapAllConstants()const;
        bool existsPredicate(std::string)const;
        bool addPredicateWithID(const std::string&, unsigned);
        std::unordered_map<std::string, unsigned>& getPredicatesID();
        void getRulesByID(std::vector<unsigned>&, std::vector<Rule*>&);
        unsigned getIDForPredicate(Literal* );
        void addIDBPredicate(Literal* );
        bool isIDBPredicate(Literal*) const;
        std::unordered_map<std::string, unsigned>& getIDBPredicates();
};

#endif /*PROGRAM_H_*/