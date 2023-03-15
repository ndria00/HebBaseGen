#ifndef PRECOMPILERASP_H
#define PRECOMPILERASP_H
#include "../DependencyGraph/DependencyGraphHandler.h"
#include "../grounder/Program.h"
#include "CompilationManagerBase.h"
class PreCompilerASP{
    private:
        Program* program;
        std::vector<std::unordered_set<unsigned>> predicatesToRemoveByLayer;
        std::unordered_map<unsigned, unsigned> predicateNodeMapping;
        std::vector<std::vector<unsigned>> layers;
        CompilationManagerBase* compManager;
        
        void computePredicatesToRemove();
        bool programContainsRecusionThroughNegation();
    public:
        PreCompilerASP(Program*);
        CompilationManagerBase* getCompilationManager();
        const std::unordered_set<unsigned> getPredicatesToRemove(unsigned);
        void findAllInterestingBodyReorderings();
        void getRulesFromPredicateIds(std::vector<unsigned>&, std::vector<unsigned>&);
        unsigned getLayersNumber();
        void getEffectiveLiteralsIDForLayer(unsigned, std::vector<unsigned>&);
        void findExitRules(std::vector<unsigned>&, std::vector<unsigned>&, std::vector<std::string>&);
        std::unordered_map<unsigned, unsigned> getPredicateNodeMapping();
        ~PreCompilerASP();

};
#endif /*PRECOMPILERASP_H*/