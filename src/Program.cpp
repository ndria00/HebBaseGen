#include "Program.h"
   
Program::Program(){

}
Program::Program(std::vector<Rule> rules){
    this->rules = rules;
}
std::vector<Rule> Program::getRules()const{
    return this->rules;
}
void Program::setRules(std::vector<Rule> rules){
    this->rules = rules;
}
void Program::print()const{
    for(Rule r : this->rules){
        r.print();
    }
    std::cout<<std::endl;
}