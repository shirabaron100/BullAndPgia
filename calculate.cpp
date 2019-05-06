#include <iostream>
#include "Chooser.hpp"
#include "Guesser.hpp"
#include "calculate.hpp"
#include <cstring>
namespace bullpgia {
  std::string calculateBullAndPgia(std::string choice, std::string guess){
    string copyGuess(guess);
    int bull=0;
    int pgia=0;
      for (int i=0;i<choice.length();i++)
      {
      if (choice.at(i)==guess.at(i))
      {
       bull++;
       copyGuess.at(i)='!';
      }
      }
      for (int i=0;i<choice.length();i++)
      {
        for (int j=0;j<copyGuess.length();j++)
        {
 
          if (choice.at(i)==copyGuess.at(j))
          { 
            pgia++;
            copyGuess.at(j)='!';
          }
        }
      }
     
      string answer=std::to_string(bull)+','+std::to_string(pgia);
      return answer;
  }
}