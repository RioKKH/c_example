#include <stdio.h>
int main()
{
    typedef int seisu; 
    typedef float syosu;
    typedef unsigned long long int u64;
    u64 x; // 64ビットの符号なし整数型
    
    // こちらの書き方の方が主流
    typedef struct GROUP {
        char name[16];
        int no;
    } GROUP;
    GROUP g = { "AKB", 48 }; // structを省略できる

    // あんまり使われない書き方
    struct GROUP2 {
        char name[16];
        int no;
    };
    typedef struct GROUP2 GROUP2;

    typedef char str[16];
    str name = "AKB";

    return 0;
}
