# ifndef __GREEDY_CPP__
# define __GREEDY_CPP__

#include"Greedy.h"

// compare value in vector by cpValue--> price
int cmp(pair<pair<double,int>,int>a,pair<pair<double,int>,int>b){
    if(a.first.first!=b.first.first) return a.first.first>b.first.first;
    else return a.first.second<b.first.second;
}

// constructor of greedy method
Greedy::Greedy(){
    myBackpack=backpack();
    priceAns=0;
    takeList.resize(myBackpack.getItemNum(),0);
    writeDir="answer/";
}

// main greedy method,sorted items by cpValue than choose by sorted result
void Greedy::greedyMethod(){
    int itemNum=myBackpack.getItemNum();
    int cap=myBackpack.getCapability();
    vector<pair<pair<double,int>,int>> cpList;
    for(int cpCal=0;cpCal<itemNum;cpCal++){
        double priceCur=myBackpack.getPrice(cpCal);
        double weightCur=myBackpack.getWeight(cpCal);
        cpList.push_back(make_pair(make_pair((priceCur/weightCur),myBackpack.getPrice(cpCal)),cpCal));
    }

    sort(cpList.begin(),cpList.end(),cmp);

    takeList.resize(myBackpack.getItemNum(),0);
    for(int choose=0;choose<cpList.size();choose++){
        int capTmp=cap-myBackpack.getWeight(cpList[choose].second);
        if(capTmp<0) continue;
        cap-=myBackpack.getWeight(cpList[choose].second);
        priceAns+=cpList[choose].first.second;
        takeList[cpList[choose].second]=1;
    }
}

// display result of greedy method
void Greedy::show(){
    cout << "priceAns=" << priceAns << endl;
    cout << "takeList:\n";
    for(int i=0;i<takeList.size();i++){
        cout << takeList[i] << endl;
    }
}

// write txt in 'answer' folder
void Greedy::writeTxt(){
    string fileName=this->writeId;
    ofstream write;
    write.open(writeDir + "/" + "ans_" + fileName + ".txt");
    if(!write){
        cout << writeDir + "/" + "ans_" + fileName + ".txt" << " cannot open.\n";
    }
    else{
        write << priceAns;
        for (int w = 0; w < takeList.size();w++){
            write << endl << takeList[w];
        }
    }
}

// initialize backpack
void Greedy::setBackpack(string inputDir){
    this->writeId=inputDir.back();
    myBackpack.process(inputDir);
    cout << "\n\nbackpack information:\n";
    cout << "============================\n";
    myBackpack.show();
    cout << "\n============================\n";
    cout << "\n\n";
}

# endif