#ifndef _CALC_H_
#define _CALC_H_

class CCalc {
    private:
        int m_a, m_b;
    public:
        // default constructor
        // 引数の無いconstructorのことをdefault constructorという
        // 引数付きのconstructorを定義した場合にはdefault constructorの定義は
        // を省略することは出来ない
        CCalc();
        // constructor with arguments
        // コンストラクタ・メンバ変数で、引数、もしくは戻り値が異なっていれば、
        // 同じ名前がついた複数のメソッドを定義することが出来る。
        // これをoverloadという
        CCalc(int a, int b);
        // addition
        int add();
        // addition with arguments
        int add(int a, int b);
        // set the values
        void setValue(int a, int b);
        // get the value A
        int getA();
        // get the value B
        int getB();
};

#endif // _CALC_H_
