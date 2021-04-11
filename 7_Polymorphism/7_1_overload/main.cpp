#include "calc.h"
#include <iostream>

using namespace std;

int main()
{
    CCalc *pC1, *pC2;
    // overloadされた関数は引数の与え方などによって区別されている
    pC1 = new CCalc();      // default constructor
    pC2 = new CCalc(1, 2);  // constructor with arguments

    cout << 3 << " + " << 4 << " = " << pC1->add(3, 4) << endl;
    cout << pC2->getA() << " + " << pC2->getB() << " = " << pC2->add() << endl;

    delete pC1;
    delete pC2;
}

