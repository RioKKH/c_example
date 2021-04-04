#ifndef _CDATA_HPP_
#define _CDATA_HPP_

#include <iostream>
#include <string>

using namespace std;

class CData {
private:
    // メンバ変数 number
    int number;
    // メンバ面数 comment
    string comment;
public:
    // 初期化
    void init();
    void setNumber(int num);
    void setComment(string s);
    int getNumber();
    string getComment();
};

#endif // _CDATA_HPP_
