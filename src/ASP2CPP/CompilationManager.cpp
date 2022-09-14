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
    
    for(auto rule : program->getRules()){
        declareDataStructures(rule);
    }

    //init function
    //*out << indentation << "void printGeneratedFromRule(vector<std::pair<std::string, vector<std::pair<std::string, int>>>>& );\n\n";
    
    //print function
    *out << indentation++ << "void printTuple(const Tuple* t){\n";
    //*out << indentation << "if(t->isFalse()) std::cout << \"not \";\n";
    //*out << indentation << "if(t->isUndef()) std::cout << \"undef \";\n";

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
    *out << indentation++ << "if(disjunctiveFact){\n";
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



void CompilationManager::compileRule(Rule* rule, std::vector<std::string>& recursiveDep){
    std::vector<Literal*> orderedConjunction;
    //TODO :substituite with a more efficient method
    for(Literal* lit : rule->getBody()->getConjunction())
        if(!lit->isNegative())
            orderedConjunction.push_back(lit);
    
    for(Literal* lit : rule->getBody()->getConjunction())
        if(lit->isNegative())
            orderedConjunction.push_back(lit);

    const Body* body = rule->getBody();
    unsigned negativeBodySize = body->getNegativeSize();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;
    *out << indentation++ << "{\n";

    std::unordered_map<std::string, unsigned> variablesNameToTupleIndexes;
    //*out <<"int recursionIndex = -1\n";
    //TODO check recursoveDep.size()>1
    //simple case in which there is only one recursive dependency in a rule (reachability)
    std::vector<unsigned> selfRecursiveIndexes;
    rule->getRecursiveIndexes(selfRecursiveIndexes);

    if(selfRecursiveIndexes.size() > 0){
        //foreach recursive literal print an if that determines which and how many variables are to be declared
        for(unsigned i = 0; i < selfRecursiveIndexes.size(); ++i){
            unsigned j = 0;


            Literal* recursiveLit = rule->getBody()->getConjunction().at(selfRecursiveIndexes[i]);

            for(unsigned t = 0; t < recursiveLit->getArity(); ++t){
                if(recursiveLit->getTerms().at(t)->isVariable())
                    variablesNameToTupleIndexes[recursiveLit->getTermAt(t)] = t; 
            }

            // for(Literal* lit: rule->getBody()->getConjunction()){
            //     if(std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end() && !lit->isNegative()){
            //         // if(j == 0){
            //         //     *out << indentation++ << "if(literalName == predicateToID[\"" << lit->getIdentifier() << "\"]){\n";
            //         //     //*out << "recursionIndex = 22";
            //         //     for(unsigned t = 0; t < lit->getArity(); ++t){
            //         //         if(lit->getTerms().at(t)->isVariable())
            //         //             variablesNameToTupleIndexes[lit->getTermAt(t)] = t; 
            //         //     }
            //         //     *out << --indentation <<"}\n";

            //         // }
            //         // else{
            //         //     *out << indentation++ << "else if(literalName == predicateToID[\"" << lit->getIdentifier() << "\"]){\n";
            //         //     for(unsigned t = 0; t < lit->getArity(); ++t){
            //         //         if(lit->getTerms().at(t)->isVariable())
            //         //             variablesNameToTupleIndexes[lit->getTermAt(t)] = t; 
            //         //     }
            //         //     *out << --indentation <<"}\n";
            //         // }
            //         //recursiveLit = std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier());
            //     }
            //     ++j;
            // }
            if (!recursiveLit->isBound(boundVariables)) {
                recursiveLit->addVariablesToSet(boundVariables);
        }
        }
            
        //std::unordered_set<std::string> declaredVariables;
        for(auto& nameIndex: variablesNameToTupleIndexes ){
            *out << indentation << "int " << nameIndex.first << " = (*recursiveTuple)[" << nameIndex.second << "];\n";
        }

    }

    closingParenthesis++;
    for(unsigned i = 0; i < orderedConjunction.size(); ++i){
        Literal* lit = orderedConjunction[i];
        if(!lit->isNegative() && lit->isBound(boundVariables)){
            *out << indentation << "const Tuple* tuple" << i << " = factory.find({";
            printLiteralTuple(lit, boundVariables); 
            *out << "}, _" << lit->getIdentifier() << ");\n";
        }
        else if(!lit->isNegative()){
            std::string mapVariableName = lit->getIdentifier() + "_";

            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t)) || ! lit->getTerms().at(t)->isVariable()){
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
            *out << indentation << "const Tuple* tuple" << i << " = factory.find(negativeTuple);\n";
            *out << indentation++ << "if(tuple" << i << " == NULL){\n";
            *out << indentation << "tuple" << i <<" = &negativeTuple;\n";
            *out << --indentation << "}\n";
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
        if(i == orderedConjunction.size() - 1){
            *out<< indentation <<"//Rule is firing \n";
            // add all literals in the head to the factory
            bool insertAsUndef = false;
            if(rule->getHead()->getDisjunction().size() > 1)
                insertAsUndef = true;

            //*out << indentation << "vector<std::pair<std::string, vector<std::pair<std::string, int>>>> literalsAndVariables;\n";
            *out << indentation << "Tuple* t;\n";
            *out << indentation << "std::pair<const TupleLight *, bool> insertResult;\n";
            *out << indentation << "bool alreadyInFactory = false;\n";
            unsigned index = 0;
            for(Literal* lit : rule->getHead()->getDisjunction()){
                //*out << indentation << "vector<std::pair<std::string, int>> variableNameToID_" << index << ";\n";


                *out << indentation++ << "if(factory.find(";
                unsigned j = 0;
                std::string listOfTerms = "{";
                for(TermBase* t : lit->getTerms()){
                    //*out << indentation << "ConstantsManager::getInstance().mapConstant()";
                    if(j != lit->getTerms().size() -1){
                        listOfTerms += t->getRepresentation();
                        listOfTerms += ",";
                    }
                    else{
                        listOfTerms += t->getRepresentation();
                        listOfTerms += "}";
                    }
                    //*out << indentation << "variableNameToID_" << index << ".push_back(std::make_pair(\"" << t->getRepresentation() << "\", " << t->getRepresentation() << "));\n";
                    j++;
                }
                *out << listOfTerms<<", _" << lit->getIdentifier() << ") != NULL){\n";
                *out << indentation << "alreadyInFactory = true;\n";
                *out << --indentation << "}\n";


                *out << indentation++ << "if(!alreadyInFactory){\n";
                *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
                *out << indentation << "insertResult = t->setStatus(TruthStatus::True);\n";
                if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end())
                    *out << indentation << "generatedStack.push_back(t->getId());\n";
                //*out << indentation << "literalsAndVariables.push_back(std::make_pair(\"" << lit->getIdentifier() << "\", variableNameToID_" << index << "));\n";
                if(insertAsUndef)
                    *out << indentation << "insertUndef(insertResult);\n";
                else
                    *out << indentation << "insertTrue(insertResult);\n";
                    
                *out << --indentation << "}\n";
                //*out << indentation << "terms.clear();\n";
                //*out << indentation << "variableNameToID.clear();\n";

                index++;
            }
            //*out << indentation << "printGeneratedFromRule(literalsAndVariables);\n";
            *out << indentation << "//negative literals saving\n";
            if(negativeBodySize > 0){
                for(Literal* lit : orderedConjunction){
                    if(lit->isNegative()){
                        unsigned j = 0;
                        std::string listOfTerms = "{";
                        for(TermBase* t : lit->getTerms()){
                            //*out << indentation << "ConstantsManager::getInstance().mapConstant()";
                            if(j != lit->getTerms().size() -1){
                                listOfTerms += t->getRepresentation();
                                listOfTerms += ",";
                            }
                            else{
                                listOfTerms += t->getRepresentation();
                                listOfTerms += "}";
                            }
                            //*out << indentation << "variableNameToID_" << index << ".push_back(std::make_pair(\"" << t->getRepresentation() << "\", " << t->getRepresentation() << "));\n";
                            j++;
                        }
                        *out << indentation << "alreadyInFactory = false;\n";
                        *out << indentation++ << "if(factory.find(" << listOfTerms <<", _"<< lit->getIdentifier() << ") != NULL){\n";
                        *out << indentation << "alreadyInFactory = true;\n";
                        *out << --indentation << "}\n";

                        *out << indentation++ << "if(!alreadyInFactory){\n";
                        *out << indentation << "t = factory.addNewInternalTuple(" << listOfTerms << ", _" << lit->getIdentifier() << ");\n";
                        *out << indentation << "insertResult = t->setStatus(TruthStatus::Undef);\n";
                        *out << indentation << "insertUndef(insertResult);\n";
                    }
                }

                if(recursiveDep.size() > 0 && std::find(recursiveDep.begin(), recursiveDep.end(), lit->getIdentifier()) != recursiveDep.end())
                    *out << indentation << "generatedStack.push_back(t->getId());\n";
                *out << --indentation << "}\n";
                *out << indentation << "terms.clear();\n";
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
                if( i != j && componentRules[j]->containsLiteralInHead(l)){
                    isExitRule = false;
                    //add recursive dep on lieral l of rule[i] 
                    if(std::find(recursiveDep.begin(), recursiveDep.end(), l->getIdentifier()) == recursiveDep.end()){
                        recursiveDep.push_back(l->getIdentifier());
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
    
    if(recursiveDep.size() > 0){
        *out << indentation++ << "while(! generatedStack.empty()){\n";
        *out << indentation << "const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());\n";
        *out << indentation << "generatedStack.pop_back();\n";
        //std::unordered_set<std::string> declaredVariables;
        //std::unordered_set<std::string> boundVariables;
        *out << indentation << "unsigned literalName = recursiveTuple->getPredicateName();\n";
    }

    for(unsigned j = 0; j < recursiveComponent.size(); ++j){
        compileRule(program->getRuleByID(recursiveComponent[j]), recursiveDep);
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