#include <iostream>
#include "iinf1.h"
#include "iinf2.h"
#include "sample.h"

// IInf1のみが使える関数
void foo(IInf1*);
// IInf2のみが使える関数
void bar(IInf2*);

int main()
{
    CSample *s = new CSample();
    // それぞれのインターフェースでキャストすることで、それぞれの
    // 純粋仮想関数が記述されている関数しか利用できなくなる
    // インターフェースを利用することのメリットは、このようにポインタ
    // を渡す相手のクラスに対して、機能を制限したい場合。
    foo((IInf1*)s);
    bar((IInf2*)s);
    return 0;
}

// IInf1のみが使える関数
void foo(IInf1* p)
{
    p->func1();
    p->func2();
    // p->func3();
    // p->func4();
}

// IInf2のみが使える関数
void bar(IInf2* p)
{
    // p->func1();
    // p->func2();
    p->func3();
    p->func4();
}
