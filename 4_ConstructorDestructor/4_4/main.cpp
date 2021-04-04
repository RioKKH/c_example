#include <iostream>
#include "car.hpp"

using namespace std;

int main()
{
    int *p = 0;
    p = new int[10]; // int型10古文の領域を動的確保
    for (int i = 0; i < 10; ++i) {
        p[i] = i;
        cout << p[i] << endl;
    }
    delete [] p; // 動的に確した領域を解放
    return 0;
}
