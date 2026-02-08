#pragma once
#include <string>
using namespace std;

class IFaxable {
public:
    virtual void Fax(string text) = 0;
};

