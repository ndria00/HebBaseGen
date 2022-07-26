#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Rule.h"

class Program{
    private:
        std::vector<Rule*> rules;
    
    public:
        Program();
        const std::vector<Rule*>& getRules()const;
        void setRules(std::vector<Rule*>&);
        void addRule(Rule*);
        void print()const;
        bool checkSafety()const;
        void mapAllConstants()const;
};

#endif