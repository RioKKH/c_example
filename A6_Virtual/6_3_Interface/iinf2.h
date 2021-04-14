#ifndef _IINF2_H_
#define _IINF2_H_

// インターフェースクラス2
class IInf2 {
    public:
        // 純粋仮想関数のみからなるクラス
        // --> interface!
        virtual void func3() = 0;
        virtual void func4() = 0;
};

#endif // _IINF2_H_
