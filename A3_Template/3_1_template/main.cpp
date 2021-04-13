#include <iostream>
#include <string>

using namespace std;

// template function
template <typename T> T add(T x, T y)
{
    return x + y;
}

int main()
{
    cout << add<int>(4, 3) << endl; // 数値でadd関数を利用
    cout << add<string>("ABC", "DEF") << endl; // stringとaddを利用
    cout << add(1, 2) << endl;   // 両方ともint型の場合には型指定が不要
    // cout << add("abc", "def") // string型の場合には型指定が必要
    // string型なのかchar*なのか、はっきりしないため。
    // cout << add(1, 2.3) << endl; // 型が不一致の場合には使えない
    return 0;
}
