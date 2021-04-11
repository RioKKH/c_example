#include "car.h"
#include "ambulance.h"

int main()
{
    CCar c;
    CAmbulance a;

    c.supply(10); // 燃料補給
    c.move();
    c.move();

    a.supply(10);
    a.move();
    a.savePeople();

    return 0;
}



