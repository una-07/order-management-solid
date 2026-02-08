#pragma once
#include <string>
using namespace std;

class IScannable {
public:
    virtual void Scan(string text) = 0;
};

