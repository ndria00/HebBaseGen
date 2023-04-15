#include "ASPFactParserRegex.h"
ASPFactParserRegex::ASPFactParserRegex(Executor* executor){
    this->executor = executor;
    //[\d+\.\.\d+|\d+|[a-z][a-zA-Z0-9]*]
    //[\\d+\\.\\.\\d+|\\d+|[a-z][a-zA-Z0-9]*]|
    identifierRegex = std::regex("[a-z][A-Za-z_0-9]*");
    termRegex = std::regex("(-?[0-9]+)|(\"(\" | . )*?\")|([a-z0-9]+)");

    // SYMBOLIC_CONSTANT:   				[a-z][A-Za-z_0-9]* ;
    // VARIABLE:           				[A-Z][A-Za-z_0-9]* ;
    // STRING:					'"' ('\\"' | . )*? '"' ;
    // NUMBER:					[0-9]+ ;
}

void ASPFactParserRegex::parseFact(std::string& s){
    std::smatch matches;
    std::string stringAtomName;
    std::vector<int> atomTerms;
    
    std::string::const_iterator searchStart(s.cbegin());
    if(std::regex_search(searchStart, s.cend(), matches, identifierRegex)){
        if(matches.ready()){
            stringAtomName = matches.str(0);
            //std::cout << "atom name is " << atomName <<"because matches is " << matches.str(0) << "\n";
        }
        searchStart = matches.suffix().first;
    }
    
    //std::cout <<"I have " << s << " left\n";

    while(std::regex_search(searchStart, s.cend(), matches, termRegex)){
        if(matches.ready()){
            atomTerms.push_back(ConstantsManager::getInstance().mapConstant(matches[0]));
            //std::cout << "term matched" << matches[0]<< std::endl;
        }
       searchStart = matches.suffix().first;

    }
    if(executor->predicateToID.count(stringAtomName)){
        executor->OnLiteralTrueUndef(executor->factory.addNewInternalTuple(atomTerms, executor->predicateToID[stringAtomName]), false);
    }
    else{
        std::cout << stringAtomName;
        if(atomTerms.size() > 0){
            std::cout<<"(";
            for(int i = 0; i < atomTerms.size()-1; ++i){
                std::cout << ConstantsManager::getInstance().unmapConstant(atomTerms[i])<<",";
            }
            std::cout << ConstantsManager::getInstance().unmapConstant(atomTerms.at(atomTerms.size()-1)) << ")\n";
        }
    }
}   