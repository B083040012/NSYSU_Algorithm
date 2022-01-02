# ifndef __SA_H__
# define __SA_H__

#include "../src/backpack.h"
#include <climits>
#include <math.h>

class SA{
    private:
        backpack myBackpack;
        int initTemp,restrictTemp,currentTemp;
        int priceCurrent,priceBest,priceNew;
        vector<bool> takeCurrent,takeBest,takeNew;
        int markovLength,ratio,p;
        string writeDir,writeId;
    public:
        SA();
        void genInittake();
        void SAMethod();
        int calculatePrice();
        int calculateWeight();
        void writeTxt();
        void setBackpack(string);
};

#endif