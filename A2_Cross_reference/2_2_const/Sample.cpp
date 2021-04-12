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
    // メソッド内で変更しようとしてたためである。
}

string CSample::getStr() const
{
    // m_str = "";
    return m_str;
}
