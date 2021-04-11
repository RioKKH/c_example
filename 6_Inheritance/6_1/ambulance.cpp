#include <iostream>
#include "ambulance.h"

using namespace std;

// constructor
CAmbulance::CAmbulance() : m_number(119)
{
    cout << "CAmbulanceオブジェクト生成" << endl;
}

// desturctor
CAmbulance::~CAmbulance()
{
    cout << "CAmbulanceオブジェクト破棄" << endl;
}

// 救急救命活動
void CAmbulance::savePeople()
{
    cout << "救急救命活動" << endl << "呼び出しは" << m_number << "番" << endl;
}
