#ifndef EXECUTORBASE_H
#define EXECUTORBASE_H
#include "../grounder/Literal.h"
class ExecutorBase{
    public:
        virtual void init(){};
        virtual void insertFactIntoFactory(const Literal& , bool ){};
        virtual void executeProgram(){};
        virtual ~ExecutorBase(){};
};
#endif /*EXECUTORBASE_H*/