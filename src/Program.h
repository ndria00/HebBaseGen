#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Rule.h"

class Program{
    private:
        std::vector<Rule> rules;
    
    public:
        Program();
        Program(std::vector<Rule>);
        std::vector<Rule> getRules()const;
        void setRules(std::vector<Rule>);
        void print()const;
};

#endif