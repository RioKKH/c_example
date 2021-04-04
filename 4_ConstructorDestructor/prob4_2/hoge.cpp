#include <iostream>
#include "hoge.hpp"

using namespace std;

Hoge::Hoge()
{
    cout << "Call constructor" << endl;
}

Hoge::~Hoge()
{
    cout << "Call destructor" << endl;
}

void Hoge::foo()
{
    cout << "fooメソッド" << endl;
}
