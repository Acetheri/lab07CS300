#include "evilHangman.h"
#include "hangman.h"
#include <string>
#include <iostream>
#include <fstream>




void evilHangman::readTXT(){
    std::fstream myFile;
    std::string temp;
    int i =0;
    if(myFile.is_open()){
        while(getline(myFile, temp)){
            array[i] = temp;
            i++;
        }
    }
}


void evilHangman::printArray(){
    int length = 466550;
    for(int i = 0; i < length; i++){
        std::cout << array[i] << std::endl;
    }

}



int main(){
    evilHangman eh = evilHangman();
    eh.readTXT();
    eh.printArray();
}



