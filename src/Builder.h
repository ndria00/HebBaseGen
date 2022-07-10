#ifndef BUILDER_H_
#define BUILDE_H_

#include "parser/ASPCore2Parser.h"
#include "grounder/Literal.h"
#include "grounder/Head.h"
#include "grounder/Rule.h"
#include "grounder/WeakConstraint.h"
#include "grounder/Term.h"
#include "grounder/Aggregate.h"
#include "Program.h"
#include <list>

class Builder{
    public:
        Builder();
        void buildAtom(ASPCore2Parser::AtomContext*);
        void buildNafLiteral(ASPCore2Parser::Naf_literalContext*);
        void buildClassicLiteral(ASPCore2Parser::Classic_literalContext*);
        void buildHead(ASPCore2Parser::HeadContext*);
        void buildSimpleRule(ASPCore2Parser::Simple_ruleContext*);
        void buildRule(ASPCore2Parser::RuleContext*);
        void buildTerm(ASPCore2Parser::TermContext*);
        void buildTerm_(ASPCore2Parser::Term_Context*);
        void buildTerm__(ASPCore2Parser::Term__Context*);
        void buildAggregateAtom(ASPCore2Parser::Aggregate_atomContext*);
        void buildAggregate(ASPCore2Parser::AggregateContext*);
        void buildLeftwardOp(ASPCore2Parser::LeftwardopContext*);
        void buildRightwardOp(ASPCore2Parser::RightwardopContext*);
        void buildBasicTerm(ASPCore2Parser::Basic_termContext*);

        void printProgram();
        //void buildProgram(ASPCore2Parser::ProgramContext*, Program&);        
        void clearMemory();
        void addAtom(Literal*);
        void addTerm(Term*);
        void addRule(Rule*);
        void addAggregate(Aggregate*);
        bool isBuildingHead();
        void setBuildingHead(bool);
        bool isBuildingAggregate();
        void setBuildingAggregate(bool);
        void setBuildingRightWardAggregate(bool);
        Literal* getCurrentAtom();
        Rule* getCurrentRule();
        Aggregate* getCurrentAggregate();

   
    private:
        Rule* currentRule;
        Literal* currentAtom;
        Aggregate* currentAggregate;
        std::list<Rule*> allRules;
        std::list<Literal*> allAtoms;
        std::list<Term*> allTerms;
        std::list<Aggregate*> allAggregates;
        //state variables used to make the builder
        //behave in different ways with the same
        //contexts passed, basing on what is being built
        //at the moment 
        bool buildingHead = false;
        bool buildingAggregate = false;
        bool buildingNegativeLiteral = false;
        bool buildingLeftWardAggregate = false;
        bool buildingRightWardAggregate = false;
        bool buildingLiteral = false;
};

#endif