#include <iostream>
#include "rat.hpp"

using namespace std;

int CRat::m_count = 0;

// コンストラクタ
CRat::CRat() : m_id(0)
{
    m_id = m_count;     // ネズミの数をIDとする
    m_count++;          // ネズミの数を1つ増やす
}

// デストラクタ
CRat::~CRat()
{
    cout << "ネズミ:" << m_id << "消去" << endl;
    m_count--; // ネズミの数を1つ減らす
}

void CRat::showNum() // 静的メンバメソッド
{
    cout << "現在のネズミの数は" << m_count << endl;
}

void CRat::squeak()
{
    cout << m_id << ":" << "チューチュー" << endl;
}
