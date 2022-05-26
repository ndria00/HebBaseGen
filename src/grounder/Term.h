#ifndef TERM_H_
#define TERM_H_
#include <string>

class Term{
    private:
        std::string value;
    
    public:
        Term();
        Term(std::string&);
        const std::string& getValue()const;
        void setValue(std::string&);
        void print();
};
#endif