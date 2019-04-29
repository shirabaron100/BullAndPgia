#pragma once
#include <string>
#include <iostream>
#include "calculate.hpp"
using namespace std;
namespace bullpgia {
class Guesser{
    public:
    uint length;
    virtual string guess()=0;
    virtual void startNewGame(uint length){};
    virtual void learn(string reply){};
};
}