#pragma once
#include <iostream>
#include "IPrintable.h"
using namespace std;

class BasicPrinter : public IPrintable {
public:
    void Print(string text) override {
        cout << text << endl;
    }
};

