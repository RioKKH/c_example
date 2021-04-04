#ifndef _NUMBER_HPP_
#define _NUMBER_HPP_

class Number {
private:
    // メンバ変数
    int a;
    int b;
public:
    Number(); // constructor
    ~Number(); // destructor
    // 2つの数値を設定
    void setNumbers(int n1, int n2);
    // 2つの数の和を取得
    int getAdd();
};

#endif // _NUMBER_HPP_

