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
        bool timeSet;
        string writeDir,writeId;

    public:
        ES();
        void esMethod();
        void modSet();
        void show();
        void writeTxt();
        bool gettimeSet();
        void setBackpack(string);
};

# endif