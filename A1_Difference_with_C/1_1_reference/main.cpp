#include <iostream>

using namespace std;

void ref(int&);
void print(int);

int main()
{
    //整数の値を代入
    int n = 5;
    print(n);
    // 参照渡し
    // 変数を引数として渡すと、そのアドレスへの参照が渡される
    // これによってref()内では、参照渡しされた変数の値を変更することが可能
    // ポインタ渡しの場合には、呼び出す際にも変数のアドレス(ポインタ)を
    // 与える必要があるが、参照渡しの場合には、変数をそのまま渡せば良いという
    // 点で異なっている
    ref(n);
    print(n);

    return 0;
}

void ref(int& n)
{
    n = 1;
}

void print(int n)
{
    cout << "n = " << n << endl;
}
