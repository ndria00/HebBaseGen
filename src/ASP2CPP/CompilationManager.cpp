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
    *out << indentation << "Executor::Executor(){\n";
    *out << indentation << "}\n";

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
    *out << indentation++ << "void Executor::init(){\n";
    for(auto lit : program->getPredicatesID()){
        *out << indentation << "Executor::predicateIds.push_back(\"" << lit.first << "\");\n";
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

    *out << indentation++ << "void executeProgram(){\n";
    //addFacts();
    *out << indentation <<"//TODO\n";
    for(Rule* r: program->getRules()){
        compileRule(r);
    }
    *out << --indentation<<"}\n";
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

void CompilationManager::compileRule(Rule* rule){
    const Body* body = rule->getBody();
    std::unordered_set<std::string> boundVariables;
    unsigned closingParenthesis = 0;

    for(unsigned i = 0; i < body->getConjunction().size(); ++i){
        Literal* lit = body->getConjunction().at(i);
        if( !lit->isNegative()){
            std::string mapVariableName = lit->getIdentifier() + "_";

            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable() && boundVariables.count(lit->getTermAt(t)) || ! lit->getTerms().at(t)->isVariable())
                    mapVariableName += std::to_string(t) + "_";
            }    
            *out << indentation << "const std::vector<int>* tuples;\n";
            *out << indentation << "tuples = &p" << mapVariableName << ".getValuesVec({";
            printLiteralTuple(lit, boundVariables);
            *out << "});\n";
            *out << indentation << "const std::vector<int>* tuplesU = &EMPTY_TUPLES_VEC;\n";
            *out << indentation << "const Tuple* tupleU = NULL;\n";
                            
            *out << indentation++ << "for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){\n";
            *out << indentation << "const Tuple * tuple" << i << " = NULL;\n";
            *out << indentation++ << "if(i < tuples->size()){\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuples->at(i));\n";
            *out << indentation++ << "if(tuplesU != &EMPTY_TUPLES_VEC) {\n";
            *out << indentation << "tupleU = NULL;\n";
            *out << --indentation << "}\n";
            *out << --indentation << "}\n";
            *out << indentation++ << "else {\n";
            *out << indentation << "tuple" << i << " = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));\n";
            *out << indentation << "tupleU = tuple" << i << ";\n";
            //*out << indentation << "tupleUNegated = false;\n";
            *out << --indentation << "}\n";
            closingParenthesis++;
        }
        if (!lit->isNegative() || (i == 0)){
            std::unordered_set<std::string> declaredVariables;
            for(unsigned t = 0; t < lit->getArity(); ++t){
                if(lit->getTerms().at(t)->isVariable()  && !boundVariables.count(lit->getTermAt(t)) && ! declaredVariables.count(lit->getTermAt(t))){
                    *out << indentation <<" int " << lit->getTermAt(t)<< " = (*tuple" << i <<")[" << t <<"];\n"; 
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