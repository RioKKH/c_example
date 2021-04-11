#include <iostream>
#include "Position2D.h"

using namespace std;

int main()
{
    Position2D p;
    p.seValue(1, 1);
    p.move(2, 3);
    cout << "p:(" << p.getX() << "," << p.getY() << ")" << endl;
    p.resetPosition();
    cout << "p:(" << p.getX() << "," << p.getY() << ")" << endl;

    return 0;
}

