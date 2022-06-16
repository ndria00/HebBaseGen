#ifndef BUILDER_H_
#define BUILDE_H_

#include "parser/ASPCore2Parser.h"
#include "grounder/Atom.h"
#include "grounder/Head.h"
#include "grounder/Rule.h"
#include "grounder/Term.h"
#include "Program.h"
#include <list>

class Builder{
    public:
        void buildAtom(ASPCore2Parser::Classic_literalContext*);
        void buildHead(ASPCore2Parser::HeadContext*);
        void buildSimpleRule(ASPCore2Parser::Simple_ruleContext*);
        void buildRule(ASPCore2Parser::RuleContext*);
        //void buildProgram(ASPCore2Parser::ProgramContext*, Program&);        
        void clearMemory();
        void addAtom(Atom*);
        void addTerm(Term*);
        void addRule(Rule*);
        bool isBuildingHead();
        void setBuildingHead(bool);
        Atom* getCurrentAtom();
        Rule* getCurrentRule();
   
    private:
        Rule* currentRule;
        Atom* currentAtom;
        bool buildingHead;
        std::list<Rule*> allRules;
        std::list<Atom*> allAtoms;
        std::list<Term*> allTerms;

};

#endif