#include "hangman.h"
#include <string>
#include <fstream>
#ifndef evilHangman_h
#define evilHangman_h

class evilHangman :public hangman{
    std::string hidden;
    


public:


  evilHangman(std::string hid){
    hangman h = hangman(hid, 5);
  }    
   

     


};


#endif