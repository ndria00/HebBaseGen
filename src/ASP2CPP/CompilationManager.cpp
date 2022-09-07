#include "CompilationManager.h"
#include <unordered_map>

CompilationManager::CompilationManager(Builder* builder){
    this->builder = builder;
    indentation = Indentation(0);
    declaredMaps = std::set<std::string>();
}

void CompilationManager::generateProgram(Program* program){
    *out << indentation << "#include \"Executor.h\"\n";
    *out << indentation << "#include \"../DataStructures/ConstantsManager.h\"\n";
    *out << indentation << "#include \"../DataStructures/AuxiliaryMapSmart.h\"\n";
    *out << indentation << "#include \"../DataStructures/TupleFactory.h\"\n";
    *out << indentation << "#include \"../DataStructures/IndexedSet.h\"\n";
    *out << indentation << "typedef TupleLight Tuple;\n";
    *out << indentation << "template<size_t S>\n";
    *out << indentation << "using AuxMap = AuxiliaryMapSmart<S> ;\n";
    *out << indentation << "const std::vector<int> EMPTY_TUPLES_VEC;\n";
    *out << indentation << "const IndexedSet EMPTY_TUPLES_SET;\n";
    *out << indentation << "\n";
    //*out << indentation << "Executor::~Executor(){\n";
    //*out << indentation << "}\n";

    //predicates id
    //Program* p = builder->getProgram();
    // for(int i= 0; i< program->getRules().size(); ++i){
    //     for(int j = 0; )
    //     *out << "const int " <<  << ";\n";
    // }
    //insert facts into factory
    *out << "TupleFactory factory;\n";
    *out << indentation << "std::vector<std::string> Executor::predicateIds;\n";

    for(auto lit : program->getPredicatesID()){
       *out << indentation << "const int _" << lit.first << " = " << lit.second << ";\n"; 
    }

    for(auto lit : program->getPredicatesID()){
        declareAuxMap(lit.first+"_", {}, lit.first);
    }
    
    for(auto rule : program->getRules()){
        declareDataStructures(rule);
    }

    //init function
    *out << indentation << "void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& );\n\n";
    *out << indentation++ << "void Executor::init(){\n";
    for(auto lit : program->getPredicatesID()){
        *out << indentation << "Executor::predicateIds.push_back(\"" << lit.first << "\");\n";
        *out << indentation << "predicateToID.insert({\"" << lit.first << "\", _" << lit.first<< "});\n";
        *out << indentation <<"factory.addPredicate();\n";
    }
    *out << --indentation << "}\n";

    //insertTrue and false functions
    std::unordered_map<std::string,std::pair<char,std::unordered_map<std::string,std::set<std::string>>>> auxInsertToPrefix={{"insertUndef",{'u',predicatesUndefMaps}},{"insertTrue",{'p',predicatesPositiveMaps}}};
    for(auto function_prefix: auxInsertToPrefix){
        *out << indentation++ << "inline void "<<function_prefix.first<<"(const std::pair<const TupleLight *, bool>& insertResult){\n";
        unsigned predIndex=0;
            for(auto predicateToMaps : function_prefix.second.second){
                std::string printElse = predIndex>0 ? "else " : "";
                *out << indentation++ << printElse << "if(insertResult.first->getPredicateName() == _"<<predicateToMaps.first<<"){\n";
                    for(auto mapName : predicateToMaps.second){
                        *out << indentation <<mapName << ".insert2Vec(*insertResult.first);\n";
                    }
                *out << --indentation << "}\n";
                predIndex++;
            }
        *out << --indentation <<"}\n";
    }
    
    //insert parsered facts into factory
    *out << indentation++ << "void Executor::insertFactIntoFactory(const Literal& lit, bool disjunctiveFact){\n";
    //*out << indentation++ << "for(Rule* r : p.){\n";
    //assuming that we only have a fact if the body of the rule is empty
    //check the case in which the body is ground and made of facts
    //*out << indentation++ << "if(r->getBody()->isEmpty()){\n";
    //*out << indentation++ << "for(Literal* lit : r->getConjunction()){\n";
    *out << indentation << "vector<int> terms;\n";
    *out << indentation++ << "for(TermBase* term : lit.getTerms()){\n";
    *out << indentation++ << "if(!term->isVariable()){\n";
    *out << indentation << "int mappedValue = ConstantsManager::getInstance().mapConstant(term->getRepresentation());\n";
    *out << indentation << "terms.push_back(mappedValue);\n";
    *out << --indentation << "}\n";
    *out << --indentation << "}\n";
    *out << indentation << "Tuple* t = factory.addNewInternalTuple(terms, predicateToID[lit.getIdentifier()]);\n";
    *out << indentation << "const auto& insertResult = t->setStatus(TruthStatus::True);\n";
    *out << indentation << "insertTrue(insertResult);\n";
    //*out << --indentation << "}\n";
    *out << --indentation << "}\n";


    *out << indentation++ << "void Executor::executeProgram(){\n";
    //addFacts();
    *out << indentation <<"//TODO\n";

    //DEP GRAPH
    //Dependency graph computation
    std::unordered_map<unsigned, unsigned> predicateNodeMapping;
	DependencyGraphHandler::getInstance().createGraph(program, predicateNodeMapping);
    //statifications
    //Each layer contains the ids of its IDB predicates
    //In order to find the rules that are part of each layer a complete search of rules needs to be done  
	std::vector<std::vector<unsigned>> layers = DependencyGraphHandler::getInstance().getProgramLayers();
	DependencyGraphHandler::getInstance().printProgramLayers(predicateNodeMapping);
    for(unsigned i = 0; i < layers.size(); ++i){
        std::vector<unsigned> effectiveLiteralsIDs;
        for(unsigned j = 0; j < layers[i].size(); ++j){
            for(auto& it : predicateNodeMapping)
                if(it.second == layers[i][j])
                    effectiveLiteralsIDs.push_back(it.first);
        }
        std::vector<unsigned> rulesForComponent;
        getRulesFromPredicateIds(program, effectiveLiteralsIDs, rulesForComponent);
        compileRecursiveComponent(program, rulesForComponent);
    }

    *out << --indentation<<"}\n";
    //print rule
    *out << indentation++ << "void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& literalsVariables){\n";
    //for each literal
    *out << indentation++ << "for(unsigned i  = 0; i < literalsVariables.size(); ++i){\n";
    *out << indentation << "std::cout<<literalsVariables[i].first;\n";
    *out << indentation++ << "for(unsigned j = 0; j < literalsVariables[i].second.size(); ++j){\n";
    *out << indentation++ << "if(j== 0 && literalsVariables[i].second.size() > 0){\n";
    *out << indentation << "std::cout<< \"(\";\n";
    *out << --indentation << "}\n";
    *out << indentation <<"std::cout << ConstantsManager::getInstance().unmapConstant(literalsVariables[i].second[j].second);\n";
    *out << indentation++ << "if(literalsVariables[i].second.size() > 1 && j < literalsVariables[i].second.size() - 1){\n";
    *out << indentation << "std::cout << \",\";\n";
    *out << --indentation << "}\n";
    *out << indentation++ << "if(j == literalsVariables[i].second.size() - 1 && literalsVariables[i].second.size() > 0){\n";
    *out << indentation << "std::cout << \")\";\n";
    *out << --indentation <<"}\n";
    *out << --indentation << "}\n";
    *out << indentation++ << "if(literalsVariables.size() > 1 && i < literalsVariables.size() - 1){\n";
    *out << indentation << "std::cout << \"|\";\n";
    *out << --indentation << "}\n";
    *out << indentation++ <<"if(i == literalsVariables.size() -1){\n";
    *out << indentation << "std::cout<<\". \";\n";
    *out << --indentation << "}\n";
    *out << --indentation << "}\n";

    *out << --indentation << "}\n";
}

void CompilationManager::setOutStream(std::ostream* outputFile){
    this->out = outputFile;
}

void CompilationManager::declareAuxMap(const std::string& mapVariableName, std::vector<unsigned> keyIndexes, const std::string& predName){
    if(!declaredMaps.count(mapVariableName)){
        int BITSETSIZE=keyIndexes.size()*CHAR_BIT*sizeof(int);
        *out << indentation << "AuxMap<"<<BITSETSIZE<<"> p" << mapVariableName << "({";
        predicatesPositiveMaps[predName].insert("p" + mapVariableName);
        for (unsigned k = 0; k < keyIndexes.size(); k++) {
            if (k > 0) {
                *out << ",";
            }
            *out << keyIndexes[k];
        }
        *out << "});\n";

        //TODO remove duplication
        *out << indentation << "AuxMap<"<<BITSETSIZE<<"> u" << mapVariableName << "({";
        predicatesUndefMaps[predName].insert("u" + mapVariableName);
        for (unsigned k = 0; k < keyIndexes.size(); k++) {
            if (k > 0) {
                *out << ",";
            }
            *out << keyIndexes[k];
        }
        *out << "});\n";
        declaredMaps.insert(mapVariableName);
    }
    //*out << indentation << "AuxMap<0> p" << predName << "({});\n";
    //*out << indentation << "AuxMap<0> u" << predName << "({});\n";
    //False literals are not needed
    //out << indentation << "AuxMap<0> n" << predName << "({});\n";
}

// //adding facts that appear into programs to the factory
// void CompilationManager::addFacts(){
//     for(Rule* r : builder->getAllRules()){
//         if(r->isFact()){
//             for(Literal lit : r->getHead()){
//                 //fact (add literals as true)
//                 if(r->getHead()->getDisjunction().size() == 1){
//                     //*out << indentation << "factory.addNewTuple()";
//                 }
//                 else{ //disjunctive fact (add literals as undefined)

//                 }
//             }
//         }
//     }
// }

void CompilationManager::compileRule(Rule* rule, std::vector<std::string>& recursiveDep){
    const Body* body = rule->getBody();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";
    closingParenthesis++;
    for(unsigned i = 0; i < body->getConjunction().size(); ++i){
        Literal* lit = body->getConjunction().at(i);
        if( !lit->isNegative()){
            std::string mapVariableName = lit->getIdentifier() + "_";

            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t)) || ! lit->getTerms().at(t)->isVariable()){
                    //std::cout<< "Searching " << lit->getTermAt(t) <<", but I didn't find it\n";
                    mapVariableName += std::to_string(t) + "_";
                }
            }
            *out << indentation << "const std::vector<int>* tuples;\n";
            *out << indentation << "tuples = &p" << mapVariableName << ".getValuesVec({";
            printLiteralTuple(lit, boundVariables);
            *out << "});\n";
            *out << indentation << "const std::vector<int>* tuplesU = &u" << mapVariableName << ".getValuesVec({";
            printLiteralTuple(lit, boundVariables);
            *out << "});\n";
            // *out << indentation << "const Tuple* tupleU = NULL;\n";
                            
            *out << indentation++ << "for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){\n";
            *out << indentation << "const Tuple * tuple" << i << " = NULL;\n";
            *out << indentation++ << "if(i < tuples->size()){\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuples->at(i));\n";
            // *out << indentation++ << "if(tuplesU != &EMPTY_TUPLES_VEC) {\n";
            // *out << indentation << "tupleU = NULL;\n";
            // *out << --indentation << "}\n";
            *out << --indentation << "}\n";
            *out << indentation++ << "else {\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));\n";
            // *out << indentation << "tupleU = tuple" << i << ";\n";
            //*out << indentation << "tupleUNegated = false;\n";
            *out << --indentation << "}\n";
            closingParenthesis++;
        }
        if (!lit->isNegative() || (i == 0)){
            std::unordered_set<std::string> declaredVariables;
            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t))){
                    *out << indentation <<"int " << lit->getTermAt(t)<< " = (*tuple" << i <<")[" << t <<"];\n"; 
                    declaredVariables.insert(lit->getTermAt(t));
                }
            }
        }

        if (!body->getConjunction().at(i)->isBound(boundVariables)) {
            body->getConjunction().at(i)->addVariablesToSet(boundVariables);
        }
        if(i == body->getConjunction().size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            // add all literals in the head to the factory
            bool insertAsUndef = false;
            if(rule->getHead()->getDisjunction().size() > 1)
                insertAsUndef = true;

            *out << indentation << "vector<int> terms;\n";
            //*out << indentation << "vector<std::pair<std::string, int>> variableNameToID;\n";
            *out << indentation << "vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;\n";
            *out << indentation << "Tuple* t;\n";
            *out << indentation << "std::pair<const TupleLight *, bool> insertResult;\n";
            *out << indentation << "bool alreadyInFactory = false;\n";
            //*out << indentation << "std::string representation = \"\";\n";
            unsigned index = 0;
            for(Literal* lit : rule->getHead()->getDisjunction()){
                *out << indentation << "vector<std::pair<std::string, int>> variableNameToID_" << index << ";\n";
                //*out << indentation << "representation += \"" << lit->getIdentifier() << "\";\n";
                //*out << indentation << "representation += \"(\";\n";
                for(TermBase* t : lit->getTerms()){
                    //*out << indentation << "ConstantsManager::getInstance().mapConstant()";
                    *out << indentation << "terms.push_back(" << t->getRepresentation() <<");\n";
                    *out << indentation << "variableNameToID_" << index << ".push_back(std::make_pair(\"" << t->getRepresentation() << "\", " << t->getRepresentation() << "));\n";
                    //*out << indentation << "representation += ConstantsManager::getInstance().unmapConstant(" << t->getRepresentation() << ");\n";
                    //*out << indentation << "representation += \",\";\n";
                }
                //*out << indentation << "representation +=\").\";\n";
                //if rule contains some literals that are in recursive dependency add them to the generation stack
                for(int i = 0; i < recursiveDep.size(); ++i){
                    if(recursiveDep[i] == lit->getIDAndArity()){
                        *out << indentation++ << "if(factory.find(terms, predicateToID[\""<< lit->getIdentifier() << "\"]) != NULL){\n";
                        *out << indentation << "alreadyInFactory = true;\n";
                        *out << --indentation << "}\n";
                    }
                }   

                *out << indentation++ << "if(!alreadyInFactory){\n";
                *out << indentation << "t = factory.addNewInternalTuple(terms, predicateToID[\"" << lit->getIdentifier() << "\"]);\n";
                *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                if(recursiveDep.size() > 0)
                    *out << indentation << "generatedStack.push_back(t->getId());\n";
                *out << indentation << "literalsAndVariables.push_back(std::make_pair(\"" << lit->getIdentifier() << "\", variableNameToID_" << index << "));\n";
                if(insertAsUndef)
                    *out << indentation << "insertUndef(insertResult);\n";
                else
                    *out << indentation << "insertTrue(insertResult);\n";
                    
                *out << --indentation << "}\n";
                *out << indentation << "terms.clear();\n";
                //*out << indentation << "variableNameToID.clear();\n";

                index++;
            }
            *out << indentation << "printGeneratedFromRule(literalsAndVariables);\n";
        }
        
    }

    for (unsigned i = 0; i < closingParenthesis; i++) {
        *out << --indentation << "}//close par\n";
    }
}

void CompilationManager::printLiteralTuple(const Literal* l) {
    for (unsigned t = 0; t < l->getArity(); t++) {
        if (t > 0) {
            *out << ", ";
        }
        if (!l->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(l->getTermAt(t))) {
            *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(l->getTermAt(t)) << "\")";
        } else {
            *out << l->getTermAt(t);
        }
    }


}

void CompilationManager::printLiteralTuple(const Literal* lit, const std::unordered_set<std::string> & boundVariables) {
    bool first = true;
    for (unsigned t = 0; t < lit->getArity(); t++) {
        if (!lit->getTerms().at(t)->isVariable() || boundVariables.count(lit->getTermAt(t))) {
            if (!first) {
                *out << ", ";
            }
            if (!lit->getTerms().at(t)->isVariable() && !sharedFunc::isInteger(lit->getTermAt(t))) {
                *out << "ConstantsManager::getInstance().mapConstant(\"" << sharedFunc::escapeDoubleQuotes(lit->getTermAt(t)) << "\")";
            } else {
                *out << lit->getTermAt(t);
            }
            first = false;
        }
    }


}

void CompilationManager::declareDataStructures(Rule* r) {
    std::unordered_set<std::string> boundVariables;
    // if (start < r.getBodySize()) {
    //     r.getFormulas().at(start)->addVariablesToSet(boundVariables);
    // }else{
    //     if(start > r.getFormulas().size()){
    //         for(unsigned k = 0; k < r.getHead()[0].getAriety(); k++){
    //             if(r.getHead()[0].isVariableTermAt(k)){
    //                 boundVariables.insert(r.getHead()[0].getTermAt(k));
    //             }
    //         }
    //     }
    // }

    //const std::vector<unsigned> & joinOrder = r.getOrderedBodyIndexesByStarter(start);
    //unsigned i = 1;
    //if (start >= r.getBodySize()) {
    //    i = 0;
    //}else{
    
    // const Literal* lit = r->getBody()->getConjunction().at(0);
    // std::string mapVariableName=lit->getPredicateName()+"_";
    // std::vector<unsigned> keyIndexes;
    // declareAuxMap(mapVariableName, keyIndexes, lit->getIdentifier());

    for(unsigned i = 0 ; i < r->getBody()->getConjunction().size(); i++){
        Literal* li = r->getBody()->getConjunction().at(i);
        if(!li->isNegative() && !li->isBound(boundVariables)){
            // std::cout<<"Declare map for: ";
            // li->print();
            // std::cout<<std::endl;
            std::vector< unsigned > keyIndexes;
            std::string mapVariableName = li->getIdentifier() + "_";
            for(unsigned tiIndex = 0; tiIndex < li->getTerms().size(); tiIndex++){
                if((li->getTerms().at(tiIndex)->isVariable() && boundVariables.count(li->getTermAt(tiIndex))) || !li->getTerms().at(tiIndex)->isVariable()){
                    mapVariableName += std::to_string(tiIndex) + "_";
                    keyIndexes.push_back(tiIndex);
                }
            }
            declareAuxMap(mapVariableName, keyIndexes, li->getIdentifier());
        }
        li->addVariablesToSet(boundVariables);
    }
}

void CompilationManager::findExitRules(std::vector<unsigned>& recursiveComponent, Program* program, std::vector<unsigned>& exitRules, std::vector<std::string>& recursiveDep){
    std::vector<Rule*> componentRules;
    program->getRulesByID(recursiveComponent, componentRules);

    bool isExitRule;
    for(unsigned i = 0; i < componentRules.size(); ++i){
        isExitRule = true;
        for(Literal* l : componentRules[i]->getBody()->getConjunction()){
            for(unsigned j = 0; j < componentRules.size(); ++j){
                if(componentRules[j]->containsLiteralInHead(l)){
                    isExitRule = false;
                    //add recursive dep on lieral l of rule[i] 
                    if(std::find(recursiveDep.begin(), recursiveDep.end(), l->getIDAndArity()) == recursiveDep.end()){
                        recursiveDep.push_back(l->getIDAndArity());
                    }
                    //break;
                }

            }
            if(!isExitRule)
                break;
        }
        if(isExitRule)
            exitRules.push_back(componentRules[i]->getID());
    }
}

void CompilationManager::compileRecursiveComponent(Program* program, std::vector<unsigned>& recursiveComponent){
    *out<< indentation << "//---------------------------------------Strongly connected component------------------------\n";
    *out<< indentation++ << "{\n";

    std::vector<unsigned> exitRules;
    std::vector<std::string> recursiveDep;
    findExitRules(recursiveComponent, program, exitRules, recursiveDep);
    
    if(recursiveDep.size() > 0)
        *out<< indentation << "std::vector<int> generatedStack;\n";
    
    for(unsigned i = 0; i < exitRules.size(); ++i){
        compileRule(program->getRuleByID(exitRules[i]), recursiveDep);
        recursiveComponent.erase(recursiveComponent.begin() + i);
    }
    
    if(recursiveDep.size() > 0){
        *out<< indentation++ << "while(! generatedStack.empty()){\n";
        *out<< indentation << "generatedStack.pop_back();\n"; 
    }

    for(unsigned j = 0; j < recursiveComponent.size(); ++j){
        compileRule(program->getRuleByID(recursiveComponent[j]), recursiveDep);
    }
    if(recursiveDep.size() > 0)
        *out<< --indentation << "}\n";
    //while not stack empty (remember to add facts that are from recursive rules)
    //compilation of recursive rules...
    //...
    //if something new has been generated, add it to the stack and go on
    *out<< --indentation << "}\n";
}

void CompilationManager::getRulesFromPredicateIds(Program * program, std::vector<unsigned>& preds, std::vector<unsigned>& rules){
    for(unsigned p = 0; p < preds.size(); ++p){
        for(Rule* r : program->getRules()){
            if(r->containsLiteralInHead(preds[p]) && std::find(rules.begin(), rules.end(), r->getID()) == rules.end())
                rules.push_back(r->getID());
        }
    }
}