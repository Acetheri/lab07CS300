#include "evilHangman.h"
#include "hangman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> 


std::string arr[466550];


void readTXT(){
    std::fstream myFile;
    std::string temp;
    int i =0;
    if(myFile.is_open()){
        while(getline(myFile, temp)){
            arr[i] = temp;
            i++;
        }
    }
}






int main(){
    readTXT();
    for(int j = 0; j < 466550; j++){
        std::cout << arr[j] << std::endl;
    }
    int i = (rand() % (466550));
    evilHangman eh = evilHangman(arr[i]);
}



