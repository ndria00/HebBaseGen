#ifndef DEPENDENCYGGRAPHHANDLES_H
#define DEPENDENCYGGRAPHHANDLES_H

#include "GraphWithTarjanAlgorithm.h"
#include <unordered_map>
#include <iostream>
#include <vector>
#include "../grounder/Rule.h"
#include "../grounder/Body.h"
#include "../grounder/Head.h"
#include "../grounder/Literal.h"
#include "../grounder/Program.h"
class DependencyGraphHandler{
    private:
        GraphWithTarjanAlgorithm depGraph;
    public:
        static DependencyGraphHandler& getInstance();
        void createGraph(Program* , std::unordered_map<unsigned, unsigned>&);
        std::vector<std::vector<unsigned>> getProgramLayers();
        DependencyGraphHandler(const DependencyGraphHandler&) = delete;
        bool operator=(const DependencyGraphHandler&) = delete;
        void printProgramLayers(std::unordered_map<unsigned, unsigned>&);
    protected:    
        DependencyGraphHandler();
};

#endif /*DEPENDENCYGGRAPHHANDLES_H*/