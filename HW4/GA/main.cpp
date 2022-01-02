#include "GA.h"
#include<sys/stat.h>

int main(int argc,char *argv[]){
    // mkdir 'answer' folder
    const int dir_err = mkdir("answer", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    string inputFile;
    vector<string> command;
    if(argc>1){
        command.assign(argv,argv+argc);
        for(int i=1;i<argc;i++){
            inputFile=command[i+1];
            i++;
        }
    }

    GA myGA;
    myGA.setBackpack(inputFile);
    cout << "\nSA Method executing...\n\n\n";
    myGA.GAMethod();
    cout << "GA Complete\n";
    cout << "Writing Ans File...\n";
    myGA.writeTxt();
    cout << "\nComplete Writing\n";
}