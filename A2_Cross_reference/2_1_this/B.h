#ifndef _B_H_
#define _B_H_

// クラスAへの参照
class A;

class B {
    private:
        A* m_pA;
    public:
        B(A* pA);
        void hoge();
};

#endif // _B_H_
