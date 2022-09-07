#ifndef COMPILATIONNMANAGER_H
#define COMPILATIONMANAGER_H
#include "../Builder.h"
#include "../utils/Indentation.h"
#include "../utils/SharedFunctions.h"
#include "../DependencyGraph/DependencyGraphHandler.h"
#include <algorithm>
#include <iostream>
class CompilationManager{
    private:
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
        CompilationManager(Builder*);
        void generateProgram(Program*);
        void declareAuxMap(const std::string&, std::vector<unsigned>, const std::string&);
        void declareDataStructures(Rule* );
        void compileRule(Rule*, std::vector<std::string>&);
        void compileRecursiveComponent(Program*, std::vector<unsigned>&);
        void getRulesFromPredicateIds(Program*, std::vector<unsigned>&, std::vector<unsigned>&);
        void setOutStream(std::ostream*);
        void addFacts();

};

#endif