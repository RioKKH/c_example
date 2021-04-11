#ifndef _AMBULANCE_H_
#define _AMBULANCE_H_

#include "car.h"

class CAmbulance : public CCar
{
public:
    // constructor
    CAmbulance();
    // destructor
    virtual ~CAmbulance();
    // 救急救命活動
    void savePeople();

private:
    int m_number;
};

#endif // _AMBULANCE_H_
