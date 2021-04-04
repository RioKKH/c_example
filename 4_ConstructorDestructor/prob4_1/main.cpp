#include <iostream>
#include "number.hpp"

using namespace std;

int main()
{
    Number* pN;
    pN = new Number();
    pN->setNumbers(1, 2);
    cout << pN->getAdd() << endl;
    delete pN;
    return 0;
}
