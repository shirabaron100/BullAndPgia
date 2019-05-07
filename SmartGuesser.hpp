#pragma once
#include <iostream>
#include <list>
#include "Guesser.hpp"
#include "calculate.hpp"
using std::string;
class SmartGuesser: public bullpgia::Guesser{
 private:
 string whatTOguess;
 bool a[10000];
 string convertIndexTOstr(int i);
 public:
 list <string> myOptions;
 string guess()override;
 void startNewGame(uint length) override;
 void learn(string reply) override;
};