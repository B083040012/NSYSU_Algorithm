# ifndef __GREEDY_H__
# define __GREEDY_H__

#include "src/backpack.h"
#include<algorithm>
#include<fstream>

class Greedy{
    private:
        backpack myBackpack;
        int priceAns;
        vector<bool> takeList;
        string writeDir,writeId;

    public:
        Greedy();
        void greedyMethod();
        void show();
        void writeTxt();
        void setBackpack(string);
};

#endif