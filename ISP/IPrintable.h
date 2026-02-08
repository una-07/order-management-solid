#pragma once
#include <string>
using namespace std;

class IPrintable {
public:
    virtual void Print(string text) = 0;
};

