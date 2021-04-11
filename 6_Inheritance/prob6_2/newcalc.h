#ifndef _NEWCALC_H_
#define _NEWCALC_H_

#include "fundcalc.h"

class NewCalc : public FundCalc {
    public:
        // Make multiplication
        double mul();
        // Make division
        double div();
};

#endif

