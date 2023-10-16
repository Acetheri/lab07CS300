#include "hangman.h"
#include <iostream>
#include <string>




  void hangman::displayBoard(){
    std::cout << "The current Board is" << std::endl;
    for(int i = 0; i < wordLength; i++){
      std::cout << " " << display.at(i);
    }
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
  }


  int hangman::updateBoard(char c){
    int letters =0;
    for(int i = 0; i < wordLength; i++){
      if(word.at(i) == c){
        display.at(i) = c;
        letters++;
      }
    }
    if(letters > 0){
      return 1;
    }else return 0;
  }

  int hangman::checkGuess(std::string guess){
    if(word.compare(guess) == 0){
      return 1;
    }
    return 2;
  }

  int hangman::countGuesses(){
    return guessesLeft;
  }


  
  

  int hangman::turn(){
    std::cout << "Would you like to guess the word or guess a letter?" << std::endl << "1 for word, 2 for letter" << std::endl;
    std::string temp;
    std::cin >> temp;
    if(temp == "1"){
      std::cout << "What is your guess?" << std::endl;
      std::cin >> temp;
      if(checkGuess(temp) == 1) {
        for(int i = 0; i < wordLength; i++){
          updateBoard(word.at(i));
        }
        return 1;
      } else{
        guessesLeft--;
        if(countGuesses() == 0) return 2;
        std::cout << "Incorrect guess, try again" << std::endl;
        return 0;
      }
    }else if(temp == "2"){
      std::cout << "What is your guess?" << std::endl;
      char temp2;
      std::cin >> temp2;
      if(updateBoard(temp2) != 0){
        std::cout << "Goodjob that letter is in the word" << std::endl;
        if(checkGuess(display) == 1) return 0; 
      } else{
        guessesLeft--;
        if(countGuesses() == 0) return 2;
        std::cout << "Letter is not there please try again" << std::endl;
        return 0;
      }
    }
    return 0;
  }


  void hangman::play(){
    int gameState = 0;
    std::cout << "Welcome to the hangman game." << std::endl;
    displayBoard();
    while(gameState == 0){
      gameState = turn();
      displayBoard();
    }
    if(gameState == 1){
      std::cout << "Congrats you won the game!" << std::endl;
    }
    else std::cout << "Sorry you lost the game" << std::endl;
  }



int main(){
  hangman hg = hangman("computer", 5);
  hg.play();
  }


