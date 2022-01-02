# ifndef __GA_CPP__
# define __GA_CPP__

#  include "GA.h"

// constructor of GA
GA::GA(){
    myBackpack=backpack();
    crossRate=0.7;
    mutateRate=0.1;
    insertRate=0.5;
    popSize=500;
    genSize=500;
    population.resize(popSize);
    writeDir="answer/";
}

// set initial population
void GA::setInitPop(){
    srand(time(NULL));
    vector<bool> dna;
    dna.resize(itemNum,false);
    for(int initPop=0;initPop<popSize;initPop++){
        for(int initDna=0;initDna<itemNum;initDna++){
            dna[initDna]=rand()%2;
        }
        population[initPop]=dna;
    }
}

// GA method
// select--> crossover--> mutate--> select--> ...
void GA::GAMethod(){
    cout << "Initialize Population...\n";
    this->setInitPop();
    int maxPrice=0;
    for(int genTimes=0;genTimes<genSize;genTimes++){
        this->select();
        maxPrice=0;
        for(int findIndex=0;findIndex<popSize;findIndex++){
            if(this->calPrice(population[findIndex])>maxPrice){
                maxPrice=this->calPrice(population[findIndex]);
                bestTakeList=population[findIndex];
            }
        }

        cout << "=====================\n";
        cout << "Gen Times: " << genTimes << endl;
        cout << "Best Price=" << maxPrice << endl;
        cout << "weight:" << this->calWeight(bestTakeList) << endl;
        cout << "=====================\n";
        this->crossover();
        this->mutate();
    }
    bestPrice=maxPrice;
}

// calculate fitness and set 0 to those overweight population
vector<double> GA::calFitness(){
    vector<double> fitness;
    fitness.resize(popSize,0);
    for(int dnaIndex=0;dnaIndex<popSize;dnaIndex++){
        int weightSum=this->calWeight(population[dnaIndex]);
        if(weightSum>myBackpack.getCapability()){
            fitness[dnaIndex]=0;
            continue;
        }
        else{
            fitness[dnaIndex]=this->calPrice(population[dnaIndex]);
        }
    }
    return fitness;
}

int GA::calWeight(vector<bool> dna){
    int weightSum=0;
    for(int chromIndex=0;chromIndex<itemNum;chromIndex++){
        weightSum+=dna[chromIndex]*myBackpack.getWeight(chromIndex);
    }
    return weightSum;
}

int GA::calPrice(vector<bool> dna){
    int priceSum=0;
    for(int chromIndex=0;chromIndex<itemNum;chromIndex++){
        priceSum+=dna[chromIndex]*myBackpack.getPrice(chromIndex);
    }
    return priceSum;
}

void GA::crossover(){
    srand(time(NULL));
    vector<vector<bool>> originalPopI(population.begin(),population.begin()+(popSize/2));
    vector<vector<bool>> originalPopII(population.begin()+(popSize/2),population.end());
    std::random_shuffle(originalPopI.begin(),originalPopI.end());
    std::random_shuffle(originalPopII.begin(),originalPopII.end());
    for(int parentI=0,parentII=0;parentI<popSize/2,parentII<popSize/2;parentI++,parentII++){
        double crossProb=(rand()%11)/10.0;
        if(crossProb<crossRate){
            int crossPointI=rand()%itemNum;
            int crossPointII=rand()%itemNum;
            while(crossPointI==crossPointII) crossPointII=rand()%itemNum;
            if(crossPointI>crossPointII) swap(crossPointI,crossPointII);
            for(int crossIndex=crossPointI;crossIndex<=crossPointII;crossIndex++){
                swap(originalPopI[parentI][crossIndex],originalPopII[parentII][crossIndex]);
            }
        }
    }
}

void GA::select(){
    vector<double>fitnessProb=calFitness();
    vector<bool> subNew;
    subNew.resize(0,false);
    vector<vector<bool>> populationNew;
    populationNew.resize(popSize,subNew);
    double fitnessSum=0;
    for(int fitIndex=0;fitIndex<popSize;fitIndex++){
        fitnessSum+=fitnessProb[fitIndex];
    }
    // calculate the selected probability (fitness/fitness_sum) for each DNA
    for(int fitIndex=0;fitIndex<popSize;fitIndex++){
        fitnessProb[fitIndex]/=fitnessSum;
    }
    // apply routtle wheel for selecting DNA
    // sum the probability for each DNA in routtle wheel
    double tmp=fitnessProb[0];
    int lastIndex=0;
    for(int fitIndex=1;fitIndex<popSize;fitIndex++){
        if(fitnessProb[fitIndex]==0) continue;
        else{
            fitnessProb[fitIndex]=tmp+fitnessProb[fitIndex];
            tmp=fitnessProb[fitIndex];
            lastIndex=fitIndex;
        }
    }
    fitnessProb[lastIndex]=1;
    // // DNA with fitness=0 has no chance to be selected
    for(int dnaIndex=0;dnaIndex<popSize;dnaIndex++){
        double selectProb=(rand()%10001)/10000.0000;
        for(int selectDna=0;selectDna<popSize;selectDna++){
            if(fitnessProb[selectDna]==0) continue;
            if(selectProb<=fitnessProb[selectDna]){
                // cout << this->calWeight(population[selectDna]) << endl;
                populationNew[dnaIndex]=population[selectDna];
                break;
            }
        }
    }
    population=populationNew;
}

void GA::mutate(){
    for(int mutateDna=0;mutateDna<popSize;mutateDna++){
        for(int mutateChrom=0;mutateChrom<itemNum;mutateChrom++){
            double mutateProb=(rand()%10001)/10000.0;
            if(mutateProb<mutateRate){
                if(population[mutateDna][mutateChrom]==1) population[mutateDna][mutateChrom]=0;
                else population[mutateDna][mutateChrom]=1;
            }
        }
    }
}

// write result to txt file
void GA::writeTxt(){
    string filename=this->writeId;
    ofstream write;
    write.open(writeDir+"/"+"ans_ds"+filename+".txt");
    if(!write){
        cout << writeDir+"/"+"ans_ds"+filename+".txt" << " cannot open.\n";

    }
    else{
        write << bestPrice << endl;
        for(int i=0;i<bestTakeList.size();i++){
            write << bestTakeList[i] << endl;
        }
    }
}

// set backpack attribute
void GA::setBackpack(string inputDir){
    this->writeId=inputDir.back();
    myBackpack.process(inputDir);
    itemNum=myBackpack.getItemNum();
    cout << "\nBackpack Information:\n";
    cout << "==========================\n";
    myBackpack.show();
    cout << "\n========================\n\n\n";
}

# endif