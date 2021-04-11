#ifndef _COUNTER_H_
#define _COUNTER_H_

// counter class
class Counter {
    private:
        // count
        int m_count;

    public:
        // constructor
        Counter();
        // destructor
        ~Counter();

        // Reset the counter
        void reset();

        // get count number
        int getCount();

        // Count
        void count();

        // count with argument
        // overload of the method
        void count(int count);
};

#endif // _COUNTER_H_
