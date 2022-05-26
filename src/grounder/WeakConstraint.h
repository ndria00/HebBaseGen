#include "Rule.h"

class WeakConstraint : public Rule{
    private:
        int levelPayed;
        std::vector<Term*> weightTerms;
        
    public:
        WeakConstraint();
        int getLevelPayed()const;
        void setLevelPayed(int);
        const std::vector<Term*>& getWeightTerms()const;
        void setWeightTerms(std::vector<Term*>&);
        
};