﻿#include <iostream>
#include "Array.h"
using namespace std;
int main()
{
    Array Numbers(5, 1, 2, 3, 4, 5);
    Numbers.setElementAt(0, 9);
    Numbers.print();

    Array Digits = Numbers;
    Digits.print();
    cout << "Min: " << Digits.min()<< endl;
    cout << "Max: " << Digits.max() << endl;
    Digits.sort();
    Digits.print();
}

