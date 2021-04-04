#include <iostream>
#include "twostrings.hpp"

using namespace std;

int main()
{
    TwoStrings s;
    s.setString1("Hello");
    s.setString2("world");
    cout << "1つ目の文字列は" << s.getString1() << endl;
    cout << "2つ目の文字列は" << s.getString2() << endl;
    cout << "2つの文字列を合成したものは" << s.getConnectedString() << endl;
    cout << "合成した文字列の長さは" << s.getConnectedLength() << "文字" << endl;
    return 0;
}
