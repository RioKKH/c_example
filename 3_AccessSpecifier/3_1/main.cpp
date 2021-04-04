#include <iostream>
#include "Sample.hpp"

using namespace std;

int main()
{
    Sample s;
    s.a = 1;
    // s.b = 2; // error
    s.func1();
    // s.func2(); // error
}
