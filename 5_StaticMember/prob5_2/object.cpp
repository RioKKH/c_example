#include "object.hpp"

// static なメンバ変数をcppの中に置いておくことが大事
int Object::m_objectNum = 0;

Object::Object()
{
    // オブジェクトの数をincrementする
    m_objectNum++;
}

Object::~Object()
{
    // オブジェクトの数をdecrementする
    m_objectNum--;
}

int Object::getObjectNum()
{
    return m_objectNum;
}
