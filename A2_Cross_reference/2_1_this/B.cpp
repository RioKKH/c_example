#include "A.h"
#include "B.h"
#include <iostream>
// *.cppの中でA.h, B.hをどちらもincludeする

using namespace std;

B::B(A* pA)
{
    m_pA = pA;
}

void B::hoge()
{
    cout << "bar" << endl;
    m_pA->foo();
}
