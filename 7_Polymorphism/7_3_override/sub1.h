#ifndef _SUB1_H_
#define _SUB1_H_

#include "sup1.h"

// 親クラスを継承。子クラスにも全く同じ名前・引数のメソッドが存在する
class Sub1 : public Sup1 {
    public:
        // A function overridden
        // 子クラスのメソッドfunc()は親クラスのメソドをオーバーライドしている
        // 子クラスのメソッドが実行される
        void func();
};

#endif // _SUB1_H_

