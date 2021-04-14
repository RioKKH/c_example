#ifndef _CROW_H_
#define _CROW_H_

#include "bird.h"

// カラスクラス
class CCrow : public CBird {
    public:
        // 鳴く関数(仮想関数)
        // CBirdのsing()をオーバーライドしている
        void sing() {
            cout << "カーカー" << endl;
        }
        // 飛ぶ関数
        // CBird()のfly()をオーバーライドしている
        void fly() {
            cout << "カラスが飛びます" << endl;
        }
};

#endif // _CROW_H_
