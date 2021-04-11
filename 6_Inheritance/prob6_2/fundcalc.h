#pragma once

class FundCalc {
protected:
    double m_number1; // 1つ目の数
    double m_number2; // 2つ目の数
public:
    // constructor
    FundCalc();
    // desturctor
    ~FundCalc();
    // Set 1st number
    void setNumber1(double number);
    // Set 2nd number
    void setNumber2(double number);
    // Get 1st number
    double getNumber1();
    // Get 2nd number
    double getNumber2();
    // Make addition
    double add();
    // Make subtraction
    double sub();
};


