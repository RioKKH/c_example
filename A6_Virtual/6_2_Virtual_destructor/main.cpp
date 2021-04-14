#include <iostream>
#include "sup1.h"
#include "sup2.h"
#include "sub1.h"
#include "sub2.h"

using namespace std;

int main()
{
    // ソフトウェア設計論でやったメッセージパッシングだ！
    CSup1 *s1 = new CSub1();
    CSup2 *s2 = new CSub2();
    /**
      CSup1のコンストラクタ
      CSub1のコンストラクタ
      CSup2のコンストラクタ
      CSub2のコンストラクタ
    */

    s1->a();
    s2->b();
    /**
      a in CSup1
      b in CSup2
    */
    CSub1 *s3 = new CSub1();
    CSub2 *s4 = new CSub2();
    s3->a();
    s4->b();
    /**
      a in CSub1
      b in CSub2
    */

    delete s1;
    delete s2;
    /**
    CSup1のデストラクタ
    CSub2のデストラクタ
    CSup2のデストラクタ --> virtual付きの影響
    virtualをつけたメソッドは仮想関数となるため、親クラスから
    メンバ関数が呼ばれた場合には、子クラスの処理が実行される。
    これはデストラクタについても同様
    子クラスのデストラクタにメモリ解放と行った重要な処理がある場合、
    それが実行されずに致命的は不具合が発生する可能性がある。
    継承して利用される可能性のあるクラスのデストラクタは必ず仮想
    デストラクタにする
    */
    
    return 0;
}
