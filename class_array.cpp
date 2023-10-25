#include <iostream>
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

    Digits.setSize(9);
    Digits.setElementAt(5, 81);
    Digits.print();
    Numbers.print();

    Array list;

    list = Numbers;
    list.print();


    
}


