#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
#include <list>
#include <iterator>
using std::string;

string SmartGuesser::guess() {
    this->whatTOguess=this->myOptions.front();
    return this->whatTOguess;
}
void SmartGuesser::startNewGame(uint length){  
    this->length=length;
    int time =1;
     for (int i=0;i<this->length;i++){
           time=time*10;
     }
    // std::cout << time << std::endl;
    for (int i=0;i<time;i++)
    {
    string s=SmartGuesser::convertIndexTOstr(i);
    this->myOptions.push_back(s);
    }
}
void SmartGuesser::learn(string reply){ 
    
    for (auto itr = myOptions.begin(); itr != myOptions.end(); itr++)
    { 
        if (bullpgia::calculateBullAndPgia(*itr,whatTOguess).compare(reply)!=0)
        {
          itr = myOptions.erase(itr);
        }
    }
}
 string SmartGuesser::convertIndexTOstr(int j){
    string s;
    string i=std::to_string(j);
    //std::cout << "i" <<  i << std::endl;
    if (this->length==4)
    {
    if (j<10)
    {
    s="000"+i;
    }
    else if (j<100)
    {
    s="00"+i;
    }
    else if (j<1000)
    {
    s="0"+i;
    }
    else 
    s=i;
    }
    else if (this->length==3)
    {
    if (j<10)
    {
    s="00"+i;
    }
    else if (j<100)
    {
    s="0"+i;
    }
    else if (j<1000)
    {
    s=i;
    }
    else 
    s="??";
 }
else if (this->length==2)
  
  {
    if (j<10)
    {
    s="0"+i;
    }
    else if (j<100)
    {
    s=i;
    }
    else
    {
    s="??";
    }
  }
  else
  {
      if (j<10)
      s=i;
      else
      {
          s="??";
      }
      
  } 
    return s;
 }