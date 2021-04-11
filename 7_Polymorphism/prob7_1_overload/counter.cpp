#include <iostream>
#include "counter.h"

using namespace std;

// constructor
Counter::Counter() : m_count(0)
{
    cout << "Constructor" << endl;
}

Counter::~Counter()
{
    cout << "Destructor" << endl;
}

// Reset the number of counter
void Counter::reset()
{
    m_count = 0;
}

// Get the number of counter
int Counter::getCount()
{
    return m_count;
}

// Count
void Counter::count()
{
    ++m_count;
}

// Count with argument
void Counter::count(int count)
{
    for (int i = 0; i < count; ++i) {
        ++m_count;
    }
}

