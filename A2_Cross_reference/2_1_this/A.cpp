#include "A.h"
#include "B.h"
#include <iostream>
// *.cppの中でA.h, B.hをどちらもincludeする

using namespace std;

A::A()
{
    // B(A* pA) in B.h
    // Aクラス内でBクラスを生成する際に自分自身のポインタを渡している
    m_pB = new B(this);
}

void A::foo()
{
    cout << "foo" << endl;
}

void A::bar()
{
    m_pB->hoge();
}
