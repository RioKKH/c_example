#include "Sample.h"

CSample::CSample()
{
    m_str = "";
}

void CSample::setStr(const string str)
{
    m_str = str;
    // str = ""; 
    // コメントを取るとエラーになる。これはconstがついているstrを
    // メソッド内で変更しようとしたためである。
}

string CSample::getStr() const
{
    // m_str = "";
    // コメントを取るとエラーになる。これはconstがついているメンバ
    // 関数内でメンバ変数を変更しようとしたためである
    return m_str;
}
