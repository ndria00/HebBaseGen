#include "CompilationManager.h"
#include "../DataStructures/TupleFactory.h"
#include <unordered_map>

CompilationManager::CompilationManager(Builder* builder){
    this->builder = builder;
    indentation = Indentation(0);
    declaredMaps = std::set<std::string>();
}

void CompilationManager::generateProgram(Program* program){
    *out << indentation << "#include <chrono>\n";
    *out << indentation << "#include \"Executor.h\"\n";
    *out << indentation << "#include \"../DataStructures/ConstantsManager.h\"\n";
    //*out << indentation << "#include \"../DataStructures/AuxiliaryMapSmart.h\"\n";
    //*out << indentation << "#include \"../DataStructures/TupleFactory.h\"\n";
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
    //*out << "TupleFactory factory;\n";
    *out << indentation << "std::vector<std::string> Executor::predicateIds;\n";

    for(auto lit : program->getPredicatesID()){
       *out << indentation << "const int _" << lit.first << " = " << lit.second << ";\n"; 
    }

    for(auto lit : program->getPredicatesID()){
        declareAuxMap(lit.first+"_", {}, lit.first);
    }
    
    //sort rule literals
    for(auto rule : program->getRules()){
        rule->sortLiteralsInBody(-1);
    }
    
    // for(auto rule : program->getRules()){
    //     declareDataStructures(rule);
    // }

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
                Rule* rule = program->getRuleByID(rulesForComponent[r]);
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

    //init function
    //*out << indentation << "void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& );\n\n";
    
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
    *out << --indentation << "}\n";



    *out << indentation++ << "void Executor::executeProgram(){\n";
    //addFacts();
    *out << indentation << "auto start = std::chrono::high_resolution_clock::now();\n";
    *out << indentation <<"//TODO\n";

    //compiling choiceRules that are not recursive(by definiton for now)
    for(ChoiceRule* rule : program->getChoiceRules()){
        compileChoiceRule(rule);
    }

    for(int i = layers.size()-1; i >= 0 ; --i){
        std::vector<unsigned> effectiveLiteralsIDs;
        for(unsigned j = 0; j < layers[i].size(); ++j){
            for(auto& it : predicateNodeMapping){
                if(it.second == layers[i][j]){
                    effectiveLiteralsIDs.push_back(it.first);
                    //std::cout << "working on "<<it.first<<std::endl;
                }
            }
        }
        std::vector<unsigned> rulesForComponent;
        getRulesFromPredicateIds(program, effectiveLiteralsIDs, rulesForComponent);
        compileRecursiveComponent(program, rulesForComponent);
    }
    *out << indentation << "printGeneratedBase();\n";
    *out << indentation << "auto finish = std::chrono::high_resolution_clock::now();\n";
    *out << indentation << "std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<\"ms\";\n";
    *out << --indentation<<"}\n";
    //TODO check and remove if disjuction should not be printed
    //print rule
    // *out << indentation++ << "void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& literalsVariables){\n";
    // //for each literal
    // *out << indentation++ << "for(unsigned i  = 0; i < literalsVariables.size(); ++i){\n";
    // *out << indentation << "std::cout<<literalsVariables[i].first;\n";
    // *out << indentation++ << "for(unsigned j = 0; j < literalsVariables[i].second.size(); ++j){\n";
    // *out << indentation++ << "if(j== 0 && literalsVariables[i].second.size() > 0){\n";
    // *out << indentation << "std::cout<< \"(\";\n";
    // *out << --indentation << "}\n";
    // *out << indentation <<"std::cout << ConstantsManager::getInstance().unmapConstant(literalsVariables[i].second[j].second);\n";
    // *out << indentation++ << "if(literalsVariables[i].second.size() > 1 && j < literalsVariables[i].second.size() - 1){\n";
    // *out << indentation << "std::cout << \",\";\n";
    // *out << --indentation << "}\n";
    // *out << indentation++ << "if(j == literalsVariables[i].second.size() - 1 && literalsVariables[i].second.size() > 0){\n";
    // *out << indentation << "std::cout << \")\";\n";
    // *out << --indentation <<"}\n";
    // *out << --indentation << "}\n";
    // *out << indentation++ << "if(literalsVariables.size() > 1 && i < literalsVariables.size() - 1){\n";
    // *out << indentation << "std::cout << \"|\";\n";
    // *out << --indentation << "}\n";
    // *out << indentation++ <<"if(i == literalsVariables.size() -1){\n";
    // *out << indentation << "std::cout<<\". \";\n";
    // *out << --indentation << "}\n";
    // *out << --indentation << "}\n";
    // *out << --indentation << "}\n";

    *out << indentation++ << "void Executor::printGeneratedBase(){\n";
    *out << indentation << "const std::vector<int>* tuples;\n";
    for(auto& predID : program->getPredicatesID()){
        
        //print positive tuples
        *out << indentation << "tuples = &p" << predID.first << "_.getValuesVec({});\n";
        *out << indentation++ << "for(unsigned i = 0; i < tuples->size(); ++i){\n";
        *out << indentation << "printTuple(factory.getTupleFromInternalID(tuples->at(i)));\n";
        *out<< --indentation <<"}\n";
        //print undef tuples
        *out << indentation << "tuples = &u" << predID.first << "_.getValuesVec({});\n";
        *out << indentation++ << "for(unsigned i = 0; i < tuples->size(); ++i){\n";
        *out << indentation << "printTuple(factory.getTupleFromInternalID(tuples->at(i)));\n";
        *out<< --indentation <<"}\n"; 
    }
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
}



void CompilationManager::compileRule(Rule* rule, std::vector<std::string>& recursiveDep, int starter = -1){
    // if(currentRecursiveAtom != "")
    //     *out << indentation++ << "This a compilation from starter\n";

    const Body* body = rule->getBody();
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";

    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;

    // std::vector<unsigned> selfRecursiveIndexes;
    // rule->getRecursiveIndexes(selfRecursiveIndexes);

    // if(selfRecursiveIndexes.size() == 1){
    //     //foreach recursive literal print an if that determines which and how many variables are to be declared
    //     for(unsigned i = 0; i < selfRecursiveIndexes.size(); ++i){
    //         unsigned j = 0;
    //         Literal* recursiveLit = rule->getBody()->getConjunction().at(selfRecursiveIndexes[i]);

    //         for(unsigned t = 0; t < recursiveLit->getArity(); ++t){
    //             if(recursiveLit->getTerms().at(t)->isVariable())
    //                 variablesNameToTupleIndexes[recursiveLit->getTermAt(t)] = t; 
    //         }

    //         if (!recursiveLit->isBound(boundVariables)) {
    //             recursiveLit->addVariablesToSet(boundVariables);
    //         }
    //     }
            

    // }

    closingParenthesis++;
    for(unsigned i = 0; i < rule->getOrderedBodyByStarter(starter).size(); ++i){
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
            else{//negative
                *out << indentation << "const Tuple negativeTuple = Tuple({";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &negativeTuple;\n";
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
                    if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t))){
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
                std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
                //builtIn is totally bound
                if(bindingResult.second && bindingResult.first == ""){
                    if(currentBuiltIn->getMyOperator() != "=")
                        *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                    else
                        *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                    std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                    rule->removeBuiltInAt(it);
                    closingParenthesis++;
                }//X = Y+2 where X is not already bound, or X == Y
                else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                    if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                        *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                        boundVariables.insert(bindingResult.first);
                        std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        rule->removeBuiltInAt(it);
                    }
                    else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                        *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                        boundVariables.insert(bindingResult.first);
                        std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                        rule->removeBuiltInAt(it);
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
                        listOfTerms += "}";
                    }
                    j++;
                }
                //*out << listOfTerms<<", _" << lit->getIdentifier() << ") != NULL){\n";
                //*out << indentation << "alreadyInFactory = true;\n";
                //*out << --indentation << "}\n";


                //*out << indentation++ << "if(!alreadyInFactory){\n";
                *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
                *out << indentation++ <<"if(t->isUnknown()){\n";
                if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end()){
                    *out << indentation << "generatedStack.push_back(t->getId());\n"; 
                }    
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
                    *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                    *out << indentation << "factory.removeFromCollisionsList(t->getId());\n";
                    *out << indentation << "insertTrue(insertResult);\n";
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

void CompilationManager::compileChoiceRule(ChoiceRule* rule){
    const Body* body = rule->getBody();
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";

    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;

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
                *out << indentation << "const Tuple negativeTuple = Tuple({";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &negativeTuple;\n";
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
                if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t))){
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
            std::pair<std::string, bool> bindingResult = currentBuiltIn->canBind(boundVariables);
            //builtIn is totally bound
            if(bindingResult.second && bindingResult.first == ""){
                if(currentBuiltIn->getMyOperator() != "=")
                    *out << indentation++ <<"if(" << currentBuiltIn->toString()<< "){\n";
                else
                    *out << indentation++ <<"if(" << currentBuiltIn->getLeftExpr()->getRepresentation() << " == " <<currentBuiltIn->getRightExpr()->getRepresentation() << "){\n";
                std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                rule->removeBuiltInAt(it);
                closingParenthesis++;
            }//X = Y+2 where X is not already bound, or X == Y
            else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                    rule->removeBuiltInAt(it);
                }
                else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    std::vector<BuiltInTerm*>::const_iterator it = rule->getBody()->getBuiltInTerms().begin() + builtInIndex;
                    rule->removeBuiltInAt(it);
                }
            }
        }
        if(i == body->getConjunction().size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            //CHECK THAT EACH BODY OF THE CHOICE ELEMENTS IS SATISFIED IN ORDER TO ADD THEM TO THE FACTORY
            for(auto& choiceElem : rule->getChoiceHead()){
                compileChoiceElement(choiceElem);
            }
        }
        
    }

    for (unsigned i = 0; i < closingParenthesis; i++) {
        *out << --indentation << "}//close par\n";
    }
}

void CompilationManager::compileChoiceElement(const std::pair<Literal*, Body*>& choiceElem){
    const Body* body = choiceElem.second;
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";

    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;

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
                *out << indentation << "const Tuple negativeTuple = Tuple({";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier() << ", true);\n";
                *out << indentation << "const Tuple* tuple" << i << " = factory.find(" << "{";
                printLiteralTuple(lit, boundVariables);
                *out << "}, _" << lit->getIdentifier()<<");\n";
                *out << indentation++ << "if(tuple" << i << " == NULL){\n";
                *out << indentation << "tuple" << i <<" = &negativeTuple;\n";
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
                if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t))){
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
                std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                choiceElem.second->removeBuiltInAt(it);
                closingParenthesis++;
            }//X = Y+2 where X is not already bound, or X == Y
            else if(bindingResult.second && bindingResult.first != "" && (currentBuiltIn->getMyOperator() == "=" || currentBuiltIn->getMyOperator() == "==")){
                if(currentBuiltIn->getLeftExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getLeftExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                    choiceElem.second->removeBuiltInAt(it);
                }
                else if(currentBuiltIn->getRightExpr()->isBound(boundVariables)){
                    *out << indentation << "int " << bindingResult.first << " = " <<currentBuiltIn->getRightExpr()->getRepresentation()<<";\n";
                    boundVariables.insert(bindingResult.first);
                    std::vector<BuiltInTerm*>::const_iterator it = body->getBuiltInTerms().begin() + builtInIndex;
                    choiceElem.second->removeBuiltInAt(it);
                }
            }
        }
        if(i == body->getConjunction().size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            //SHOULD WE SAVE NEGATIVE LITERALS IN CHOICE ELEMENTS' BODY
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
                    listOfTerms += "}";
                }
                j++;
            }
            *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
            *out << indentation++ <<"if(t->isUnknown()){\n";
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
                *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                *out << indentation << "factory.removeFromCollisionsList(t->getId());\n";
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


void CompilationManager::printLiteralTuple(const Literal* lit) {
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

void CompilationManager::printLiteralTuple(const Literal* lit, const std::unordered_set<std::string>& boundVariables) {
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

void CompilationManager::declareDataStructures(Rule* r) {
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

void CompilationManager::declareDataStructures(ChoiceRule* r) {
    std::unordered_set<std::string> boundVariables;

    //declaration for normal order grounding
    for(unsigned i = 0 ; i < r->getBody()->getConjunction().size(); i++){
        Literal* li = r->getBody()->getConjunction().at(i);
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
        if(isExitRule)
            exitRules.push_back(componentRules[i]->getID());
    }
}

void CompilationManager::compileRecursiveComponent(Program* program, std::vector<unsigned>& recursiveComponent){
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
    if(recursiveDep.size() > 0)
        *out<< indentation << "std::vector<int> generatedStack;\n";

    for(unsigned i = 0; i < exitRules.size(); ++i){
        Rule* rule = program->getRuleByID(exitRules[i]);
        compileRule(rule, recursiveDep);
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
    
    if(recursiveDep.size() > 0){
        *out << indentation++ << "while(! generatedStack.empty()){\n";
        *out << indentation << "const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());\n";
        *out << indentation << "generatedStack.pop_back();\n";
        *out << indentation << "unsigned literalName = recursiveTuple->getPredicateName();\n";
        //if recursive[i] -> do a specific compilation
        for(unsigned i = 0; i < recursiveDep.size(); ++i){
            *out << indentation++ << "if(literalName == _"<< recursiveDep[i] <<"){\n";
                for(unsigned j = 0; j < recursiveComponent.size(); ++j){
                    if(program->getRuleByID(recursiveComponent[j])->containsLiteralInBody(recursiveDep[i])){
                        //compile several times basing on how many occurrencies of the predicate are present in the chosen rule
                        for(unsigned k  = 0; k < program->getRuleByID(recursiveComponent[j])->getBody()->getConjunction().size(); ++k)
                        if(program->getRuleByID(recursiveComponent[j])->getBody()->getConjunction()[k]->getIdentifier() == recursiveDep[i]){
                            compileRule(program->getRuleByID(recursiveComponent[j]), recursiveDep, k);
                        }
                    }
                }
            *out << --indentation << "}\n";
        
        }
    }else {
        for(unsigned j = 0; j < recursiveComponent.size(); ++j){
            compileRule(program->getRuleByID(recursiveComponent[j]), recursiveDep);
        }
    }


    if(recursiveDep.size() > 0)
        *out<< --indentation << "}\n";
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