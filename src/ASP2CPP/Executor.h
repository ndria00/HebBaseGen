#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "../grounder/Program.h"
#include "../DataStructures/TupleFactory.h"
#include "../DataStructures/AuxiliaryMapSmart.h"
#include "ExecutorBase.h"
class Executor : public ExecutorBase{
    private:

    public:
        TupleFactory factory;
        unordered_map<std::string, int> predicateToID;
        static std::vector<std::string> predicateIds;
        Executor(){};
        //inline void insertTrue(const std::pair<const TupleLight *, bool>& );
        //inline void insertUndef(const std::pair<const TupleLight *, bool>& );
        void init() override;
        //void insertFactIntoFactory(const Literal& , bool )override;
        void OnLiteralTrueUndef(TupleLight* t, bool disjunctiveFact);
        void printGeneratedBase();
        void executeProgram()override;
        ~Executor(){};
};

#endif /*EXECUTOR_H*/