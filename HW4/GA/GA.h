# ifndef __GA_H__
# define __GA_H__

# include "../src/backpack.h"
# include<climits>
# include<algorithm>

class GA{
    private:
        backpack myBackpack;
        int itemNum;
        double crossRate,mutateRate,insertRate;
        int popSize,genSize;
        vector<vector<bool>> population;
        vector<bool> bestTakeList;
        int bestPrice;
        string writeId,writeDir;
    public:
        GA();
        void setInitPop();
        void GAMethod();
        vector<double> calFitness();
        int calPrice(vector<bool>);
        int calWeight(vector<bool>);
        void crossover();
        void select();
        void mutate();
        void writeTxt();
        void setBackpack(string);
};

# endif