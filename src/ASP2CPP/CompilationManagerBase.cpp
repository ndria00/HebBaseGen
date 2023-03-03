#include "CompilationManagerBase.h"
#include "../DataStructures/TupleFactory.h"
#include <unordered_map>

CompilationManagerBase::CompilationManagerBase(Builder* builder){
    this->builder = builder;
    indentation = Indentation(0);
    declaredMaps = std::set<std::string>();
}


void CompilationManagerBase::setOutStream(std::ostream* outputFile){
    this->out = outputFile;
}


void CompilationManagerBase::printLiteralTuple(const Literal* lit) {
    for (unsigned t = 0; t < lit->getArity(); t++) {
        if (t > 0) {
            *out << ", ";
        }
        if (!lit->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(lit->getTermAt(t))) {
            *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(lit->getTerms().at(t)->getRepresentation()) << "\")";
        } else {
            *out << lit->getTermAt(t);
        }
    }


}

void CompilationManagerBase::printLiteralTuple(const Literal* lit, const std::unordered_set<std::string>& boundVariables) {
    bool first = true;
    for (unsigned t = 0; t < lit->getArity(); t++) {
        if (!lit->getTerms().at(t)->isVariable() || boundVariables.count(lit->getTermAt(t))) {
            if (!first) {
                *out << ", ";
            }
            if (!lit->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(lit->getTerms().at(t)->getRepresentation())) {
                *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(lit->getTerms().at(t)->getRepresentation()) << "\")";
            } else {
                *out << lit->getTerms().at(t)->getRepresentation();
            }
            first = false;
        }
    }


}

void CompilationManagerBase::findExitRules(std::vector<unsigned>& recursiveComponent, Program* program, std::vector<unsigned>& exitRules, std::vector<std::string>& recursiveDep){
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

void CompilationManagerBase::getRulesFromPredicateIds(Program * program, std::vector<unsigned>& preds, std::vector<unsigned>& rules){
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