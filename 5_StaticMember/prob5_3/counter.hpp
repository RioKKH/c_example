#ifndef _COUNTER_HPP_
#define _COUNTER_HPP_

class Counter
{
private:
    int m_count; // 回数
    static int m_totalCount; // 静的メンバ変数　トータル回数
public:
    Counter();
    ~Counter();
    void reset();
    void count();
    int getCount();
    static int getTotalCount();
};

#endif // _COUNTER_HPP_
