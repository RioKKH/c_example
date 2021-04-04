#include <iostream>
#include "counter.hpp"

using namespace std;

int main()
{
    Counter c1, c2;
    c1.count();
    c2.count();
    c2.count();
    c2.reset();
    c1.count();
    c1.count();
    c2.count();
    cout << "c1 のカウント数" << c1.getCount() << endl;
    cout << "c2 のカウント数" << c2.getCount() << endl;
    cout << "トータルのカウント数" << Counter::getTotalCount() << endl;
    // cout << "トータルのカウント数" << c1.getCount() + c2.getCount() << endl;
    return 0;
}


