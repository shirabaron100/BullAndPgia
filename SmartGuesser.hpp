#pragma once
#include <iostream>
#include "Guesser.hpp"
#include "calculate.hpp"
using std::string;
class SmartGuesser: public bullpgia::Guesser{
  
 public:
 string guess()override;
 void startNewGame(uint length) override;
 void learn(string reply) override;
  };
