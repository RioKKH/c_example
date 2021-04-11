#include <iostream>
#include "vector.h"

using namespace std;

// constructor
Vector::Vector() : m_x(0), m_y(0)
{
    cout << "constructor" << endl;
}

Vector::Vector(double x, double y) : m_x(x), m_y(y)
{
    cout << "constructor with arguments" << endl;
}

// destructor
Vector::~Vector()
{
    cout << "destructor" << endl;
}

// Set the coordinate values
void Vector::set(double x, double y)
{
    m_x = x;
    m_y = y;
}

// Get x value
double Vector::getX()
{
    return m_x;
}

// Get y value
double Vector::getY()
{
    return m_y;
}
