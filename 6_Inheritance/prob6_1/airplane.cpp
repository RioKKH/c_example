#include <iostream>
#include "airplane.h"

using namespace std;

Airplane::Airplane()
{
    cout << "constructor of Airplane" << endl;
}

Airplane::~Airplane()
{
    cout << "destructor of Airplance" << endl;
}

void Airplane::fly()
{
    cout << "飛行する" << endl;
}
