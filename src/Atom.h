#ifndef ATOM_H_
#define ATOM_H_
#include <string>
#include <vector>
#include <iostream>
class Atom{
    private:
        std::string identifier;
        std::vector<std::string> terms;
 
    public:
        Atom();
        Atom(std::string, std::vector<std::string>);
        std::string getIdentifier()const;
        std::vector<std::string> getTerms()const;
        void setIdentifier(std::string);
        void setTerms (std::vector<std::string>);
        void print()const;
};

#endif