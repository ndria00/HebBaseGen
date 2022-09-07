#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "../DataStructures/TupleLight.h"
#include "../grounder/Program.h"
#include "ExecutorBase.h"
class Executor : public ExecutorBase{
    private:
        unordered_map<std::string, int> predicateToID;
    public:
        static std::vector<std::string> predicateIds;
        Executor(){};
        //inline void insertTrue(const std::pair<const TupleLight *, bool>& );
        //inline void insertUndef(const std::pair<const TupleLight *, bool>& );
        void init() override;
        void insertFactIntoFactory(const Literal& , bool )override;
        void executeProgram()override;
        ~Executor(){};
};

#endif /*EXECUTOR_H*/