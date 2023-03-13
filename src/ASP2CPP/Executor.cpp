#include <chrono>
#include "Executor.h"
#include "../DataStructures/ConstantsManager.h"
#include "../DataStructures/IndexedSet.h"
typedef TupleLight Tuple;
template<size_t S>
using AuxMap = AuxiliaryMapSmart<S> ;
const std::vector<int> EMPTY_TUPLES_VEC;
const IndexedSet EMPTY_TUPLES_SET;

std::vector<std::string> Executor::predicateIds;
const int _arc = 1;
const int _reach = 0;
AuxMap<0> parc_({});
AuxMap<0> preach_({});
AuxMap<32> parc_0_({0});
void printTuple(const Tuple* t){
    std::cout << Executor::predicateIds[t->getPredicateName()] << "(";
    for(int i=0;i<t->size();i++){
        if(i>0) std::cout << ",";
        std::cout << ConstantsManager::getInstance().unmapConstant(t->at(i));
    }
    std::cout << ")"<<std::endl;
}
void Executor::init(){
    predicateToID.insert({"arc", _arc});
    factory.addPredicate();
    predicateToID.insert({"reach", _reach});
    factory.addPredicate();
    Executor::predicateIds.push_back("reach");
    Executor::predicateIds.push_back("arc");
}
inline void insertTrue(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        preach_.insert2VecNoColl(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        parc_.insert2VecNoColl(*insertResult.first);
        parc_0_.insert2VecNoColl(*insertResult.first);
    }
}
void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){
    const auto& insertResult = t->setStatus(TruthStatus::True);
    insertTrue(insertResult);
    printTuple(t);
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            const std::vector<int>* tuples;
            tuples = &parc_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    t = factory.addNewInternalTuple({X,Y}, _reach);
                    if(t->isUnknown()){
                        printTuple(t);
                        insertResult = t->setStatus(TruthStatus::True);
                        insertTrue(insertResult);
                    }
                }//close par
            }//close par
        }//close par
        {
            const std::vector<int>* tuples;
            tuples = &preach_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size(); i++){
                const Tuple * tuple0 = NULL;
                tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    const std::vector<int>* tuples;
                    tuples = &parc_0_.getValuesVec({Y});
                    for(unsigned i = 0; i < tuples->size(); i++){
                        const Tuple * tuple1 = NULL;
                        tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        if(tuple1!= NULL){
                            int Z = (*tuple1)[1];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            t = factory.addNewInternalTuple({X,Z}, _reach);
                            if(t->isUnknown()){
                                printTuple(t);
                                generatedStack.push_back(t->getId());
                                insertResult = t->setStatus(TruthStatus::True);
                                insertTrue(insertResult);
                            }
                        }//close par
                    }//close par
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            if(literalName == _reach){
                {
                }//close par
            }
        }
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &parc_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        parc_.clear();
        parc_0_.clear();
    }
    //Removing tuples of predicates that have been completely defined
    {
        const std::vector<int>* tuplesToRemove;
        tuplesToRemove = &preach_.getValuesVec({});
        for(unsigned i = 0; i< tuplesToRemove->size(); ++i){
            factory.destroyTuple(tuplesToRemove->at(i));
        }
        preach_.clear();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
