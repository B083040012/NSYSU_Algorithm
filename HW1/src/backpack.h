# ifndef __BACKPACK_H__
# define __BACKPACK_H__

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

/*
 *  build class backpack
 *  attributes:
 *              capcbility: package 
 */

class backpack{
    private:
        int capability, itemNum;
        vector<int> weight, price;
        string fileDir;
        string dataId;

    public:
        backpack();
        backpack(string);
        void readFile(string);
        int getWeight(int);
        int getPrice(int);
        int getCapability();
        int getItemNum();
        string getDataId();
        void show();
        void process();
};

# endif