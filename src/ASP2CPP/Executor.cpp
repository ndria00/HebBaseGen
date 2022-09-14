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
AuxMap<0> uarc_({});
AuxMap<0> preach_({});
AuxMap<0> ureach_({});
AuxMap<32> parc_0_({0});
AuxMap<32> uarc_0_({0});
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
        preach_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        parc_.insert2Vec(*insertResult.first);
        parc_0_.insert2Vec(*insertResult.first);
    }
}
inline void insertUndef(const std::pair<const TupleLight *, bool>& insertResult){
    if(insertResult.first->getPredicateName() == _reach){
        ureach_.insert2Vec(*insertResult.first);
    }
    else if(insertResult.first->getPredicateName() == _arc){
        uarc_.insert2Vec(*insertResult.first);
        uarc_0_.insert2Vec(*insertResult.first);
    }
}
void Executor::OnLiteralTrueUndef(Tuple* t, bool disjunctiveFact){
    if(disjunctiveFact){
        const auto& insertResult = t->setStatus(TruthStatus::True);
        insertTrue(insertResult);
    }
    else{
        const auto& insertResult = t->setStatus(TruthStatus::Undef);
        insertUndef(insertResult);
    }
}
void Executor::executeProgram(){
    auto start = std::chrono::high_resolution_clock::now();
    //TODO
    //---------------------------------------Strongly connected component------------------------
    {
        std::vector<int> generatedStack;
        {
            const std::vector<int>* tuples;
            tuples = &parc_.getValuesVec({});
            const std::vector<int>* tuplesU = &uarc_.getValuesVec({});
            for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                const Tuple * tuple0 = NULL;
                if(i < tuples->size()){
                    tuple0 = factory.getTupleFromInternalID(tuples->at(i));
                }
                else {
                    tuple0 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                }
                if(tuple0!= NULL){
                    int X = (*tuple0)[0];
                    int Y = (*tuple0)[1];
                    //Rule is firing 
                    Tuple* t;
                    std::pair<const TupleLight *, bool> insertResult;
                    bool alreadyInFactory = false;
                    if(factory.find({X,Y}, _reach) != NULL){
                        alreadyInFactory = true;
                    }
                    if(!alreadyInFactory){
                        t = factory.addNewInternalTuple({X,Y}, _reach);
                        insertResult = t->setStatus(TruthStatus::True);
                        generatedStack.push_back(t->getId());
                        insertTrue(insertResult);
                    }
                    //negative literals saving
                }//close par
            }//close par
        }//close par
        while(! generatedStack.empty()){
            const Tuple* recursiveTuple = factory.getTupleFromInternalID(generatedStack.back());
            generatedStack.pop_back();
            unsigned literalName = recursiveTuple->getPredicateName();
            {
                int Y = (*recursiveTuple)[1];
                int X = (*recursiveTuple)[0];
                const Tuple* tuple0 = factory.find({X, Y}, _reach);
                if(tuple0!= NULL){
                    const std::vector<int>* tuples;
                    tuples = &parc_0_.getValuesVec({Y});
                    const std::vector<int>* tuplesU = &uarc_0_.getValuesVec({Y});
                    for(unsigned i = 0; i < tuples->size() + tuplesU->size(); i++){
                        const Tuple * tuple1 = NULL;
                        if(i < tuples->size()){
                            tuple1 = factory.getTupleFromInternalID(tuples->at(i));
                        }
                        else {
                            tuple1 = factory.getTupleFromInternalID(tuplesU->at(i-tuples->size()));
                        }
                        if(tuple1!= NULL){
                            int Z = (*tuple1)[1];
                            //Rule is firing 
                            Tuple* t;
                            std::pair<const TupleLight *, bool> insertResult;
                            bool alreadyInFactory = false;
                            if(factory.find({X,Z}, _reach) != NULL){
                                alreadyInFactory = true;
                            }
                            if(!alreadyInFactory){
                                t = factory.addNewInternalTuple({X,Z}, _reach);
                                insertResult = t->setStatus(TruthStatus::True);
                                generatedStack.push_back(t->getId());
                                insertTrue(insertResult);
                            }
                            //negative literals saving
                        }//close par
                    }//close par
                }//close par
            }//close par
        }
    }
    printGeneratedBase();
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()/1000000<<"ms";
}
void Executor::printGeneratedBase(){
    const std::vector<int>* tuples;
    tuples = &parc_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &uarc_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &preach_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
    tuples = &ureach_.getValuesVec({});
    for(unsigned i = 0; i < tuples->size(); ++i){
        printTuple(factory.getTupleFromInternalID(tuples->at(i)));
    }
}
