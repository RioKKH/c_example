#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

// 二次元ベクトルクラス
class Vector2D {
protected:
    int m_x;
    int m_y;
public:
    // constructor
    Vector2D();
    // destructtor
    virtual ~Vector2D();
    // Set the values
    void seValue(int x, int y);
    // get the value of x
    int getX();
    // get the value of y
    int getY();
protected:
    // initialize
    void init();
};

#endif //_VECTOR2D_H_
