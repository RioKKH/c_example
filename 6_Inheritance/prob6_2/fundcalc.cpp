#include <iostream>
#include "fundcalc.h"

using namespace std;

FundCalc::FundCalc() : m_number1(0), m_number2(0)
{
    cout << "constructor of FuncCalc" << endl;
}

FundCalc::~FundCalc()
{
    cout << "destructor of FundCalc" << endl;
}

void FundCalc::setNumber1(double number)
{
    m_number1 = number;
}

void FundCalc::setNumber2(double number)
{
    m_number2 = number;
}

double FundCalc::getNumber1()
{
    return m_number1;
}

double FundCalc::getNumber2()
{
    return m_number2;
}

double FundCalc::add()
{
    return m_number1 + m_number2;
}

double FundCalc::sub()
{
    return m_number1 - m_number2;
}
