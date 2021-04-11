#include "sup1.h"
#include "sub1.h"

int main()
{
    Sup1 *sp1;
    Sub1 *sb1;

    sp1 = new Sup1();
    sb1 = new Sub1();

    sp1->func();
    sb1->func();

    delete sp1;
    delete sb1;

    return 0;
}
