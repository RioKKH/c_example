#ifndef _BIRD_H_
#define _BIRD_H_

#include <iostream>
#include <string>

using namespace std;

class CBird {
    public:
        // 鳴く関数（仮想関数）
        // 実装が省略されている仮想関数
        // このような仮想関数のことを純粋仮想関数という
        // 実装はこのクラスを継承した子クラスにされる事が前提となっている
        // このような完全仮想関数を１つでも持つクラスのことを
        // 抽象クラスという
        virtual void sing() = 0;
        // 飛ぶ関数
        void fly() {
            cout << "鳥が飛びます" << endl;
        }
};

#endif // _BIRD_H_
