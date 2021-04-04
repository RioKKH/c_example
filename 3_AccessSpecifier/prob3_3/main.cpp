#include <iostream>
#include "calculation.hpp"

using namespace std;

int main()
{
    Calculation c;
    c.setNumber1(8); // 1つ目の数をセット
    c.setNumber2(9); // 2つ目の数をセット
    // 2つの数の和を表示
    cout << c.getNumber1() << " + " << c.getNumber2() << " = " << c.add() << endl;
    // 2つの数のを表示
    cout << c.getNumber1() << " - " << c.getNumber2() << " = " << c.sub() << endl;

    return 0;
}
