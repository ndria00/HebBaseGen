#include "FunctionalTerm.h"

        FunctionalTerm::FunctionalTerm::FunctionalTerm(){

        }
        const std::string& FunctionalTerm::getValue()const{

        }
        void FunctionalTerm::setValue(std::string&) {
            
        }
        void FunctionalTerm::addTerm(TermBase* term){
            terms.push_back(term);
        }
        void FunctionalTerm::print() const{
            std::cout<<""<<this->identifier<<"(";
            for(unsigned i = 0; i < terms.size(); ++i) {
                terms.at(i)->print();
                if(i != terms.size() -1)
                    std::cout<<", ";
            }
            std::cout<<")";
        }
        bool FunctionalTerm::isVariable()const{
            return false;
        }
        void FunctionalTerm::setVariable(bool){

        }
        void FunctionalTerm::getAllVariables(std::set<std::string>& variables){
            for(TermBase* term : terms){
                if(term->isVariable())
                    variables.insert(term->getValue());
            }
        }
        void FunctionalTerm::removeSafeVariables(std::set<std::string>& variables){
            for(TermBase* term : terms){
                term->removeSafeVariables(variables);
            }
        }
        std::string FunctionalTerm::getFunctionName()const{
            return identifier;
        }
        const std::vector<TermBase*>& FunctionalTerm::getTerms()const{
            return terms;
        }
        void FunctionalTerm::setFunctionName(std::string identifier){
            this->identifier = identifier;
        }

        FunctionalTerm::~FunctionalTerm(){

        }

        