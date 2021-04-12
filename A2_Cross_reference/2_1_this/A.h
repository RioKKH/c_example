#ifndef _A_H_
#define _A_H_

// クラスBへの参照
class B;

class A {
    private:
        B* m_pB;
    public:
        // constructor
        A();
        void foo();
        void bar();
};

#endif // _A_H_
