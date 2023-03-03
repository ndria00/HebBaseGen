#ifndef COMPILATIONMANAGERDATALOG_H
#define COMPILATIONMANAGERDATALOG_H
#include "CompilationManagerBase.h"

class CompilationManagerDatalog : public CompilationManagerBase{

    public:
        CompilationManagerDatalog(Builder*);
        void generateProgram(Program*) override;
        void declareAuxMap(const std::string&, std::vector<unsigned>, const std::string&) override;
        void declareDataStructures(RuleBase* ) override;
        void declareDataStructures(ChoiceRule* ) override;
        void compileRule(Rule*, std::vector<std::string>&, int, bool) override;
        void compileChoiceRule(ChoiceRule*, std::vector<std::string>&, int, bool) override;
        void compileChoiceElement(const std::pair<Literal*, Body*>&, bool) override;
        void compileRecursiveComponent(Program*, std::vector<unsigned>&) override;
        void deleteCompletelyDefinedPredicates(std::unordered_set<unsigned>&, Program*) override;
};
#endif /*COMPILATIONMANAGERBASE*/