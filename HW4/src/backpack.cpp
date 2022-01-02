# include "backpack.h"


// constructor for backpack
backpack::backpack(){
    itemNum=capability = 0;
    weight.clear();
    price.clear();
    fileDir = "dataset/";
}

backpack::backpack(string Id){
    itemNum=capability = 0;
    weight.clear();
    price.clear();
    fileDir = "dataset/";
}

// read file from dataItem input by user
void backpack::readFile(string dataItem){
    ifstream read;
    string readNumber;
    string dir = fileDir + "/" + dataItem +".txt";
    read.open(dir,ios::in);
    if(!read){
        cout << "file:" << dir << " cannot open\n";
    }
    else{
        while(getline(read,readNumber)){
            if(dataItem=="c"){
                capability = atoi(readNumber.c_str());
            }
            else if(dataItem=="w"){
                this->weight.push_back(atoi(readNumber.c_str()));
            }
            else if(dataItem=="p"){
                this->price.push_back(atoi(readNumber.c_str()));
            }
        }
    }
}

// get member attributes of backpack
int backpack::getWeight(int i){
    return weight[i];
}

int backpack::getPrice(int i){
    return price[i];
}

int backpack::getCapability(){
    return capability;
}

int backpack::getItemNum(){
    return itemNum;
}

// display backpack information
void backpack::show(){
    cout << "capability: " << this->capability << endl;
    cout << "number of item:" << this->itemNum << endl;
    cout << "weight: " << endl;
    for (int i = 0; i < this->weight.size();i++){
        cout << this->weight[i] << " ";
    }
    cout << "\nprice: " << endl;
    for (int i = 0; i < this->price.size();i++){
        cout << this->price[i] << " ";
    }
}

// public interface called by backpack method
void backpack::process(string inputDir){
    this->fileDir=inputDir;
    this->readFile("c");
    this->readFile("w");
    this->readFile("p");
    this->itemNum = weight.size();
}