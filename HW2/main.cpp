#include "Greedy.h"
#include<sys/stat.h>

int main(int argc, char *argv[]){
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

    Greedy myGreedy;
    myGreedy.setBackpack(inputFile);
    cout << "\ngreedy Method executing:...\n";
    myGreedy.greedyMethod();
    cout << "\n\n";
    myGreedy.show();
    cout << "writing ans file...\n";
    myGreedy.writeTxt();
    cout << "complete writing\n";
}
