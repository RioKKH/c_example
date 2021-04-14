#include <iostream>
#include <string>
#include "bird.h"
#include "chiken.h"
#include "crow.h"

using namespace std;

int main()
{
    CBird *b1, *b2;
    b1 = new CCrow();
    b2 = new CChicken();

    //- b1
    // w/ virtual --> サブクラスに実装されたメンバ関数が実行される
    b1->sing(); // カーカー
    // w/o virtual --> スーパークラスに実装されたメンバ関数が実行される
    b1->fly();  // 鳥が飛びます

    //- b2
    // w/ virtual --> サブクラスに実装されたメンバ関数が実行される
    b2->sing(); // コケコッコー w/ virtual
    // w/o virtual --> スーパークラスに実装されたメンバ関数が実行される
    b2->fly();  // 鳥が飛びます

    return 0;
}
