#include "SA.h"
#include<sys/stat.h>

int main(int argc,char *argv[]){
    // mkdir 'answer' folder
    const int dir_err = mkdir("answer", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    string inputFile;
    vector<string> command;
    if(argc>1){
        command.assign(argv,argv+argc);
        for(int i=1;i<argc;i++){
            if(command[i]=="-input"){
                inputFile=command[i+1];
                i++;
            }
        }
    }

    SA mySA;
    mySA.setBackpack(inputFile);
    cout << "Initialize Take List...\n";
    mySA.genInittake();
    cout << "\nSA Method executing...\n\n\n";
    mySA.SAMethod();
    cout << "SA Complete\n";
    cout << "writing ans file...\n";
    mySA.writeTxt();
    cout << "complete writing\n";
}