#include "calc.h"
#include <iostream>

// default constructor
CCalc::CCalc() : m_a(0), m_b(0)
{
    std::cout << "Default constructor" << std::endl; 
}

// constructor with arguments
CCalc::CCalc(int a, int b) : m_a(a), m_b(b)
{
    std::cout << "Constructor with arguments" << std::endl; 
}

// Addition
int CCalc::add()
{
    return m_a + m_b;
}

// Addition with arguments
int CCalc::add(int a, int b)
{
    return a + b;
}

// Set the values
void CCalc::setValue(int a, int b)
{
    m_a = a;
    m_b = b;
}

// Get the value
int CCalc::getA()
{
    return m_a;
}

// Get the value
int CCalc::getB()
{
    return m_b;
}

