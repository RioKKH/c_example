#include <iostream>
#include "Vector2D.h"

using namespace std;

// constructor
Vector2D::Vector2D()
{
    init();
}

// destructor
Vector2D::~Vector2D()
{
    cout << "destructor of vector2d" << endl;
}

// set the value
void Vector2D::seValue(int x, int y)
{
    m_x = x;
    m_y = y;
}

// get the value of X
int Vector2D::getX()
{
    return m_x;
}

// get the value of y
int Vector2D::getY()
{
    return m_y;
}

// initialize
void Vector2D::init()
{
    m_x = 0;
    m_y = 0;
}
