#include "ASPCore2FactListenerNoTree.h"
 
ASPCore2FactListenerNoTree::ASPCore2FactListenerNoTree(Executor* executor, antlr4::CommonTokenStream* myTokens){
    this->executor = executor;
    this->myTokens = myTokens;
    this->terms = vector<int>();
    this->intervalIndexAndRanges =  std::unordered_map<int, std::pair<int, int>>();
    atomName = NO_NAME;
}

ASPCore2FactListenerNoTree::ASPCore2FactListenerNoTree(Executor* executor){
    this->executor = executor;
    this->terms = vector<int>();
    this->intervalIndexAndRanges =  std::unordered_map<int, std::pair<int, int>>();
    atomName = NO_NAME;
}
void ASPCore2FactListenerNoTree::setTokenStream(antlr4::CommonTokenStream* myTokens){
    this->myTokens = myTokens;
}

void ASPCore2FactListenerNoTree::enterSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/){
}

void ASPCore2FactListenerNoTree::exitSimple_rule(ASPCore2Parser::Simple_ruleContext * /*ctx*/){
    //add last atom as true
    bindTermsAndAddToFactory();
    atomName = NO_NAME;
    terms.clear();
    atomInsideRule = 0;
}

void ASPCore2FactListenerNoTree::enterAtom(ASPCore2Parser::AtomContext * /*ctx*/){
    //when enter atom try to add the previous atom(if it exists)
    //fact is disjunctive
    atomInsideRule++;
    //add the previous atom as undef atom because the rule is disjunctive
    if(atomName != NO_NAME){
        bindTermsAndAddToFactory();
        //clear data of the last atom
        atomName = NO_NAME;
        terms.clear();
    }
}

void ASPCore2FactListenerNoTree::exitAtom(ASPCore2Parser::AtomContext * /*ctx*/){

}

void ASPCore2FactListenerNoTree::enterTerm(ASPCore2Parser::TermContext * term){
    if(term->getText().find("..") != string::npos){
        //it is an interval and I should save both the position
        //of the term in the atom and the text associated
        //terms.push_back(INT_MAX);
        //int indexOfDelim = term->getText().find("..");
        //intervalRanges.push_back(std::make_pair(std::stoi(term->getText().substr(0, indexOfDelim)), std::stoi(term->getText().substr(indexOfDelim + 2, term->getText().length()))));

    }else{

        if(term->getStop() != NULL){
            //std::cout <<"HELLO " <<  myTokens->getText(term->getSourceInterval())  <<" OOOOOO"<< term->getStop() << std::endl;
        }else{
            terms.push_back(ConstantsManager::getInstance().mapConstant(term->getStart()->getText()));
        }
        //terms.push_back(ConstantsManager::getInstance().mapConstant(myTokens->getTokens(term->getStart(), term->getStop())));
        //myTokens->get(identifier->getStart()->getTokenIndex())->getText()
        //myTokens->getText(term->getStart(), term->getStop())
    }
}

void ASPCore2FactListenerNoTree::enterTerm_(ASPCore2Parser::Term_Context * /*ctx*/){

}

void ASPCore2FactListenerNoTree::enterIdentifier(ASPCore2Parser::IdentifierContext * identifier){
    if(atomName == NO_NAME){
        if(executor->predicateToID.find(identifier->getStart()->getText()) != executor->predicateToID.end()){
            atomName = executor->predicateToID[identifier->getStart()->getText()];
        }
        else{
            atomName = NOT_ENCODING_ATOM;
            nonEncodingAtomName = identifier->getStart()->getText();
        }
    }
    // else{// string or symbolic constant but already entered term
    //     //terms.push_back(ConstantsManager::getInstance().mapConstant(identifier->getText()));
    // }
}

void ASPCore2FactListenerNoTree::bindTermsAndAddToFactory(){
    //all terms are already bound
    if(intervalIndexAndRanges.empty()){
        //just print the tuple
        if(atomName == NOT_ENCODING_ATOM){
            std::cout << nonEncodingAtomName;
            if(terms.size() > 0){
                std::cout<<"(";
                for(int i = 0; i < terms.size()-1; ++i){
                    std::cout << ConstantsManager::getInstance().unmapConstant(terms[i])<<",";
                }
                std::cout << ConstantsManager::getInstance().unmapConstant(terms.at(terms.size()-1)) << ")\n";
            }
        }
        else{//add tuple to factory
            executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(terms, atomName), atomInsideRule > 1);
        }
    }
    else{ //there are terms that have to be bound using intervals
        
        // for(unsigned i = 0; i < intervalIndexAndRanges.size(); ++i){

        // }

        // while(){

        // }
    }
}