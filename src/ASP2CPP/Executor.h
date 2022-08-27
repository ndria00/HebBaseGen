#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "../DataStructures/TupleLight.h"
class Executor{
    private:
    
    public:
        static std::vector<std::string> predicateIds;
        Executor();
        inline void insertTrue(const std::pair<const TupleLight *, bool>& );
        inline void insertUndef(const std::pair<const TupleLight *, bool>& );
        void executeProgram();
        void init();

};

#endif /*EXECUTOR_H*/