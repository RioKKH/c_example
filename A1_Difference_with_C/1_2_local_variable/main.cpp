#include <iostream>

using namespace std;

// c++では関数のスコープ以外の場所でも変数を定義することが可能
int main()
{
    cout << "ABC" << endl;
    // 処理の途中で変数を宣言
    int i;
    for (i = 0; i < 10; ++i) {
        cout << ":" << i;
    }
    cout << endl;

    // 処理の途中で変数を宣言
    for (int j = 0; j < 10; ++j) {
        cout << ":" << j;
    }
    cout <<endl;

    return 0;
}
