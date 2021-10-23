# ifndef __ES_H__
# define __ES_H__

#include "src/backpack.h"
#include<algorithm>
#include<fstream>

class ES{
    private:
        backpack myBackpack;
        int priceAns;
        vector<bool> takeList;
        string writeDir;

    public:
        ES(string);
        void esMethod();
        void show();
        void writeTxt(string);
        void process();
};

# endif