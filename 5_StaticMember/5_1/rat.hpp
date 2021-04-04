#ifndef _RAT_HPP_
#define _RAT_HPP_

class CRat {
public:
    // constructor
    CRat();
    // destructor
    ~CRat();
    // ネズミの数を出力する
    static void showNum();
    // ネズミが鳴く
    void squeak();

private:
    // ネズミの番号
    int m_id;
    // ネズミの数
    static int m_count;
};

#endif // _RAT_HPP_
