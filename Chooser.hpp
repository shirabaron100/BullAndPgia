#pragma once
#include <string>
#include <iostream>
#include "calculate.hpp"
using namespace std;
namespace bullpgia {
    class Chooser{
        public:
        uint length;
virtual string choose(uint length)=0;
    };
}