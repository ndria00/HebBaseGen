#ifndef ASPFACTPARSERREGEX_H
#define ASPFACTPARSERREGEX_H
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include "../ASP2CPP/Executor.h"
#include "../DataStructures/ConstantsManager.h"
class ASPFactParserRegex{
    public:
        ASPFactParserRegex(Executor*);
        void parseFact(std::string&);

    private:
        Executor* executor;
        std::regex identifierRegex;
        std::regex termRegex;
};
#endif /*ASPFACTPARSERREGEX_H*/