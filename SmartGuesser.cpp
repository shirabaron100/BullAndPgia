#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
using std::string;


string SmartGuesser::guess() {

  std::cout << "guess" << std::endl;
     for (int i=0;i<10000;i++)
    {
        if (this->a[i]==true)
        this->whatTOguess=SmartGuesser::convertIndexTOstr(i);
    }
 return this->whatTOguess;
}
void SmartGuesser::startNewGame(uint length){  
    this->length=length;
    for (int i=0;i<10000;i++)
    {
        this->a[i]=true;
    }
}
void SmartGuesser::learn(string reply){ 
    std::cout << "roio" << std::endl;
    for (int i=0;i<10000;i++)
    {
        
        string s=SmartGuesser::convertIndexTOstr(i);

        if (bullpgia::calculateBullAndPgia(s,whatTOguess).compare(reply)!=0)
        {
 // std::cout << "false" << std::endl;
            this->a[i]=false;
        }
    }
}
 string SmartGuesser::convertIndexTOstr(int j){
    string s;
    string i=std::to_string(j);
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
    return s;
 }