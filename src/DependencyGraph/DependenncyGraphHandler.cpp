#include "DependencyGraphHandler.h"

DependencyGraphHandler::DependencyGraphHandler(){
    predicateID = {};
    depGraph = GraphWithTarjanAlgorithm();
}

DependencyGraphHandler& DependencyGraphHandler::getInstance(){
    static DependencyGraphHandler instance;
    return instance; 
}

void DependencyGraphHandler::createGraph(std::vector<Rule*>& allRules){
	unsigned literalsId = 0;
	//set ids
	for(Rule* r : allRules){
		for(Literal* lit : r->getHead()->getDisjunction()){
			if(predicateID.find(lit->getIDAndArity()) == predicateID.end()){
				lit->setID(literalsId);
				predicateID[lit->getIDAndArity()] = literalsId;
				depGraph.addNode(literalsId);
				++literalsId;
			}
		}
	}
	
	for(Rule* r : allRules){
		for(Literal* lit : r->getBody()->getConjunction()){
			if(predicateID.find(lit->getIDAndArity()) != predicateID.end()){
				lit->setID(predicateID[lit->getIDAndArity()]);
			}
		}
	}

	//add edges and compute dependency graph
	for(Rule* r : allRules){
		for(Literal * lit : r->getBody()->getConjunction()){
			if(predicateID.find(lit->getIDAndArity()) != predicateID.end()){
				for(Literal* litHead : r->getHead()->getDisjunction()){
					depGraph.addEdge(lit->getID(), litHead->getID());
					// std::cout<<"added edge from ";
					// lit->print();
					// std::cout<<" to ";
					// litHead->print();
					// std::cout<<std::endl;
				}
			}
		}
	}

}

std::vector<std::vector<int>> DependencyGraphHandler::getProgramLayers(){
    return depGraph.SCC();
}

void DependencyGraphHandler::printProgramLayers(){
    std::vector<std::vector<int>> layers = depGraph.SCC();
    for(unsigned i = 0; i < layers.size(); ++i){
		std::cout<<"Layer number "<<i<<" of size "<<layers[i].size()<< ": ";
		for(unsigned j = 0; j < layers[i].size(); ++j){
			std::cout<<layers[i][j]<<" ";
		} 
		std::cout<<std::endl;
	}
}