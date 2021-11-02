#include "ES.h"
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<sys/stat.h>

bool timeSet=false;

ES myES;

void handler(int sigNum){
    if(sigNum==SIGALRM){
        cout << "over time (60 seconds)\n";
        myES.modSet();
    }
}

int main(int argc, char *argv[]){
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

    myES.setBackpack(inputFile);
    // set timer if timeout
    signal(SIGALRM,handler);
    alarm(60);
    myES.esMethod();
    cout << "\n\n";
    myES.show();
    if(myES.gettimeSet()) cout << "not done in 1 minute\n";
    cout << "writing ans file...\n";
    myES.writeTxt();
    cout << "complete writing\n";
}
