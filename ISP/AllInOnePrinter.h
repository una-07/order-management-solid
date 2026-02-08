#pragma once
#include <iostream>
#include "IPrintable.h"
#include "IScannable.h"
#include "IFaxable.h"
using namespace std;

class AllInOnePrinter : public IPrintable, public IScannable, public IFaxable {
public:
    void Print(string text) override { cout << text << endl; }
    void Scan(string text) override { cout << text << endl; }
    void Fax(string text) override { cout << text << endl; }
};

