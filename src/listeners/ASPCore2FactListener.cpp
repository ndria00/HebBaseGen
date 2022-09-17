#include "ASPCore2FactListener.h"

ASPCore2FactListener::ASPCore2FactListener(Executor* executor) : ASPCore2BaseListener(){
    this->executor = executor;
    disjunctiveFact = false;
    atomName = -1;
    terms = std::vector<int>();
}

void ASPCore2FactListener::enterHead(ASPCore2Parser::HeadContext * head){
    if(head->disjunction() != NULL && head->disjunction()->children.size() > 1){
        disjunctiveFact = true;
    }
}

void ASPCore2FactListener::exitHead(ASPCore2Parser::HeadContext * /*ctx*/) {
    disjunctiveFact = false;
}

void ASPCore2FactListener::enterAtom(ASPCore2Parser::AtomContext * atom){
    if(atom->identifier() != NULL ){
        if(executor->predicateToID.find(atom->identifier()->getText()) != executor->predicateToID.end())
            atomName = executor->predicateToID[atom->identifier()->getText()];
        else
            atomName = -2;


        //std::cout<< atom->identifier()->getText() << " has id: " << executor->predicateToID[atom->identifier()->getText()] << std::endl;
    }
}

void ASPCore2FactListener::exitAtom(ASPCore2Parser::AtomContext * atom){
    //std::cout <<"built atom with id " <<atomName << "and a number of " << terms.size() <<" terms\n";
    if(atomName != -2)
        executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(terms, atomName), disjunctiveFact);   
    else
        std::cout << atom->getText() << std::endl;
    //std::cout<<"added tuple\n";
    atomName = -1;
    terms.clear();
}

// void ASPCore2FactListener::enterIdentifier(ASPCore2Parser::IdentifierContext * id){
//     //if(atomName != -1)
//     //    terms.push_back(ConstantsManager::getInstance().mapConstant(id->getText()));
// }

void ASPCore2FactListener::enterTerm(ASPCore2Parser::TermContext * t){
    if(atomName != -1){
        terms.push_back(ConstantsManager::getInstance().mapConstant(t->getText()));
    }
}


// void ASPCore2FactListener::visitTerminal(antlr4::tree::TerminalNode * t){
//     //all terminals that are not literal identifiers are terms
//     if(atomName != -1){
//         terms.push_back(ConstantsManager::getInstance().mapConstant(t->getText()));
//     }

// }