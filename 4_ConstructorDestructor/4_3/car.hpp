#ifndef _CAR_HPP_
#define _CAR_HPP_

// 自動車クラス
class CCar {
public:
    // コンストラクタ
    CCar();
    // デストラクタ
    ~CCar();
    // 移動メソッド
    void move();
    // 燃料補給メソッド
    void supply(int fuel);

private:
    int m_fuel;         // 燃料
    int m_migration;    // 移動距離
};

#endif // _CAR_HPP_
