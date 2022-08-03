#ifndef DEPENDENCYGGRAPHHANDLES_H
#define DEPENDENCYGGRAPHHANDLES_H

#include "GraphWithTarjanAlgorithm.h"
#include "unordered_map"
#include <iostream>
#include <vector>
#include "../grounder/Rule.h"
#include "../grounder/Body.h"
#include "../grounder/Head.h"
#include "../grounder/Literal.h"
class DependencyGraphHandler{
    private:
        GraphWithTarjanAlgorithm depGraph;
        std::unordered_map<std::string, int> predicateID;
    public:
        static DependencyGraphHandler& getInstance();
        void createGraph(std::vector<Rule*>&);
        std::vector<std::vector<int>> getProgramLayers();
        DependencyGraphHandler(const DependencyGraphHandler&) = delete;
        bool operator=(const DependencyGraphHandler&) = delete;
        void printProgramLayers();
    protected:    
        DependencyGraphHandler();
};

#endif /*DEPENDENCYGGRAPHHANDLES_H*/