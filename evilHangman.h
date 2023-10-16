#include "hangman.h"
#include <string>
#include <fstream>
#ifndef evilHangman_h
#define evilHangman_h

class evilHangman : public hangman{
    std::string array[466550];
    std::string hidden;
    


public:

    evilHangman();
    
    void printArray();
    
    void readTXT();

     


};


#endif