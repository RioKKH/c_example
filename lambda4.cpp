#include <iostream>
#include <string>

/**
 * リファレンスキャプチャーは変数をリファレンスによってキャプチャ−する
 */
int main()
{
    // リファレンスキャプチャーした変数をラムダ式の中で変更すると、
    // 元の変数が変更される
    int x = 0;
    auto f = [&]{ return x; };

    f(); // x == 1;
    f(); // x == 2;
    f(); // x == 3;
}