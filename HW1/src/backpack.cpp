# include "backpack.h"

backpack::backpack(){
    itemNum=capability = 0;
    weight.clear();
    price.clear();
    fileDir = "dataset/";
    dataId = "ds1";
}

backpack::backpack(string Id){
    itemNum=capability = 0;
    weight.clear();
    price.clear();
    fileDir = "dataset/";
    dataId = Id;
}

void backpack::readFile(string dataItem){
    ifstream read;
    string readNumber;
    string dir = fileDir + dataId + "/" + dataItem+".txt";
    read.open(dir,ios::in);
    if(!read){
        cout << "file" << dir << " cannot open\n";
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

string backpack::getDataId(){
    return dataId;
}

void backpack::process(){
    this->readFile("c");
    this->readFile("w");
    this->readFile("p");
    this->itemNum = weight.size();
}