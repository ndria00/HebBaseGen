#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "../DataStructures/TupleLight.h"
#include "../grounder/Program.h"
class Executor{
    private:
        unordered_map<std::string, int> predicateToID;
    public:
        static std::vector<std::string> predicateIds;
        Executor();
        //inline void insertTrue(const std::pair<const TupleLight *, bool>& );
        //inline void insertUndef(const std::pair<const TupleLight *, bool>& );
        void init();
        void insertFactIntoFactory(const Literal& , bool );
        void executeProgram();
};

#endif /*EXECUTOR_H*/