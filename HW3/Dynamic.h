# ifndef DYNAMIC_h
# define DYNAMIC_H

#include "src/backpack.h"

class Dynamic{
    private:
        backpack myBackpack;
        vector<int> priceDP;
        vector<vector<bool>> takeList;
        vector<bool> takeListWrite;
        string writeDir,writeId;
    public:
        Dynamic();
        void DPMethod();
        void show();
        void writeTxt();
        void setBackpack(string);
};

# endif