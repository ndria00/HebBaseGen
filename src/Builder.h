#ifndef BUILDER_H
#define BUILDER_H

#include "parser/ASPCore2Parser.h"
#include "grounder/Literal.h"
#include "grounder/Head.h"
#include "grounder/Rule.h"
#include "grounder/WeakConstraint.h"
#include "grounder/TermBase.h"
#include "grounder/Aggregate.h"
#include "grounder/SimpleFactor.h"
#include "grounder/Expression.h"
#include "grounder/ExpressionBase.h"
#include "grounder/BuiltInTerm.h"
#include "grounder/Program.h"
#include "grounder/FunctionalTerm.h"
#include "grounder/ChoiceRule.h"
#include <vector>
#include <list>

class Builder{
    public:
        Builder(Program*);
        void buildAtom(ASPCore2Parser::AtomContext*);
        void buildNafLiteral(ASPCore2Parser::Naf_literalContext*);
        void buildClassicLiteral(ASPCore2Parser::Classic_literalContext*);
        void buildHead(ASPCore2Parser::HeadContext*);
        void buildSimpleRule(ASPCore2Parser::Simple_ruleContext*);
        void buildChoiceRule(ASPCore2Parser::Choice_atomContext*);
        void buildTerm(ASPCore2Parser::TermContext*);
        void buildTerm_(ASPCore2Parser::Term_Context*);
        void buildTerm__(ASPCore2Parser::Term__Context*);
        void buildAggregateAtom(ASPCore2Parser::Aggregate_atomContext*);
        void buildAggregate(ASPCore2Parser::AggregateContext*);
        void buildLeftwardOp(ASPCore2Parser::LeftwardopContext*);
        void buildRightwardOp(ASPCore2Parser::RightwardopContext*);
        void buildBasicTerm(ASPCore2Parser::Basic_termContext*);
        void buildCompareOperator(ASPCore2Parser::CompareopContext*);
        void buildTerminal(antlr4::tree::TerminalNode *);
        void buildExpression(ASPCore2Parser::ExprContext*);
        void buildFactor(ASPCore2Parser::FactorContext*);
        void buildBuiltInAtom(ASPCore2Parser::Builtin_atomContext*);
        void buildChoiceElementLiterals(ASPCore2Parser::Choice_elements_literalsContext*);
        void buildChoiceElement(ASPCore2Parser::Choice_elementContext*);
        void printProgram();
        //void buildProgram(ASPCore2Parser::ProgramContext*, Program&);        
        void clearMemory();
        void addCurrentChoiceRule();
        void addCurrentAtom();
        void addCurrentTerm();
        void addCurrentRule();
        void addCurrentAggregate();
        void addCurrentBuiltIn();
        bool isBuildingHead();
        void setBuildingHead(bool);
        bool isBuildingAggregate();
        void setBuildingAggregate(bool);
        void setBuildingRightWardAggregate(bool);
        antlr4::ParserRuleContext* getParentContext();
        Literal* getCurrentAtom();
        Rule* getCurrentRule();
        Aggregate* getCurrentAggregate();
        ChoiceRule* getCurrentChoiceRule();
        void exitExprFact();
        void exitBinop();
        void exitBuiltIn();
        void exitedSymbolicSet();
        //getResult()
        Program* getProgram();
        std::vector<Rule*>& getAllRules();
        std::vector<Literal*>& getAllLiterals();
        std::vector<std::pair<Literal*, bool>>& getAllFacts();
    
    private:
        Program* program;

        Rule* currentRule;
        Literal* currentAtom;
        Aggregate* currentAggregate;
        TermBase* currentTerm;
        SimpleFactor* currentFactor;
        ExpressionBase* currentExpression;
        BuiltInTerm* currentBuiltInTerm;
        FunctionalTerm* currentFuncTerm;
        ChoiceRule* currentChoiceRule;

        std::vector<ChoiceRule*> allChoiceRules;
        std::vector<Rule*> allRules;
        std::vector<Literal*> allAtoms;
        std::vector<TermBase*> allTerms;
        std::vector<Aggregate*> allAggregates;
        std::vector<ExpressionBase*> allExpressions;
        std::vector<BuiltInTerm*> allBuiltIn;
        std::vector<std::pair<Literal*, bool>> allFacts;
        //state variables used to make the builder
        //behave in different ways with the same
        //contexts passed, basing on what is being built
        //at the moment 
        bool buildingHead = false;
        bool buildingAggregate = false;
        bool buildingNegativeLiteral = false;
        bool buildingLeftWardAggregate = false;
        bool buildingRightWardAggregate = false;
        bool buildingAggregateLiterals = false;
        bool buildingChoiceElementLiterals = false;

        std::list<antlr4::ParserRuleContext*> currentBuildingTerms;
        std::vector<antlr4::ParserRuleContext*> expressionNesting;
        std::vector<antlr4::ParserRuleContext*> functionalTermsNesting;

        unsigned ruleID;
        unsigned literalsId;
};

#endif /*BUILDER_H*/