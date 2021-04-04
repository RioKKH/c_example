#ifndef _TWOSTRINGS_HPP_
#define _TWOSTRINGS_HPP_

#include <iostream>
#include <string>

using namespace std;

class TwoStrings
{
private:
    // 1つ目の文字列
    string m_string1;

    // 2つ目のの文字列
    string m_string2;

public:
    // 1つ目の文字列を設定
    void setString1(string s);
    // 2つ目の文字列を設定
    void setString2(string s);

    // 1つ目の文字列を取得
    string getString1();
    // 2つ目のの文字列を取得
    string getString2();

    // 2つの文字列をつないだものを取得
    string getConnectedString();
    // getConnectedString()で得られる文字列の長さを取得
    int getConnectedLength();
};

#endif // _TWOSTRINGS_HPP_
    int getConnectedLength();

