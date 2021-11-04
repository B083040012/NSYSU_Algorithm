# ifndef __ES_CPP__
# define __ES_CPP__

#include "ES.h"

// constructor of ES method,set write txt in 'answer folder'
ES::ES(){
    myBackpack = backpack();
    priceAns = 0;
    takeList.resize(myBackpack.getItemNum(), 0);
    writeId="";
    writeDir = "answer";
    timeSet=false;
}

// main ES method,using prev_permutation for finding best solution--> may occur timeout
void ES::esMethod(){
    int itemNum = myBackpack.getItemNum();
    vector<bool> takeListTmp;
    takeListTmp.resize(itemNum, 0);
    for (int takeNum = 1; takeNum <= itemNum; takeNum++){
        for (int ini = 0; ini < takeListTmp.size();ini++)
            takeListTmp[ini] = 0;
        for (int m = 0; m < takeNum; m++)
            takeListTmp[m] = 1;

        do
        {
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
        } while(std::prev_permutation(takeListTmp.begin(), takeListTmp.end()) && !this->timeSet);
    }
}

// set timeSet when timeout
void ES::modSet(){
    this->timeSet=true;
}

// show solution
void ES::show(){
    cout << "priceAns:" << priceAns << endl;
    cout << "takeList:\n";
    for (int i = 0; i < takeList.size();i++){
        cout << takeList[i] << endl;
    }
}

// write solution into txt place in 'answer'
void ES::writeTxt(){
    string fileName=this->writeId;
    ofstream write;
    write.open(writeDir + "/" + "ans_ds" + fileName + ".txt");
    if(!write){
        cout << writeDir + "/" + "ans_ds" + fileName + ".txt" << " cannot open.\n";
    }
    else{
        write << priceAns;
        for (int w = 0; w < takeList.size();w++){
            write << endl << takeList[w];
        }
    }
}

// check if timeout or not
bool ES::gettimeSet(){
    return this->timeSet;
}

// initialize backpack by input file
void ES::setBackpack(string inputDir){
    this->writeId=inputDir.back();
    myBackpack.process(inputDir);
    cout << "\n\nbackpack information:\n";
    cout << "============================\n";
    myBackpack.show();
    cout << "\n============================\n";
    cout << "\nesMethod executing:...\n";
}

# endif