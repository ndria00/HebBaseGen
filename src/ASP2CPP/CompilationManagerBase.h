#ifndef COMPILATIONMANAGERBASE_H
#define COMPILATIONMANAGERBASE_H
#include "../Builder.h"
#include "../utils/Indentation.h"
#include "../utils/SharedFunctions.h"
#include "../DependencyGraph/DependencyGraphHandler.h"
#include <algorithm>
#include <iostream>
class CompilationManagerBase{
    protected:
        Builder* builder;
        std::ostream* out;
        Indentation indentation;
        std::set<std::string> declaredMaps;
        std::unordered_map<std::string, std::set<std::string> > predicatesPositiveMaps;
        std::unordered_map<std::string, std::set<std::string> > predicatesUndefMaps;
        
        void printLiteralTuple(const Literal*);
        void printLiteralTuple(const Literal* , const std::unordered_set<std::string> &);
        void findExitRules(std::vector<unsigned>& ,Program* program,  std::vector<unsigned>&, std::vector<std::string>& );
    public:
        CompilationManagerBase(Builder*);
        virtual void generateProgram(Program*) = 0;
        virtual void declareAuxMap(const std::string&, std::vector<unsigned>, const std::string&) = 0;
        virtual void declareDataStructures(RuleBase* ) = 0;
        virtual void declareDataStructures(ChoiceRule* ) = 0;
        virtual void compileRule(Rule*, std::vector<std::string>&, int, bool) = 0;
        virtual void compileChoiceRule(ChoiceRule*, std::vector<std::string>&, int, bool) = 0;
        virtual void compileChoiceElement(const std::pair<Literal*, Body*>&, bool) = 0;
        virtual void compileRecursiveComponent(Program*, std::vector<unsigned>&) = 0;
        void getRulesFromPredicateIds(Program*, std::vector<unsigned>&, std::vector<unsigned>&);
        virtual void deleteCompletelyDefinedPredicates(std::unordered_set<unsigned>&, Program*) = 0;
        void setOutStream(std::ostream*);

};

#endif