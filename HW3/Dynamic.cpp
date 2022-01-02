# ifndef DYNAMIC_CPP
# define DYNAMIC_CPP

#include"Dynamic.h"

// constructor of greedy method
Dynamic::Dynamic(){
    myBackpack=backpack();
    priceDP.resize(myBackpack.getItemNum(),0);
    takeList.resize(myBackpack.getItemNum());
    takeListWrite.resize(myBackpack.getItemNum(),0);
    writeDir="answer/";
}

// DP method by 1-D vector
// price[i,j]=max(price[i-1,j] , price[i-1,j-weight[i]]+value[i])
void Dynamic::DPMethod(){
    int itemNum=myBackpack.getItemNum();
    int cap=myBackpack.getCapability();

    vector<bool> subTakeList;
    subTakeList.resize(cap+1,false);
    takeList.resize(itemNum,subTakeList);
    takeListWrite.resize(myBackpack.getItemNum(),false);

    priceDP.resize(cap+1,0);

    cout << "vector setDone\n";

    for(int itemIndex=0;itemIndex<itemNum;itemIndex++){
        int itemWeight=myBackpack.getWeight(itemIndex);
        int itemPrice=myBackpack.getPrice(itemIndex);
        for(int remainCap=cap;remainCap>=itemWeight;remainCap--){
            if(priceDP[remainCap-itemWeight]+itemPrice>priceDP[remainCap]){
                priceDP[remainCap]=priceDP[remainCap-itemWeight]+itemPrice;
                takeList[itemIndex][remainCap]=true;
            }
        }
    }
}

// show the result
void Dynamic::show(){
    int cap=myBackpack.getCapability();
    int itemNum=myBackpack.getItemNum();
    cout << "=================\n";
    cout << "Final Answer=" << priceDP[cap] << endl;
    cout << "=================\n\n";

    for(int i=itemNum-1,j=cap;i>=0;i--){
        if(takeList[i][j]){
            takeListWrite[i]=true;
            j-=myBackpack.getWeight(i);
        }
    }

    cout << "End of DP Processing\n";
}

// write result to txt file
void Dynamic::writeTxt(){
    string filename=this->writeId;
    ofstream write;
    write.open(writeDir+"/"+"ans_ds"+filename+".txt");
    if(!write){
        cout << writeDir+"/"+"ans_ds"+filename+".txt" << " cannot open.\n";

    }
    else{
        write << priceDP[myBackpack.getCapability()] << endl;
        for(int i=0;i<takeListWrite.size();i++){
            write << takeListWrite[i] << endl;
        }
    }
}

// set backpack attributes
void Dynamic::setBackpack(string inputDir){
    this->writeId=inputDir.back();
    myBackpack.process(inputDir);
    cout << "\n\nbackpack information\n";
    cout << "===========================\n";
    myBackpack.show();
    cout << "\n===========================\n\n\n";
}

# endif