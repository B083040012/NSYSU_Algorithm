# ifndef __ES_CPP__
# define __ES_CPP__

#include "ES.h"

ES::ES(string dataId){
    myBackpack = backpack(dataId);
    priceAns = 0;
    takeList.resize(myBackpack.getItemNum(), 0);
    writeDir = "answer/";
}

void ES::esMethod(){
    int itemNum = myBackpack.getItemNum();
    cout << "itemNum: " << itemNum << endl;
    vector<bool> takeListTmp;
    takeListTmp.resize(itemNum, 0);
    for (int takeNum = 1; takeNum <= itemNum; takeNum++){
        for (int ini = 0; ini < takeListTmp.size();ini++)
            takeListTmp[ini] = 0;
        for (int m = 0; m < takeNum; m++)
            takeListTmp[m] = 1;

        cout << "\n\nwhen takeNum=" << takeNum << endl;

        do
        {
            cout << "check:" << endl;
            for (int p = 0; p < takeListTmp.size();p++)
                cout << takeListTmp[p] << " ";
            cout << endl;
            int priceAnsTmp = 0, capTmp = myBackpack.getCapability();
            for (int takeIndex = 0; takeIndex < itemNum; takeIndex++)
            {
                if (takeListTmp[takeIndex])
                {
                    capTmp -= myBackpack.getWeight(takeIndex);
                    priceAnsTmp += myBackpack.getPrice(takeIndex);
                }
            }
            if (priceAnsTmp > priceAns && capTmp >= 0)
            {
                priceAns = priceAnsTmp;
                takeList = takeListTmp;
            }
        } while(std::prev_permutation(takeListTmp.begin(), takeListTmp.end()));
    }
}

void ES::show(){
    cout << "priceAns:" << priceAns << endl;
    cout << "takeList:\n";
    for (int i = 0; i < takeList.size();i++){
        cout << takeList[i] << endl;
    }
}

void ES::writeTxt(string fileName){
    ofstream write;
    write.open(writeDir + "ans_" + fileName + ".txt");
    if(!write){
        cout << writeDir + fileName << " cannot open.\n";
    }
    else{
        write << priceAns;
        for (int w = 0; w < takeList.size();w++){
            write << endl << takeList[w];
        }
    }
}

void ES::process(){
    myBackpack.process();
    cout << "\n\nbackpack information:\n";
    cout << "============================\n";
    myBackpack.show();
    cout << "\n============================\n";
    cout << "\nesMethod executing:...\n";
    this->esMethod();
    cout << "\n\n";
    this->show();
    cout << "writing ans file...\n";
    this->writeTxt(myBackpack.getDataId());
    cout << "complete writing\n";
}

# endif