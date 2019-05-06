#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
using std::string;

string SmartGuesser::guess() {

     for (int i=0;i<10000;i++)
    {
        //std::cout << "shira" << i  << std::endl;
        if (this->a[i]==true)
        {
        // std::cout << "index" << i  << std::endl;
        this->whatTOguess=SmartGuesser::convertIndexTOstr(i);
         return this->whatTOguess;
        }
       // std::cout << " what" << this->whatTOguess.length() << std::endl;
    }

}
void SmartGuesser::startNewGame(uint length){  
    this->length=length;
    //std::cout << "length" << this->length <<  std::endl;
    for (int i=0;i<10000;i++)
    {
        this->a[i]=true;
    }
}
void SmartGuesser::learn(string reply){ 
    
    for (int i=0;i<10000;i++)
    {
        //std::cout << "i" << i << std::endl;
        string s=SmartGuesser::convertIndexTOstr(i);
       if(s.compare("??")==0)
       return;
        if (bullpgia::calculateBullAndPgia(s,whatTOguess).compare(reply)!=0)
        {
          //std::cout << "false" << std::endl;
            this->a[i]=false;
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