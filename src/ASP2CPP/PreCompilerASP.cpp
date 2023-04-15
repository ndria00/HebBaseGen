#include "PreCompilerASP.h"
#include "CompilationManagerASP.h"
#include "CompilationManagerDatalog.h"


PreCompilerASP::PreCompilerASP(Program* program){
    this->program = program;
    DependencyGraphHandler::getInstance().createGraph(program, predicateNodeMapping);

    //statifications
    //Each layer contains the ids of its IDB predicates
    //In order to find the rules that are part of each layer a complete search of rules needs to be done  
	layers = DependencyGraphHandler::getInstance().getProgramLayers();
    DependencyGraphHandler::getInstance().printProgramLayers(program, predicateNodeMapping);
    //computePredicatesToRemove();
    //check if the program is asp or datalog and create the appropriate compilation manager
    if(programContainsRecusionThroughNegation()){
        compManager = new CompilationManagerASP();
        compManager->setIncrementalRemotion(false);
    }
    else{
        compManager = new CompilationManagerDatalog();
    }
}

PreCompilerASP::~PreCompilerASP(){
    delete compManager;
}

CompilationManagerBase* PreCompilerASP::getCompilationManager(){
    return compManager;
}

//TODO implement
bool PreCompilerASP::programContainsRecusionThroughNegation(){
    //check that there are no layers that have negative edges inside them
    for(unsigned i = 0; i < layers.size(); ++i){
        for(unsigned j = 0; j < layers[i].size(); ++j){
            for(int k = 0; k < layers[k].size(); ++k){
                if(DependencyGraphHandler::getInstance().graphHasNegativeEdgeBetweenPredicates(layers[i][j], layers[i][k]))
                    return true;
            }
        }
    }
    return false;
}

unsigned PreCompilerASP::getLayersNumber(){
    return layers.size();
}

// void PreCompilerASP::computePredicatesToRemove(){
//     std::unordered_set<unsigned> remainingPredicatesToRemove;
//     for(unsigned i = 0; i < layers.size(); ++i){
//         predicatesToRemoveByLayer.push_back(std::unordered_set<unsigned>());
//     }
//     for(auto kv : program->getPredicatesID()){
//         remainingPredicatesToRemove.insert(kv.second);
//     }
//     std::unordered_set<unsigned> predicatesNotDefined;
//     for(int i = layers.size()-1; i >= 0 ; --i){
//         std::vector<unsigned> effectiveLiteralsIDs;
//         for(unsigned j = 0; j < layers[i].size(); ++j){
//             for(auto& it : predicateNodeMapping){
//                 if(it.second == layers[i][j]){
//                     effectiveLiteralsIDs.push_back(it.first);
//                     //std::cout << "working on "<<it.first<<std::endl;
//                     //predicatesCompletelyDefined.insert(it.first);
//                 }
//             }
//         }
//         predicatesNotDefined.clear();
//         for(Rule* r : program->getRules()){
//             if(!r->isAlreadyCompiled()){
//                 r->getAllLiterals(predicatesNotDefined);
//             }
//         }
//         //get literals that can be deleted as the difference between literals that
//         //appear somewhere in rules and all the literals that has not been deleted since now
//         for(auto pred : remainingPredicatesToRemove){
//             if(predicatesNotDefined.count(pred) == 0){
//                 predicatesToRemoveByLayer[i].insert(pred);
//             }
//         }
//     }
// }

// const std::unordered_set<unsigned> PreCompilerASP::getPredicatesToRemove(unsigned layerNumber){
//     std::unordered_set<unsigned> toDelete;
//     if(layerNumber > DependencyGraphHandler::getInstance().getNumberOfSCC() || layerNumber < 0){
//         return toDelete;
//     }
//     return predicatesToRemoveByLayer[layerNumber];
// }

void PreCompilerASP::findAllInterestingBodyReorderings(){

	DependencyGraphHandler::getInstance().printProgramLayers(program, predicateNodeMapping);
    for(int i = layers.size()-1; i >= 0 ; --i){
        std::vector<unsigned> effectiveLiteralsIDs;
        for(unsigned j = 0; j < layers[i].size(); ++j){
            for(auto& it : predicateNodeMapping){
                if(it.second == layers[i][j]){
                    effectiveLiteralsIDs.push_back(it.first);
                }
            }
        }
        std::vector<unsigned> rulesForComponent;
        getRulesFromPredicateIds(effectiveLiteralsIDs, rulesForComponent);
        std::vector<unsigned> exitRules;
        std::vector<std::string> recursiveDep;
        findExitRules(rulesForComponent, exitRules, recursiveDep);
        for(unsigned r = 0; r < rulesForComponent.size(); ++r){
            //for each ordering possible given from recursiveDep declare maps
            for(unsigned l = 0;  l < recursiveDep.size(); ++l){
                RuleBase* rule = program->getRuleByID(rulesForComponent[r]);
                for(int lit = 0; lit < rule->getBody()->getConjunction().size(); ++lit){
                    if(recursiveDep[l] == rule->getBody()->getConjunction().at(lit)->getIdentifier()){
                        rule->sortLiteralsInBody(lit);
                    }
                }
            }
        }
    }
}




void PreCompilerASP::getRulesFromPredicateIds(std::vector<unsigned>& preds, std::vector<unsigned>& rules){
    for(unsigned p = 0; p < preds.size(); ++p){
        for(Rule* r : program->getRules()){
            if(r->containsLiteralInHead(preds[p]) && std::find(rules.begin(), rules.end(), r->getID()) == rules.end())
                rules.push_back(r->getID());
        }
        for(ChoiceRule* r : program->getChoiceRules()){
            if(r->containsLiteralInHead(preds[p]) && std::find(rules.begin(), rules.end(), r->getID()) == rules.end())
                rules.push_back(r->getID());
        }
    }
}

void PreCompilerASP::getEffectiveLiteralsIDForLayer(unsigned layer, std::vector<unsigned>& effectiveLiteralsIDs){
    for(unsigned j = 0; j < layers[layer].size(); ++j){
        for(auto& it : predicateNodeMapping){
            if(it.second == layers[layer][j]){
                effectiveLiteralsIDs.push_back(it.first);
                //std::cout << "working on "<<it.first<<std::endl;
                //predicatesCompletelyDefined.insert(it.first);
            }
        }
    }   
}

void PreCompilerASP::findExitRules(std::vector<unsigned>& recursiveComponent, std::vector<unsigned>& exitRules, std::vector<std::string>& recursiveDep){
    std::vector<RuleBase*> componentRules;
    program->getRulesByID(recursiveComponent, componentRules);
    bool isExitRule;
    for(unsigned i = 0; i < componentRules.size(); ++i){
        isExitRule = true;
        for(Literal* l : componentRules[i]->getBody()->getConjunction()){
            
            for(unsigned j = 0; j < componentRules.size(); ++j){
                if(componentRules[j]->containsLiteralInHead(l)){
                    isExitRule = false;
                    //add recursive dep on lieral l of rule[i] 
                    if(std::find(recursiveDep.begin(), recursiveDep.end(), l->getIdentifier()) == recursiveDep.end()){
                        recursiveDep.push_back(l->getIdentifier());
                        //std::cout << "adding " << l->getIdentifier() <<std::endl;
                    }
                    //break;
                }
            }
            // if(!isExitRule)
            //     break;
        }
        //add recursive dep from body to head of choice elements
        //is not exit rule if there are literals in choice elements
        //body that appear in the head of any other rule that is part
        //of current component
        if(componentRules[i]->isChoiceRule()){
            ChoiceRule* rule = static_cast<ChoiceRule*>(componentRules[i]);
            for(auto& choiceElem : rule->getChoiceHead()){
                for(Literal* lit : choiceElem.second->getConjunction()){
                    for(unsigned j = 0; j < componentRules.size(); ++j){
                        if(componentRules[j]->containsLiteralInHead(lit)){
                            isExitRule = false;
                            //add recursive dep on lieral l of rule[i] 
                            if(std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) == recursiveDep.end()){
                                recursiveDep.push_back(lit->getIdentifier());
                                //std::cout << "adding " << l->getIdentifier() <<std::endl;
                            }
                        }
                    }
                }
            }
        }
        if(isExitRule)
            exitRules.push_back(componentRules[i]->getID());
    }
}

std::unordered_map<unsigned, unsigned> PreCompilerASP::getPredicateNodeMapping(){
    return predicateNodeMapping;
}