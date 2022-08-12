#ifndef COMPILATIONNMANAGER_H
#define COMPILATIONMANAGER_H
#include "../Builder.h"
#include "../utils/Indentation.h"
#include <iostream>
class CompilationManager{
    private:
        Builder* builder;
        std::ostream* out;
        Indentation indentation;

    public:
        CompilationManager(Builder*);
        void generateProgram(Program*);
        void setOutStream(std::ostream*);
        void addFacts();

};

#endif