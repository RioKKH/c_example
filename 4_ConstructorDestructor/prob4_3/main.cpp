#include <iostream>

using namespace std;

int main()
{
    int* num = new int[4];
    for (int i = 0; i < 4; ++i) {
        num[i] = i;
    }

    for (int i = 0; i < 4; ++i) {
        cout << "num[" << i << "]=" << i << " ";
    }
    cout << endl;
    delete [] num;
    return 0;
}
