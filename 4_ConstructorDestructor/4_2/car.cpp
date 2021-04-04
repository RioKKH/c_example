#include <iostream>
#include "car.hpp"

using namespace std;

// コンストラクタ
CCar::CCar() : m_fuel(0), m_migration(0)
{
    cout << "CCar オブジェクト生成" << endl;
}

// デストラクタ
CCar::~CCar()
{
    cout << "CCar オブジェクト破棄" << endl;
}

void CCar::move()
{
    // 燃料があるのなら移動
    if (m_fuel >= 0) {
        m_migration++;  // 移動距離増加
        m_fuel--;       // 燃料消費
    }

    cout << "移動距離" << m_migration << endl;
    cout << "燃料" << m_fuel << endl;
}

// 燃料補給メソッド
void CCar::supply(int fuel)
{
    if (fuel > 0) {
        m_fuel += fuel;     // 燃料補給
    }
    cout << "燃料" << m_fuel << endl;
}


