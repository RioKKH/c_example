#include "sample.h"

int main()
{
    Sample *p1, *p2;
    p1 = new Sample(1); // constructor with arguments
    p2 = new Sample();  // default constructor --> cause error because of missing of declaration

    return 0;
}
