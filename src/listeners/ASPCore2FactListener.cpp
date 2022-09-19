#include "ASPCore2FactListener.h"

const int NOT_ENCODING_ATOM = -2;
const int NO_NAME = -1;
const int IGNORE_TERM = -1;

ASPCore2FactListener::ASPCore2FactListener(Executor* executor) : ASPCore2BaseListener(){
    this->executor = executor;
    disjunctiveFact = false;
    atomName = NO_NAME;
    atomArity = 0; 
    indexAndRange = unordered_map<std::string, std::pair<int, int>>();
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
        else{
            atomName = NOT_ENCODING_ATOM;
        }

        //std::cout<< atom->identifier()->getText() << " has id: " << executor->predicateToID[atom->identifier()->getText()] << std::endl;
    }
}

void ASPCore2FactListener::exitAtom(ASPCore2Parser::AtomContext * atom){
    //std::cout <<"built atom with id " <<atomName << "and a number of " << terms.size() <<" terms\n";
    
    if(indexAndRange.size() == 0){
        if(atomName != NOT_ENCODING_ATOM){
            executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(terms, atomName), disjunctiveFact);   
        }
        else{
            std::cout << atom->getText() << std::endl;
        }
    }
    else{
        std::vector<int> myTerms;
        std::string stringAtomName = "";
        if(atomName == NOT_ENCODING_ATOM){
            stringAtomName = atom->getStart()->getText();
            bindTerms(0, myTerms, stringAtomName);
        
        }else{
            bindTerms(0, myTerms, stringAtomName);
        }
        

        indexAndRange.clear();
    }
    //std::cout<<"added tuple\n";
    atomName = NO_NAME;
    atomArity = 0;
    terms.clear();
}

void ASPCore2FactListener::enterTerm(ASPCore2Parser::TermContext * t){
    if(atomName != NO_NAME){
        if(!t->term_()){
            terms.push_back(ConstantsManager::getInstance().mapConstant(t->getText()));
            atomArity++;
        }else{
            //TODO improve
            terms.push_back(IGNORE_TERM);
        }
    }
}


void ASPCore2FactListener::enterTerm_(ASPCore2Parser::Term_Context * term_){
    //NUMBER DDOT NUMBER
    if(term_->children.size() == 3){
        if(term_->children.at(1)->getText() == ".."){
            indexAndRange[std::to_string(atomArity)] = std::make_pair(std::stoi(term_->children.at(0)->getText()), std::stoi(term_->children.at(2)->getText()));
        }
        atomArity++;
    }
}

void ASPCore2FactListener::bindTerms(int index, std::vector<int>& atomTerms, std::string& stringAtomName){
    //chain stops (all terms are bound)
    if(index == atomArity){
        if(atomName == NOT_ENCODING_ATOM){
            std::cout << stringAtomName;
            if(atomTerms.size() > 0){
                std::cout<<"(";
                for(int i = 0; i < atomTerms.size()-1; ++i){
                    std::cout << ConstantsManager::getInstance().unmapConstant(atomTerms[i])<<",";
                }
                std::cout << ConstantsManager::getInstance().unmapConstant(atomTerms.at(atomTerms.size()-1)) << ")\n";
            }
        }
        else{
            executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(atomTerms, atomName), disjunctiveFact);
        }
        return;
    }
    if(indexAndRange.count(std::to_string(index)) > 0){
        int minNumber = indexAndRange[std::to_string(index)].first;
        int maxNumber = indexAndRange[std::to_string(index)].second;
        
        for(int i = minNumber; i <= maxNumber; ++i){
            atomTerms.push_back(i);
            bindTerms(index+1, atomTerms, stringAtomName);
            atomTerms.pop_back();
        }
    }
    else{
        atomTerms.push_back(terms[index]);
        bindTerms(index+1, atomTerms, stringAtomName);
        atomTerms.pop_back();
    }

}