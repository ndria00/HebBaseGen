#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Rule.h"
#include <unordered_map>
class Program{
    private:
        std::vector<Rule*> rules;
        std::unordered_map<std::string, unsigned> predicateID;
    
    public:
        Program();
        const std::vector<Rule*>& getRules()const;
        void setRules(std::vector<Rule*>&);
        void addRule(Rule*);
        void print()const;
        bool checkSafety()const;
        void mapAllConstants()const;
        bool existsPredicate(std::string)const;
        void addPredicateWithID(const std::string&, unsigned);
        std::unordered_map<std::string, unsigned>& getPredicatesID();
};

#endif /*PROGRAM_H_*/