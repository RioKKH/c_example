#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
    // make counter object
    Counter *pC = new Counter();

    pC->count();
    pC->count();
    cout << "回数:" << pC->getCount() << "回" << endl;
    pC->count(4);
    cout << "回数:" << pC->getCount() << "回" << endl;
    // Reset the counter
    pC->reset();
    cout << "回数:" << pC->getCount() << "回" << endl;
    // delete counter object
    delete pC;
    return 0;
}
