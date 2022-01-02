# ifndef __SA_CPP__
# define __SA_CPP__

# include "SA.h"

// constructor of SA
SA::SA(){
    myBackpack=backpack();
    currentTemp=initTemp=1000;
    restrictTemp=1;
    priceCurrent=priceBest=INT_MIN;
    markovLength=10000;
    ratio=0.99;
    writeDir="answer/";
}

// initialize SA attributes
void SA::genInittake(){
    srand(time(NULL));
    int itemNum=myBackpack.getItemNum();
    takeNew.resize(itemNum,0);
    for(int i=0;i<itemNum;i++){
        takeNew[i]=rand()%2;
    }

    cout << "init takeNew...\n";
    for(int i=0;i<itemNum;i++){
        cout << takeNew[i] << " ";
    }
    cout << endl;
    
    takeCurrent=takeNew;
    takeBest=takeNew;
}

// SA method
void SA::SAMethod(){
    srand(time(NULL));
    int itemNum=myBackpack.getItemNum();
    int cap=myBackpack.getCapability();
    while(currentTemp>restrictTemp){
        for(int marLoop=0;marLoop<markovLength;marLoop++){
            int newTakeProb=rand()%2;
            
            // modified take list way #1
            // randomly pick one bit and reverse it
            if(newTakeProb==0){
                int index1=rand()%itemNum;
                int index2=rand()%itemNum;
                while(index1==index2) index2=rand()%itemNum;
                if(takeNew[index1]==0) takeNew[index1]=1;
                else takeNew[index1]=0;
                if(takeNew[index2]==0) takeNew[index2]=1;
                else takeNew[index2]=0;
                // takeNew[index]=~(takeNew[index]);
            }

            // modified take list way #2
            // randomly pick two bit and swap it
            else if(newTakeProb==1){
                int index1=rand()%itemNum,index2=rand()%itemNum;
                while(index1==index2){
                    index2=rand()%itemNum;
                }
                swap(takeNew[index1],takeNew[index2]);
            }

            while(this->calculateWeight()>cap){
                // modified take list if weight exceed capability
                // randomly pick a bit '1' and reverse it
                int index=rand()%itemNum;
                while(takeNew[index]!=true) index=rand()%itemNum;
                takeNew[index]=false;
            }

            priceNew=this->calculatePrice();
            
            if (priceNew>priceCurrent){
                priceCurrent=priceNew;
                takeCurrent=takeNew;
                if(priceNew>priceBest){
                    priceBest=priceNew;
                    takeBest=takeNew;
                    cout << "priceBest update:" << priceBest << endl;
                }
            }
            else{
                double prob=rand()%100001;
                prob=prob/100000.0;
                double acceptProb=exp((priceNew-priceCurrent)/currentTemp);
                if(prob<acceptProb){
                    // accept the bad result
                    priceCurrent=priceNew;
                    takeCurrent=takeNew;
                }
                else{
                    takeNew=takeCurrent;
                }
            }
        }
        currentTemp=currentTemp*ratio;
    }
    cout << "\n======================\n";
    cout << "Final result...\n";
    cout << "Best Price: " << priceBest << endl;
    cout << "Best Take List:\n";
    for(int i=0;i<itemNum;i++){
        cout << takeBest[i] << " ";
    }
    cout << "\n======================\n";
    cout << endl;
}

// calculate price of the takeList
int SA::calculatePrice(){
    int price=0;
    int itemNum=myBackpack.getItemNum();
    for(int i=0;i<itemNum;i++){
        price+=myBackpack.getPrice(i)*takeNew[i];
    }
    return price;
}

// calculate weight of the takeList
int SA::calculateWeight(){
    int weight=0;
    int itemNum=myBackpack.getItemNum();
    for(int i=0;i<itemNum;i++){
        weight+=myBackpack.getWeight(i)*takeNew[i];
    }
    return weight;
}

// write result to txt file
void SA::writeTxt(){
    string filename=this->writeId;
    ofstream write;
    write.open(writeDir+"/"+"ans_ds"+filename+".txt");
    if(!write){
        cout << writeDir+"/"+"ans_ds"+filename+".txt" << " cannot open.\n";

    }
    else{
        write << priceBest << endl;
        for(int i=0;i<takeBest.size();i++){
            write << takeBest[i] << endl;
        }
    }
}

void SA::setBackpack(string inputDir){
    this->writeId=inputDir.back();
    myBackpack.process(inputDir);
    cout << "\n\nbackpack information:\n";
    cout << "============================\n";
    myBackpack.show();
    cout << "\n===========================\n\n\n";
}

# endif