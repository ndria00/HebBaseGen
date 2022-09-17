#include "DependencyGraphHandler.h"

DependencyGraphHandler::DependencyGraphHandler(){
    depGraph = GraphWithTarjanAlgorithm();
}

DependencyGraphHandler& DependencyGraphHandler::getInstance(){
    static DependencyGraphHandler instance;
    return instance; 
}

void DependencyGraphHandler::createGraph(Program* program, std::unordered_map<unsigned, unsigned>& predicateNodeMapping){

	//set ids and add nodes
	// for(Rule* r : allRules){
	// 	for(Literal* lit : r->getHead()->getDisjunction()){
	// 		if(predicateID.find(lit->getIdentifier()) != predicateID.end()){
	// 			//lit->setID(literalsId);
	// 			//predicateID[lit->getIDAndArity()] = literalsId;
	// 			depGraph.addNode(lit->getID());
	// 			//std::cout<<"Added node " <<literalsId<<std::endl;
	// 			//++literalsId;
	// 		}
	// 	}
	// }
	unsigned literalsID = 0;
	for(auto& it: program->getIDBPredicates()){
		depGraph.addNode(literalsID);
		predicateNodeMapping[it.second] = literalsID;
		++literalsID;

	}
	// for(Rule* r : allRules){
	// 	for(Literal* lit : r->getBody()->getConjunction()){
	// 		if(predicateID.find(lit->getIDAndArity()) != predicateID.end()){
	// 			lit->setID(predicateID[lit->getIDAndArity()]);
	// 			++literalsId;
	// 		}
	// 	}
	// }

	//add edges
	for(Rule* r : program->getRules()){
		for(Literal * lit : r->getBody()->getConjunction()){
			if(lit->isIDBPredicate() /*&& !lit->isNegative()*/){
				for(Literal* litHead : r->getHead()->getDisjunction()){
					//if(predicateID[lit->getIdentifier()] != predicateID[litHead->getIdentifier()]){
						depGraph.addEdge(predicateNodeMapping[lit->getID()], predicateNodeMapping[litHead->getID()]);
						//std::cout<<"added edge from " << lit->getID();
						//lit->print();
						//std::cout<<" to " << litHead->getID();
						//litHead->print();
						//std::cout<<std::endl;
					//}
				}
			}
		}
	}

}

//compute dependency graph
std::vector<std::vector<unsigned>> DependencyGraphHandler::getProgramLayers(){
    return depGraph.SCC();
}

void DependencyGraphHandler::printProgramLayers(std::unordered_map<unsigned, unsigned>& predicateNodeMapping){
    std::vector<std::vector<unsigned>> layers = depGraph.SCC();
    for(unsigned i = 0; i < layers.size(); ++i){
		std::cout<<"Layer number "<<i<<" of size "<<layers[i].size()<< ": ";
		for(unsigned j = 0; j < layers[i].size(); ++j){
			std::cout<<layers[i][j]<<" ";
		} 
		std::cout<<std::endl;
	}
}