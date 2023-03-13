#include "CompilationManagerASP.h"
#include "../DataStructures/TupleFactory.h"
#include "PreCompilerASP.h"
#include <unordered_map>


void CompilationManagerASP::generateProgram(Program* program){
    *out << indentation << "#include <chrono>\n";
    *out << indentation << "#include \"Executor.h\"\n";
    *out << indentation << "#include \"../DataStructures/ConstantsManager.h\"\n";
    *out << indentation << "#include \"../DataStructures/IndexedSet.h\"\n";
    *out << indentation << "typedef TupleLight Tuple;\n";
    *out << indentation << "template<size_t S>\n";
    *out << indentation << "using AuxMap = AuxiliaryMapSmart<S> ;\n";
    *out << indentation << "const std::vector<int> EMPTY_TUPLES_VEC;\n";
    *out << indentation << "const IndexedSet EMPTY_TUPLES_SET;\n";
    *out << indentation << "\n";

    *out << indentation << "std::vector<std::string> Executor::predicateIds;\n";

    for(auto lit : program->getPredicatesID()){
       *out << indentation << "const int _" << lit.first << " = " << lit.second << ";\n"; 
    }

    for(auto lit : program->getPredicatesID()){
        declareAuxMap(lit.first+"_", {}, lit.first);
    }
    
    //get default sort of literals for both rules and choice rules
    for(auto rule : program->getRules()){
        rule->sortLiteralsInBody(-1);
    }
    for(auto rule : program->getChoiceRules()){
        rule->sortLiteralsInBody(-1);
    }
    

    //DEP GRAPH
    //Dependency graph computation
    std::unordered_map<unsigned, unsigned> predicateNodeMapping;
	DependencyGraphHandler::getInstance().createGraph(program, predicateNodeMapping);
    //statifications
    //Each layer contains the ids of its IDB predicates
    //In order to find the rules that are part of each layer a complete search of rules needs to be done  
	std::vector<std::vector<unsigned>> layers = DependencyGraphHandler::getInstance().getProgramLayers();
	DependencyGraphHandler::getInstance().printProgramLayers(predicateNodeMapping);
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
        getRulesFromPredicateIds(program, effectiveLiteralsIDs, rulesForComponent);
        std::vector<unsigned> exitRules;
        std::vector<std::string> recursiveDep;
        findExitRules(rulesForComponent, program, exitRules, recursiveDep);
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

    //declare maps for each starter
    for(Rule* rule : program->getRules()){
        declareDataStructures(rule);
    }

    //assuming that choiceRules are already sorted
    for(ChoiceRule* rule : program->getChoiceRules()){
        declareDataStructures(rule);
    }

    
    //print function
    *out << indentation++ << "void printTuple(const Tuple* t){\n";

    *out << indentation << "std::cout << Executor::predicateIds[t->getPredicateName()] << \"(\";\n";
    *out << indentation++ << "for(int i=0;i<t->size();i++){\n";
    *out << indentation << "if(i>0) std::cout << \",\";\n";
    *out << indentation << "std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));\n";
    *out << --indentation << "}\n";
    *out << indentation << "std::cout << \")\"<<std::endl;\n";
    *out << --indentation << "}\n";
    
    *out << indentation++ << "void Executor::init(){\n";
    std::vector<std::pair<std::string, unsigned>>predIDPair;
    for(auto lit : program->getPredicatesID()){
        predIDPair.push_back(std::make_pair(lit.first, lit.second));
        
        *out << indentation << "predicateToID.insert({\"" << lit.first << "\", _" << lit.first<< "});\n";
        *out << indentation <<"factory.addPredicate();\n";
    }

    std::sort(predIDPair.begin(), predIDPair.end(), [](auto &left, auto &right) {
    return left.second < right.second;
    });
    for(auto& predNameID : predIDPair){
        *out << indentation << "Executor::predicateIds.push_back(\"" << predNameID.first << "\");\n";
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
    
    //TODO remove
    //insert parsered facts into factory
    // *out << indentation++ << "void Executor::insertFactIntoFactory(const Literal& lit, bool disjunctiveFact){\n";
    // //assuming that we only have a fact if the body of the rule is empty
    // //check the case in which the body is ground and made of facts
    // *out << indentation << "vector<int> terms;\n";
    // *out << indentation++ << "for(TermBase* term : lit.getTerms()){\n";
    // *out << indentation++ << "if(!term->isVariable()){\n";
    // *out << indentation << "int mappedValue = ConstantsManager::getInstance().mapConstant(term->getRepresentation());\n";
    // *out << indentation << "terms.push_back(mappedValue);\n";
    // *out << --indentation << "}\n";
    // *out << --indentation << "}\n";
    // *out << indentation << "Tuple* t = factory.addNewInternalTuple(terms, predicateToID[lit.getIdentifier()]);\n";
    // *out << indentation++ << "if(!disjunctiveFact){\n";
    // *out << indentation << "const auto& insertResult = t->setStatus(TruthStatus::True);\n";
    // *out << indentation << "insertTrue(insertResult);\n";
    // *out << --indentation << "}\n";
    // *out << indentation++ << "else{\n";
    // *out << indentation << "const auto& insertResult = t->setStatus(TruthStatus::Undef);\n";
    // *out << indentation << "insertUndef(insertResult);\n";
    // *out << --indentation << "}\n";
    // *out << --indentation << "}\n";

    *out << indentation++ << "void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){\n";
    *out << indentation++ << "if(!disjunctiveFact){\n";
    *out << indentation << "const auto& insertResult = t->setStatus(TruthStatus::True);\n";
    *out << indentation << "insertTrue(insertResult);\n";
    *out << --indentation << "}\n";
    *out << indentation++ << "else{\n";
    *out << indentation << "const auto& insertResult = t->setStatus(TruthStatus::Undef);\n";
    *out << indentation << "insertUndef(insertResult);\n";
    *out << --indentation << "}\n";
    *out << indentation << "printTuple(t);\n";
    *out << --indentation << "}\n";



    *out << indentation++ << "void Executor::executeProgram(){\n";
    *out << indentation << "const Tuple dummyTuple = Tuple();\n";
    //addFacts();
    *out << indentation << "auto start = std::chrono::high_resolution_clock::now();\n";

    //compiling choiceRules that are not recursive(by definiton for now)
    // for(ChoiceRule* rule : program->getChoiceRules()){
    //     compileChoiceRule(rule);
    // }
    std::unordered_set<unsigned> remainingPredicatesToRemove;
    for(auto kv : program->getPredicatesID()){
        remainingPredicatesToRemove.insert(kv.second);
    }
    std::unordered_set<unsigned> predicatesNotDefined;
    for(int i = layers.size()-1; i >= 0 ; --i){
        std::vector<unsigned> effectiveLiteralsIDs;
        for(unsigned j = 0; j < layers[i].size(); ++j){
            for(auto& it : predicateNodeMapping){
                if(it.second == layers[i][j]){
                    effectiveLiteralsIDs.push_back(it.first);
                    //std::cout << "working on "<<it.first<<std::endl;
                    //predicatesCompletelyDefined.insert(it.first);
                }
            }
        }
        //TODO IMPROVE
        std::vector<unsigned> rulesForComponent;
        getRulesFromPredicateIds(program, effectiveLiteralsIDs, rulesForComponent);
        compileRecursiveComponent(program, rulesForComponent);
        rulesForComponent.clear();
        //getRulesFromPredicateIds(program, effectiveLiteralsIDs, rulesForComponent);
        predicatesNotDefined.clear();
        //get all literals that are in some head or or body of any rule that has not been yet compiled
        // for(int j = i-1; j >= 0; --j){
        //     for(int k = 0; k < rulesForComponent.size(); ++k){
        //         std::cout <<"Rule " << rulesForComponent[k] << " not compiled....\n" 
        //         program->getRuleByID(rulesForComponent[k])->getAllLiterals(predicatesNotDefined);
        //     }
        // }
        for(Rule* r : program->getRules()){
            if(!r->isAlreadyCompiled()){
                r->getAllLiterals(predicatesNotDefined);
            }
        }
        //get literals that can be deleted as the difference between literals that
        //appear somewhere in rules and all the literals that has not been deleted since now
        std::unordered_set<unsigned> toDelete;
        for(auto pred : remainingPredicatesToRemove){
            if(predicatesNotDefined.count(pred) == 0){
                toDelete.insert(pred);
            }
        }
        deleteCompletelyDefinedPredicates(toDelete, program);
        for(auto pred: toDelete){
            remainingPredicatesToRemove.erase(pred);
        }
        //std::cout <<"Completed component\n";
    }
    //*out << indentation << "printGeneratedBase();\n";
    *out << indentation << "auto finish = std::chrono::high_resolution_clock::now();\n";
    *out << indentation << "//std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<\"ms\";\n";
    *out << --indentation<<"}\n";

    // *out << indentation++ << "void Executor::printGeneratedBase(){\n";
    // *out << indentation << "const std::vector<int>* tuples;\n";
    // for(auto& predID : program->getPredicatesID()){
        
    //     //print positive tuples
    //     *out << indentation << "tuples = &p" << predID.first << "_.getValuesVec({});\n";
    //     *out << indentation++ << "for(unsigned i = 0; i < tuples->size(); ++i){\n";
    //     *out << indentation << "printTuple(factory.getTupleFromInternalID(tuples->at(i)));\n";
    //     *out<< --indentation <<"}\n";
    //     //print undef tuples
    //     *out << indentation << "tuples = &u" << predID.first << "_.getValuesVec({});\n";
    //     *out << indentation++ << "for(unsigned i = 0; i < tuples->size(); ++i){\n";
    //     *out << indentation << "printTuple(factory.getTupleFromInternalID(tuples->at(i)));\n";
    //     *out<< --indentation <<"}\n"; 
    // }
    // *out << --indentation << "}\n";

    //TODO REMOVE BECAUSE IT IS NOT NEEDED
    //deleteCompletelyDefinedPredicates(remainingPredicatesToRemove, program);
}

void CompilationManagerASP::deleteCompletelyDefinedPredicates(std::unordered_set<unsigned>& toRemove, Program* program){
    std::cout <<"deleting: ";
    for(auto pred : toRemove){
        std::string predicateNameString = program->getPredicateByID(pred);
        *out << indentation << "//Removing tuples of predicates that have been completely defined\n";
        *out << indentation++ << "{\n";
        *out << indentation << "const std::vector<int>* tuplesToRemove;\n";
        *out << indentation << "tuplesToRemove = &p" << predicateNameString << "_.getValuesVec({});\n";
        *out << indentation++ << "for(unsigned i = 0; i< tuplesToRemove->size(); ++i){\n";
        //*out << indentation << "factory.removeFromCollisionsList(tuplesToRemove->at(i));\n";
        *out << indentation << "factory.destroyTuple(tuplesToRemove->at(i));\n";
        *out << --indentation <<"}\n";
        //*out << indentation << "p" << program->getPredicateByID(pred) << "_.clear();\n";
        *out << indentation << "tuplesToRemove = &u" << predicateNameString << "_.getValuesVec({});\n";
        *out << indentation++ << "for(unsigned i = 0; i< tuplesToRemove->size(); ++i){\n";
        //*out << indentation << "factory.removeFromCollisionsList(tuplesToRemove->at(i));\n";
        *out << indentation << "factory.destroyTuple(tuplesToRemove->at(i));\n";
        *out << --indentation <<"}\n";
        //*out << indentation << "u" << program->getPredicateByID(pred) << "_.clear();\n";
        for(std::string mapName : this->predicatesPositiveMaps[predicateNameString]){
            *out << indentation << mapName << ".clear();\n";   
        }
        for(std::string mapName : this->predicatesUndefMaps[predicateNameString]){
            *out << indentation << mapName << ".clear();\n";   
        }
        *out << --indentation <<"}\n";
        
        std::cout << pred << ", ";
    }
    std::cout<<std::endl;

}


void CompilationManagerASP::declareAuxMap(const std::string& mapVariableName, std::vector<unsigned> keyIndexes, const std::string& predName){
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
}



void CompilationManagerASP::compileRule(Rule* rule, std::vector<std::string>& recursiveDep, int starter = -1, bool compileAsExitRule = false){
    // if(currentRecursiveAtom != "")
    //     *out << indentation++ << "This a compilation from starter\n";
    rule->setAlreadyCompiled(true);
    const Body* body = rule->getBody();
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";
    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;
    closingParenthesis++;
    for(unsigned i = 0; i < rule->getOrderedBodyByStarter(starter).size(); ++i){
        if(i == 0){
            *out << indentation << "bool undefTuple" << i << "= false;\n";
        }
        else{
            *out << indentation << "bool undefTuple" << i << " = undefTuple" << i-1 <<";\n";
        }
        std::unordered_set<unsigned> alreadyCompiledBuiltIn;
        Literal* lit = body->getConjunction()[rule->getOrderedBodyByStarter(starter)[i]];
        // compiling rule with a starter given by a recursive literal
        if(starter != -1  && i == 0){
            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable())
                    variablesNameToTupleIndexes[lit->getTermAt(t)] = t; 
            }
            for(auto& nameIndex: variablesNameToTupleIndexes ){
                *out << indentation << "int " << nameIndex.first << " = (*recursiveTuple)[" << nameIndex.second << "];\n";
            }
            *out << indentation++ << "if(recursiveTupleUndef){\n";
            *out << indentation << "undefTuple" << i << " = true;\n";
            *out<< --indentation << "}\n";
            if (!lit->isBound(boundVariables)) {
                lit->addVariablesToSet(boundVariables);
            }
            //when recursive tuple is negative
            //TODO REMOVE WHEN NEGATIVE DEPENDENCIES WILL BE REMOVED
            if(lit->isNegative()){
                *out << indentation++ << "if(!recursiveTuple->isTrue()){\n";
                closingParenthesis++;
            }
        }
        else{
            if(!lit->isNegative() && lit->isBound(boundVariables)){
                *out << indentation << "const Tuple* tuple" << i << " = factory.find({";
                printLiteralTuple(lit, boundVariables); 
                *out << "}, _" << lit->getIdentifier() << ");\n";
                *out << indentation << "if(tuple" << i << " != NULL && " << "tuple" << i << "->isUndef()) undefTuple" << i << " = true;\n";
            }
            else if(!lit->isNegative()){
                std::string mapVariableName = lit->getIdentifier() + "_";

                for(unsigned t = 0; t < lit->getArity(); ++t){
                    if((lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t))) || ! lit->getTerms().at(t)->isVariable()){
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
                                
                *out << indentation++ << "for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){\n";
                //*out << indentation << "undefTuple" << i << " = false;\n";
                *out << indentation << "const Tuple * tuple" << i << " = NULL;\n";
                *out << indentation++ << "if(i < tuples->size()){\n";
                *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuples->at(i));\n";
                *out << --indentation << "}\n";
                *out << indentation++ << "else {\n";
                *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));\n";
                *out << indentation << "undefTuple" << i << " = true;\n";
                *out << --indentation << "}\n";
                closingParenthesis++;
            }
            else{//negative
                // *out << indentation << "const Tuple negativeTuple = Tuple({";
                // printLiteralTuple(lit, boundVariables);
                // *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &dummyTuple;\n";
                //ONLY IF WE HAVE NEGATIVE RECURSIVE DEPENDECY ON THIS ATOM
                //ONLY FOR UNSTRATIFIED PROGRAMS
                if(lit->isNegative() && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end()){
                    *out << indentation << "undefTuple" << i << " = true;\n";
                }
                *out << --indentation <<"}\n";
                *out << indentation++ << "else{\n";
                *out << indentation << "if(tuple" << i << "->isTrue())    tuple" << i << "= NULL;\n";
                *out << indentation << "else " << "undefTuple" << i << " = true;\n";
                *out << --indentation << "}\n";
            }


            *out << indentation++ << "if(tuple" << i << "!= NULL){\n";
            closingParenthesis++;
            if (!lit->isNegative() || (i == 0)){
                std::unordered_set<std::string> declaredVariables;
                for(unsigned t = 0; t < lit->getArity(); ++t){
                    if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t)) && !lit->getTerms().at(t)->isAnonVar()){
                        *out << indentation <<"int " << lit->getTermAt(t)<< " = (*tuple" << i <<")[" << t <<"];\n"; 
                        declaredVariables.insert(lit->getTermAt(t));
                    }
                }
            }

            if (!lit->isBound(boundVariables)) {
                lit->addVariablesToSet(boundVariables);
            }
            for(unsigned builtInIndex = 0; builtInIndex < rule->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = rule->getBody()->getBuiltInTerms().at(builtInIndex);
                if(!alreadyCompiledBuiltIn.count(builtInIndex)){
                    std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                    //builtIn is totally bound
                    if(bindingResult.second && bindingResult.first == ""){
                        if(currentBuiltIn->getMyOperator() != "=")
                            *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                        else
                            *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                        
                        alreadyCompiledBuiltIn.insert(builtInIndex);
                        //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        //rule->removeBuiltInAt(it);
                        closingParenthesis++;
                    }//X = Y+2 where X is not already bound, or X == Y
                    else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                        if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                        else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                    }
                }
            }
        }
        //to ensure that builtin are all compile.
        //Fix for the corner case in which a rule with a signle atom is being
        //compiled starting by a recursive literal and this rule contains some builtin  
        if(i == rule->getOrderedBodyByStarter(starter).size() - 1){
            for(unsigned builtInIndex = 0; builtInIndex < rule->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = rule->getBody()->getBuiltInTerms().at(builtInIndex);
                if(!alreadyCompiledBuiltIn.count(builtInIndex)){
                    std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                    //builtIn is totally bound
                    if(bindingResult.second && bindingResult.first == ""){
                        if(currentBuiltIn->getMyOperator() != "=")
                            *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                        else
                            *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                        
                        alreadyCompiledBuiltIn.insert(builtInIndex);
                        //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        //rule->removeBuiltInAt(it);
                        closingParenthesis++;
                    }//X = Y+2 where X is not already bound, or X == Y
                    else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                        if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                        else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                    }
                }
            }  
        }
        if(i == rule->getOrderedBodyByStarter(starter).size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            // add all literals in the head to the factory
            bool insertAsUndef = false;
            if(rule->getHead()->getDisjunction().size() > 1)
                insertAsUndef = true;

            //*out << indentation << "vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;\n";
            *out << indentation << "Tuple* t;\n";
            *out << indentation << "std::pair<const TupleLight *, bool> insertResult;\n";
            //*out << indentation << "bool alreadyInFactory = false;\n";
            unsigned index = 0;
            for(Literal* lit : rule->getHead()->getDisjunction()){

                //*out << indentation++ << "if(factory.find(";
                unsigned j = 0;
                std::string listOfTerms = "{";
                for(TermBase* t : lit->getTerms()){
                    if(j != lit->getTerms().size() -1){
                        if(!t->isVariable()){
                            listOfTerms += "ConstantsManager::getInstance().mapConstant(\"";
                            listOfTerms += sharedFunc::escapeDoubleQuotes(t->getRepresentation());
                            listOfTerms += "\")";
                        }
                        else
                            listOfTerms += t->getRepresentation();
                        listOfTerms += ",";
                    }
                    else{
                        if(!t->isVariable()){
                            listOfTerms += "ConstantsManager::getInstance().mapConstant(\"";
                            listOfTerms += sharedFunc::escapeDoubleQuotes(t->getRepresentation());
                            listOfTerms += "\")";
                        }
                        else
                            listOfTerms += t->getRepresentation();
                    }
                    j++;
                }
                listOfTerms += "}";
                //*out << listOfTerms<<", _" << lit->getIdentifier() << ") != NULL){\n";
                //*out << indentation << "alreadyInFactory = true;\n";
                //*out << --indentation << "}\n";


                //*out << indentation++ << "if(!alreadyInFactory){\n";
                *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
                *out << indentation++ << "if(t->isUnknown()){\n";
                *out << indentation << "printTuple(t);\n";
                if(!compileAsExitRule && recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end()){
                    *out << indentation << "generatedStack.push_back(t->getId());\n"; 
                }    
                if(insertAsUndef){
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                    *out << indentation << "insertUndef(insertResult);\n";
                }
                else{
                    *out << indentation++ << "if(" << "undefTuple" << i << "){\n";
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                    *out << indentation << "insertUndef(insertResult);\n";
                    *out << --indentation << "}\n";
                    *out << indentation++ << "else{\n";
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                    *out << indentation << "insertTrue(insertResult);\n";
                    *out << --indentation<<"}\n";
                }
                *out << --indentation << "}\n";
                *out << indentation++ << "else if(t->isUndef()){\n";
                if(insertAsUndef){
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                }
                else{
                    *out << indentation++ << "if(!" << "undefTuple" << i << "){\n";
                    *out << indentation << "factory.removeFromCollisionsList(t->getId());\n";
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                    *out << indentation << "insertTrue(insertResult);\n";
                    *out << --indentation << "}\n";
                }
                *out << --indentation << "}\n";

                // if(insertAsUndef)
                //     *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                // else
                //     *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                // // if this tuple was already inside the factory with different thruth satus
                // // then it should be removed from its collisionslist and added as
                // if(!insertAsUndef){
                //     *out << indentation++ << "if(insertResult.second && tupleWasUndef){\n";
                //     *out << indentation << "factory.removeFromCollisionsList(t->getId())";
                //     *out << indentation << "insertTrue(insertResult);\n";
                //     *out << --indentation << "}\n";
                // }

                // if(insertAsUndef)
                //     *out << indentation << "insertUndef(insertResult);\n";
                // else
                //     *out << indentation << "insertTrue(insertResult);\n";
                    
                // if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end())
                //     *out << indentation << "generatedStack.push_back(t->getId());\n";
                //*out << indentation << "literalsAndVariables.push_back(std::make_pair(\"" << lit->getIdentifier() << "\", variableNameToID_" << index << "));\n";
                //*out << --indentation << "}\n";
                //*out << indentation << "terms.clear();\n";
                //*out << indentation << "variableNameToID.clear();\n";

                index++;
            }

            // *out << indentation << "//negative literals saving\n";
            // if(negativeBodySize > 0){
            //     for(Literal* lit : body->getConjunction()){
            //         if(lit->isNegative()){
            //             unsigned j = 0;
            //             std::string listOfTerms = "{";
            //             for(TermBase* t : lit->getTerms()){
            //                 //*out << indentation << "ConstantsManager::getInstance().mapConstant()";
            //                 if(j != lit->getTerms().size() -1){
            //                     listOfTerms += t->getRepresentation();
            //                     listOfTerms += ",";
            //                 }
            //                 else{
            //                     listOfTerms += t->getRepresentation();
            //                     listOfTerms += "}";
            //                 }
            //                 //*out << indentation << "variableNameToID_" << index << ".push_back(std::make_pair(\"" << t->getRepresentation() << "\", " << t->getRepresentation() << "));\n";
            //                 j++;
            //             }
            //             // *out << indentation << "alreadyInFactory = false;\n";
            //             // *out << indentation++ << "if(factory.find(" << listOfTerms <<", _"<< lit->getIdentifier() << ") != NULL){\n";
            //             // *out << indentation << "alreadyInFactory = true;\n";
            //             // *out << --indentation << "}\n";

            //             //*out << indentation++ << "if(!alreadyInFactory){\n";
            //             *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
            //             *out << indentation++ << "if(t->isUnknown()){\n";
            //             if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end())
            //                 *out << indentation << "generatedStack.push_back(t->getId());\n";
            //             *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
            //             *out << indentation << "insertUndef(insertResult);\n";
            //             *out << --indentation << "}\n";
            //         }
            //     }


            //     //*out << --indentation << "}\n";
            //     //*out << indentation << "terms.clear();\n";
            // }
            //*out << indentation << "undefTuple = false;\n";
        }
        
    }

    for (int i = closingParenthesis; i > 0; --i) {
        *out << --indentation << "}//close par\n";
        // if(i < negativeBodySize){
        //     *out << indentation++ << "else{\n";
        //     *out << indentation << "udefLitsToSave.pop_back();\n";
        //     *out << --indentation << "}\n"; 
        // }
    }
}

void CompilationManagerASP::compileChoiceRule(ChoiceRule* rule, std::vector<std::string>& recursiveDep, int starter = -1, bool compileAsExitRule = false){
    rule->setAlreadyCompiled(true);
    const Body* body = rule->getBody();
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";
    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;

    closingParenthesis++;
    for(unsigned i = 0; i < rule->getOrderedBodyByStarter(starter).size(); ++i){
        std::unordered_set<unsigned> alreadyCompiledBuiltIn;
        Literal* lit = body->getConjunction()[rule->getOrderedBodyByStarter(starter)[i]];
        // compiling rule with a starter given by a recursive literal
        if(starter != -1  && i == 0){
            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable())
                    variablesNameToTupleIndexes[lit->getTermAt(t)] = t; 
            }
            for(auto& nameIndex: variablesNameToTupleIndexes ){
                *out << indentation << "int " << nameIndex.first << " = (*recursiveTuple)[" << nameIndex.second << "];\n";
            }
            if (!lit->isBound(boundVariables)) {
                lit->addVariablesToSet(boundVariables);
            }
            //when recursive tuple is negative
            //TODO REMOVE WHEN NEGATIVE DEPENDENCIES WILL BE REMOVED
            if(lit->isNegative()){
                *out << indentation++ << "if(!recursiveTuple->isTrue()){\n";
                closingParenthesis++;
            }
        }
        else{
            if(!lit->isNegative() && lit->isBound(boundVariables)){
                *out << indentation << "const Tuple* tuple" << i << " = factory.find({";
                printLiteralTuple(lit, boundVariables); 
                *out << "}, _" << lit->getIdentifier() << ");\n";
            }
            else if(!lit->isNegative()){
                std::string mapVariableName = lit->getIdentifier() + "_";

                for(unsigned t = 0; t < lit->getArity(); ++t){
                    if((lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t))) || ! lit->getTerms().at(t)->isVariable()){
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
                                
                *out << indentation++ << "for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){\n";
                *out << indentation << "const Tuple * tuple" << i << " = NULL;\n";
                *out << indentation++ << "if(i < tuples->size()){\n";
                *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuples->at(i));\n";
                *out << --indentation << "}\n";
                *out << indentation++ << "else {\n";
                *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));\n";
                *out << --indentation << "}\n";
                closingParenthesis++;
            }
            else{//negative
            //CHECK
                // *out << indentation << "const Tuple negativeTuple = Tuple({";
                // printLiteralTuple(lit, boundVariables);
                // *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &dummyTuple;\n";
                *out << --indentation <<"}\n";
                *out << indentation++ << "else{\n";
                *out << indentation << "if(tuple" << i << "->isTrue())    tuple" << i << "= NULL;\n";
                *out << --indentation << "}\n";
            }


            *out << indentation++ << "if(tuple" << i << "!= NULL){\n";
            closingParenthesis++;
            if (!lit->isNegative() || (i == 0)){
                std::unordered_set<std::string> declaredVariables;
                for(unsigned t = 0; t < lit->getArity(); ++t){
                    if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t)) && !lit->getTerms().at(t)->isAnonVar()){
                        *out << indentation <<"int " << lit->getTermAt(t)<< " = (*tuple" << i <<")[" << t <<"];\n"; 
                        declaredVariables.insert(lit->getTermAt(t));
                    }
                }
            }

            if (!lit->isBound(boundVariables)) {
                lit->addVariablesToSet(boundVariables);
            }
            for(unsigned builtInIndex = 0; builtInIndex < rule->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = rule->getBody()->getBuiltInTerms().at(builtInIndex);
                if(!alreadyCompiledBuiltIn.count(builtInIndex)){
                    std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                    //builtIn is totally bound
                    if(bindingResult.second && bindingResult.first == ""){
                        if(currentBuiltIn->getMyOperator() != "=")
                            *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                        else
                            *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                        
                        alreadyCompiledBuiltIn.insert(builtInIndex);

                        closingParenthesis++;
                    }//X = Y+2 where X is not already bound, or X == Y
                    else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                        if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                        }
                        else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                        }
                    }
                }
            }
        }
        //to ensure that builtin are all compile.
        //Fix for the corner case in which a rule with a signle atom is being
        //compiled starting by a recursive literal and this rule contains some builtin  
        if(i == rule->getOrderedBodyByStarter(starter).size() - 1){
            for(unsigned builtInIndex = 0; builtInIndex < rule->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = rule->getBody()->getBuiltInTerms().at(builtInIndex);
                if(!alreadyCompiledBuiltIn.count(builtInIndex)){
                    std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                    //builtIn is totally bound
                    if(bindingResult.second && bindingResult.first == ""){
                        if(currentBuiltIn->getMyOperator() != "=")
                            *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                        else
                            *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                        
                        alreadyCompiledBuiltIn.insert(builtInIndex);
                        //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        //rule->removeBuiltInAt(it);
                        closingParenthesis++;
                    }//X = Y+2 where X is not already bound, or X == Y
                    else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                        if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                        else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                    }
                }
            }  
        }
        if(i == rule->getOrderedBodyByStarter(starter).size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            // check that each body of choice elements is satisfied in order to add it to the factory
            // consider only those choice element that have as heas literal one of 
            // the literal that are considered in this recursive component
            for(auto& choiceElem : rule->getChoiceHead()){
                //if(std::find(recursiveDep.begin(), recursiveDep.end(), choiceElem.first->getIdentifier()) != recursiveDep.end())
                compileChoiceElement(choiceElem, compileAsExitRule);
            }
        }
        
    }

    for (unsigned i = 0; i < closingParenthesis; i++) {
        *out << --indentation << "}//close par\n";
        // if(i < negativeBodySize){
        //     *out << indentation++ << "else{\n";
        //     *out << indentation << "udefLitsToSave.pop_back();\n";
        //     *out << --indentation << "}\n"; 
        // }
    }
}

void CompilationManagerASP::compileChoiceElement(const std::pair<Literal*, Body*>& choiceElem, bool compileAsExitRule = false){
    const Body* body = choiceElem.second;
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";

    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;
    std::unordered_set<unsigned> alreadyCompiledBuiltIn;
    closingParenthesis++;
    for(unsigned i = 0; i < body->getConjunction().size(); ++i){
        Literal* lit = body->getConjunction()[i];
        // compiling rule with a starter given by a recursive literal

        if(!lit->isNegative() && lit->isBound(boundVariables)){
            *out << indentation << "const Tuple* tuple" << i << " = factory.find({";
            printLiteralTuple(lit, boundVariables); 
            *out << "}, _" << lit->getIdentifier() << ");\n";
        }
        else if(!lit->isNegative()){
            std::string mapVariableName = lit->getIdentifier() + "_";

            for(unsigned t = 0; t < lit->getArity(); ++t){
                if((lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t))) || ! lit->getTerms().at(t)->isVariable()){
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
                            
            *out << indentation++ << "for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){\n";
            *out << indentation << "const Tuple * tuple" << i << " = NULL;\n";
            *out << indentation++ << "if(i < tuples->size()){\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuples->at(i));\n";
            *out << --indentation << "}\n";
            *out << indentation++ << "else {\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));\n";
            *out << --indentation << "}\n";
            closingParenthesis++;
        }
        else{//negative
                // *out << indentation << "const Tuple negativeTuple = Tuple({";
                // printLiteralTuple(lit, boundVariables);
                // *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &dummyTuple;\n";
                *out << --indentation <<"}\n";
                *out << indentation++ << "else{\n";
                *out << indentation << "if(tuple" << i << "->isTrue())    tuple" << i << "= NULL;\n";
                *out << --indentation << "}\n";
        }


        *out << indentation++ << "if(tuple" << i << "!= NULL){\n";
        closingParenthesis++;
        if (!lit->isNegative() || (i == 0)){
            std::unordered_set<std::string> declaredVariables;
            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && !declaredVariables.count(lit->getTermAt(t)) && !lit->getTerms().at(t)->isAnonVar()){
                    *out << indentation <<"int " << lit->getTermAt(t)<< " = (*tuple" << i <<")[" << t <<"];\n"; 
                    declaredVariables.insert(lit->getTermAt(t));
                }
            }
        }

        if (!lit->isBound(boundVariables)) {
            lit->addVariablesToSet(boundVariables);
        }
        for(unsigned builtInIndex = 0; builtInIndex < body->getBuiltInTerms().size(); ++builtInIndex){
            BuiltInTerm* currentBuiltIn = body->getBuiltInTerms().at(builtInIndex);
            std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
            //builtIn is totally bound
            if(bindingResult.second && bindingResult.first == ""){
                if(currentBuiltIn->getMyOperator() != "=")
                    *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                else
                    *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                //std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                //choiceElem.second->removeBuiltInAt(it);
                alreadyCompiledBuiltIn.insert(builtInIndex);
                closingParenthesis++;
            }//X = Y+2 where X is not already bound, or X == Y
            else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    //std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                    //choiceElem.second->removeBuiltInAt(it);
                    alreadyCompiledBuiltIn.insert(builtInIndex);
                }
                else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    //std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                    //choiceElem.second->removeBuiltInAt(it);
                    alreadyCompiledBuiltIn.insert(builtInIndex);
                }
            }
        }
        //to ensure that builtin are all compile.
        //Fix for the corner case in which a rule with a signle atom is being
        //compiled starting by a recursive literal and this rule contains some builtin  
        if(i == body->getConjunction().size() - 1){
            for(unsigned builtInIndex = 0; builtInIndex < body->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = body->getBuiltInTerms().at(builtInIndex);
                if(!alreadyCompiledBuiltIn.count(builtInIndex)){
                    std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                    //builtIn is totally bound
                    if(bindingResult.second && bindingResult.first == ""){
                        if(currentBuiltIn->getMyOperator() != "=")
                            *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                        else
                            *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                        
                        alreadyCompiledBuiltIn.insert(builtInIndex);
                        //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        //rule->removeBuiltInAt(it);
                        closingParenthesis++;
                    }//X = Y+2 where X is not already bound, or X == Y
                    else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                        if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                        else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                            *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                            boundVariables.insert(bindingResult.first);
                            alreadyCompiledBuiltIn.insert(builtInIndex);
                            //std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                            //rule->removeBuiltInAt(it);
                        }
                    }
                }
            }  
        }
        if(i == body->getConjunction().size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            // add literal in choice head to the factory
            bool insertAsUndef = true;

            *out << indentation << "Tuple* t;\n";
            *out << indentation << "std::pair<const TupleLight *, bool> insertResult;\n";

            unsigned index = 0;
            unsigned j = 0;
            Literal* lit = choiceElem.first;
            std::string listOfTerms = "{";
            for(TermBase* t : lit->getTerms()){
                if(j != lit->getTerms().size() -1){
                    if(!t->isVariable()){
                        listOfTerms += "ConstantsManager::getInstance().mapConstant(\"";
                        listOfTerms += sharedFunc::escapeDoubleQuotes(t->getRepresentation());
                        listOfTerms += "\")";
                    }
                    else
                        listOfTerms += t->getRepresentation();
                    listOfTerms += ",";
                }
                else{
                    if(!t->isVariable()){
                        listOfTerms += "ConstantsManager::getInstance().mapConstant(\"";
                        listOfTerms += sharedFunc::escapeDoubleQuotes(t->getRepresentation());
                        listOfTerms += "\")";
                    }
                    else
                        listOfTerms += t->getRepresentation();
                }
                j++;
            }
            listOfTerms += "}";
            *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
            *out << indentation++ <<"if(t->isUnknown()){\n";
            *out << indentation << "printTuple(t);\n";
            // if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end()){
            //     *out << indentation << "generatedStack.push_back(t->getId());\n"; 
            // }    
            if(insertAsUndef){
                *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                *out << indentation << "insertUndef(insertResult);\n";
            }
            else{
                *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                *out << indentation << "insertTrue(insertResult);\n";
            }
            *out << --indentation << "}\n";
            *out << indentation++ << "else if(t->isUndef()){\n";
            if(insertAsUndef){
                *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
            }
            else{
                *out << indentation << "factory.removeFromCollisionsList(t->getId());\n";
                *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                *out << indentation << "insertTrue(insertResult);\n";
            }
            *out << --indentation << "}\n";
            index++;

            // *out << indentation << "//negative literals saving\n";
            // if(negativeBodySize > 0){
            //     for(Literal* lit : body->getConjunction()){
            //         if(lit->isNegative()){
            //             unsigned j = 0;
            //             std::string listOfTerms = "{";
            //             for(TermBase* t : lit->getTerms()){
            //                 if(j != lit->getTerms().size() -1){
            //                     listOfTerms += t->getRepresentation();
            //                     listOfTerms += ",";
            //                 }
            //                 else{
            //                     listOfTerms += t->getRepresentation();
            //                     listOfTerms += "}";
            //                 }
            //                 j++;
            //             }

            //             *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
            //             *out << indentation++ << "if(t->isUnknown()){\n";
            //             // if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end())
            //             //     *out << indentation << "generatedStack.push_back(t->getId());\n";
            //             *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
            //             *out << indentation << "insertUndef(insertResult);\n";
            //             *out << --indentation << "}\n";
            //         }
            //     }
            // }
        }
        
    }

    for (unsigned i = 0; i < closingParenthesis; i++) {
        *out << --indentation << "}//close par\n";
    }
}

void CompilationManagerASP::declareDataStructures(RuleBase* r) {
    std::unordered_set<std::string> boundVariables;

    //declaration for normal order grounding
    //assuming that each starter contains all predicates
    for(auto it : r->getStartersAndBody()){
        std::vector<unsigned> orderedBody = it.second;
        for(unsigned i = 0 ; i < orderedBody.size(); i++){
            Literal* li = r->getBody()->getConjunction().at(orderedBody[i]);
            if(!li->isNegative() && !li->isBound(boundVariables)){
                // std::cout<<"Declare map for: ";
                // li->print();
                // std::cout<<std::endl;
                std::vector<unsigned> keyIndexes;
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

            for(unsigned builtInIndex = 0; builtInIndex < r->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = r->getBody()->getBuiltInTerms().at(builtInIndex);
                std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                //builtIn is totally bound
                if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                    if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                        boundVariables.insert(bindingResult.first);
                    }
                    else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                        boundVariables.insert(bindingResult.first);
                    }
                }
            }
        }
        boundVariables.clear();
    }
}

void CompilationManagerASP::declareDataStructures(ChoiceRule* r) {
    std::unordered_set<std::string> boundVariables;

    //declare data structure considering choice rules as standard rules
    declareDataStructures((RuleBase*) r);
    
    //declaration for bodies of each choice (always assuming a fixed order of grounding)
    for(unsigned choiceIndex = 0; choiceIndex < r->getChoiceHead().size(); ++choiceIndex){
        Body* body = r->getChoiceHead().at(choiceIndex).second;
        for(unsigned i = 0 ; i < body->getConjunction().size(); i++){
            Literal* li = body->getConjunction().at(i);
            if(!li->isNegative() && !li->isBound(boundVariables)){
                // std::cout<<"Declare map for: ";
                // li->print();
                // std::cout<<std::endl;
                std::vector<unsigned> keyIndexes;
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

            for(unsigned builtInIndex = 0; builtInIndex < r->getBody()->getBuiltInTerms().size(); ++builtInIndex){
                BuiltInTerm* currentBuiltIn = r->getBody()->getBuiltInTerms().at(builtInIndex);
                std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                //builtIn is totally bound
                if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                    if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                        boundVariables.insert(bindingResult.first);
                    }
                    else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                        boundVariables.insert(bindingResult.first);
                    }
                }
            }
        }
    }
}

void CompilationManagerASP::compileRecursiveComponent(Program* program, std::vector<unsigned>& recursiveComponent){
    if(recursiveComponent.size() == 0)
        return;
    //std::cout << "compiling " << recursiveComponent.size() <<"rules\n";
    //for(unsigned i = 0; i < recursiveComponent.size(); ++i){
    //    std::cout <<"Compiling rule n: "<<recursiveComponent[i]<<std::endl;
    //}
    *out<< indentation << "//---------------------------------------Strongly connected component------------------------\n";
    *out<< indentation++ << "{\n";

    std::vector<unsigned> exitRules;
    std::vector<std::string> recursiveDep;
    findExitRules(recursiveComponent, program, exitRules, recursiveDep);
    //std::cout << "found " << exitRules.size() <<" exit rule\n";

    
    //check that you are actually compiling something
    //This is for the corner case of disjunction and choice rules that can be 
    //taken into consideration among different layers but shouldn't
    //because in the first component they appear they are completely defined (see SCC and arcs for more details)
    bool allRulesCompiledForComponent = true;

    for(unsigned i = 0; i < recursiveComponent.size(); ++i){
        if(!program->getRuleByID(recursiveComponent.at(i))->isAlreadyCompiled()){
            allRulesCompiledForComponent = false;
            break;
        } 
    }
    if(!allRulesCompiledForComponent){
        if(recursiveDep.size() > 0)
            *out<< indentation << "std::vector<int> generatedStack;\n";

        for(unsigned i = 0; i < exitRules.size(); ++i){
            RuleBase* rule = program->getRuleByID(exitRules[i]);
            if(rule->isChoiceRule() && !rule->isAlreadyCompiled()){
                compileChoiceRule(static_cast<ChoiceRule*>(rule), recursiveDep);
            }
            else if(rule->isClassicRule() && !rule->isAlreadyCompiled()){
                compileRule(static_cast<Rule*>(rule), recursiveDep, -1, true);
            }
            //if(rule == nullptr)
            //   std::cout<<"Something went wrong\n";
            std::vector<unsigned>::iterator it = std::find(recursiveComponent.begin(), recursiveComponent.end(), exitRules[i]);
            recursiveComponent.erase(it);
        }
        //component is totally recursive
        if(exitRules.size() == 0){
            //add all tuples in factory that are true or undef so that the component can generate
            //without need to do a preliminar grounding
            *out << indentation++ << "{//adding already existing tuple for predicates involved in recursion\n";
            *out << indentation << "const std::vector<int>* actualTuples;\n";
            for(unsigned i = 0; i < recursiveDep.size(); ++i){
                
                *out << indentation << "actualTuples = &p" << recursiveDep[i] << "_.getValuesVec({});\n";
                *out << indentation << "for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());\n";
            
                *out << indentation << "actualTuples = &u" << recursiveDep[i] << "_.getValuesVec({});\n";
                *out << indentation << "for(int i = 0; i < actualTuples->size(); ++i) generatedStack.push_back((factory.getTupleFromInternalID(actualTuples->at(i)))->getId());\n";
            }
            *out << --indentation << "}\n";
        }
        for(unsigned i = 0; i < recursiveComponent.size(); ++i){
            RuleBase* rule = program->getRuleByID(recursiveComponent[i]);
            if(rule->isChoiceRule() && !rule->isAlreadyCompiled()){
                compileChoiceRule(static_cast<ChoiceRule*>(rule), recursiveDep);
            }
            else if(rule->isClassicRule() && !rule->isAlreadyCompiled()){
                compileRule(static_cast<Rule*>(rule), recursiveDep);
            }
        }

        
        if(recursiveDep.size() > 0){
            *out << indentation++ << "while(! generatedStack.empty()){\n";
            *out << indentation << "const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());\n";
            *out << indentation << "generatedStack.pop_back();\n";
            *out << indentation << "unsigned literalName = recursiveTuple->getPredicateName();\n";
            *out << indentation << "bool recursiveTupleUndef = recursiveTuple->isUndef();\n";
            //if recursive[i] -> do a specific compilation
            for(unsigned i = 0; i < recursiveDep.size(); ++i){
                *out << indentation++ << "if(literalName == _"<< recursiveDep[i] <<"){\n";
                    for(unsigned j = 0; j < recursiveComponent.size(); ++j){
                        if(program->getRuleByID(recursiveComponent[j])->containsLiteralInBody(recursiveDep[i])){
                            //compile several times basing on how many occurrencies of the predicate are present in the chosen rule
                            for(unsigned k  = 0; k < program->getRuleByID(recursiveComponent[j])->getBody()->getConjunction().size(); ++k)
                            if(program->getRuleByID(recursiveComponent[j])->getBody()->getConjunction()[k]->getIdentifier() == recursiveDep[i]){
                                if(program->getRuleByID(recursiveComponent[j])->isChoiceRule() && !(exitRules.size() == 0 && program->getRuleByID(recursiveComponent[j])->isAlreadyCompiled()))
                                    compileChoiceRule(static_cast<ChoiceRule*>(program->getRuleByID(recursiveComponent[j])), recursiveDep,k);
                                else if(program->getRuleByID(recursiveComponent[j])->isClassicRule())
                                    compileRule(static_cast<Rule*>(program->getRuleByID(recursiveComponent[j])), recursiveDep, k);
                            }
                        }
                    }
                *out << --indentation << "}\n";
            
            }
        }else { //TODO REMOVE because this scenario is not possible
            for(unsigned j = 0; j < recursiveComponent.size(); ++j){
                RuleBase* ruleBase = program->getRuleByID(recursiveComponent[j]);
                if(ruleBase->isChoiceRule() && ! ruleBase->isAlreadyCompiled())
                    compileChoiceRule(static_cast<ChoiceRule*>(ruleBase), recursiveDep);
                else if(ruleBase->isClassicRule() && !ruleBase->isAlreadyCompiled())
                    compileRule(static_cast<Rule*>(ruleBase), recursiveDep);
            }
        }


        if(recursiveDep.size() > 0)
            *out<< --indentation << "}\n";
    }
    *out<< --indentation << "}\n";
}