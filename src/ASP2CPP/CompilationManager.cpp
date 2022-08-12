#include "CompilationManager.h"

CompilationManager::CompilationManager(Builder* builder){
    this->builder = builder;
    indentation = Indentation();
}

void CompilationManager::generateProgram(Program* program){
    *out << indentation << "#include \"Executor.h\"\n";
    *out << indentation << "#include \"../DataStructures/ConstantsManager.h\"\n";
    *out << indentation << "#include \"../DataStructures/AuxiliaryMapSmart.h\"\n";
    *out << indentation << "template<size_t S>\n";
    *out << indentation << "using AuxMap = AuxiliaryMapSmart<S> ;\n";
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
    
    for(auto lit : program->getPredicatesID()){
       *out << indentation << "const std::string _" << lit.first << " = \"" << lit.first << "\";\n"; 
    }

    *out << indentation << "void executeProgram(){\n";

    ++indentation;
    //addFacts();
    *out << indentation <<"//TODO\n";
    --indentation;
    *out << indentation <<"}\n";
}

void CompilationManager::setOutStream(std::ostream* outputFile){
    this->out = outputFile;
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