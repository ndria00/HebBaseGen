#include "ASPCore2FactsListenerLight.h"

ASPCore2FactsListenerLight::ASPCore2FactsListenerLight(Executor* executor){
    this->executor = executor;
    this->terms = vector<int>();
    this->intervalIndexAndRanges =  std::unordered_map<int, std::pair<int, int>>();
    atomName = NO_NAME;
}

void ASPCore2FactsListenerLight::exitFact(ASPCore2FactsParser::FactContext * /*ctx*/){
    //add last atom as true
    executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(terms, atomName), atomInsideRule > 1);
    atomName = NO_NAME;
    terms.clear();
    atomInsideRule = 0;
}

void ASPCore2FactsListenerLight::enterAtom(ASPCore2FactsParser::AtomContext * /*ctx*/){
    //when enter atom try to add the previous atom(if it exists)
    //fact is disjunctive
    atomInsideRule++;
    //add the previous atom as undef atom because the rule is disjunctive
    if(atomName != NO_NAME){
        executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(terms, atomName), atomInsideRule > 1);
        //clear data of the last atom
        atomName = NO_NAME;
        terms.clear();
    }
}

void ASPCore2FactsListenerLight::enterTerm(ASPCore2FactsParser::TermContext * term){
    //if(!term->term_()){
        terms.push_back(ConstantsManager::getInstance().mapConstant(term->getStart()->getText()));
    //}
}

void ASPCore2FactsListenerLight::enterIdentifier(ASPCore2FactsParser::IdentifierContext * identifier){
    if(atomName == NO_NAME){
        if(executor->predicateToID.find(identifier->getStart()->getText()) != executor->predicateToID.end()){
            atomName = executor->predicateToID[identifier->getStart()->getText()];
        }
        else{
            atomName = NOT_ENCODING_ATOM;
            nonEncodingAtomName = identifier->getStart()->getText();
        }
    }
}