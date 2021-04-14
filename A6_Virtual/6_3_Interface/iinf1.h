#ifndef _IINF1_H_
#define _IINF1_H_

// インターフェースクラス1
class IInf1 {
    public:
        // 純粋仮想関数のみからなるクラス
        // --> interface!
        virtual void func1() = 0;
        virtual void func2() = 0;
};

#endif // _IINF1_H_
