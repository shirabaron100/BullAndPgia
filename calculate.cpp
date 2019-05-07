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
    int counter [9]={0};
//     std::cout << "choice" << choice << std::endl;
//     std::cout << "guess" << guess << std::endl;
      for (int i=0;i<choice.length()&&i<guess.length();i++)
      {
      if (choice.at(i)==guess.at(i))
      {
       bull++;
       copyGuess.at(i)='!';
      }
      else
      {
        counter[(int)choice.at(i)-(int)'0']++;
      }
      }
        for (int j=0;j<copyGuess.length();j++)
        {
          if (copyGuess.at(j)!='!'&&counter[(int)copyGuess.at(j)-(int)'0']>0)
          {
            counter[(int)copyGuess.at(j)-(int)'0']--;
            pgia++;
          }
        }
      
     
      string answer=std::to_string(bull)+','+std::to_string(pgia);
      return answer;
  }
}