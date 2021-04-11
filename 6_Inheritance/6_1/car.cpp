#include <iostream>
#include "car.h"

using namespace std;

// consturctor
CCar::CCar() : m_fuel(0), m_migration(0)
{
    cout << "CCar オブジェクト生成" << endl;
}

// destructor
CCar::~CCar()
{
    cout << "CCar オブジェクト破棄" << endl;
}

// 移動メソッド
void CCar::move()
{
    // 燃料があるなら移動
    if (m_fuel >= 0) {
        m_migration++; // 距離移動
        m_fuel--;      // 燃料消費
    }
    cout << "移動距離: " << m_migration << endl;
    cout << "燃料: " << m_fuel << endl;
}

// 燃料補給メソッド
void CCar::supply(int fuel)
{
    if (fuel > 0) {
        m_fuel += fuel; // 燃料補給
    }
    cout << "燃料" << m_fuel << endl;
}



