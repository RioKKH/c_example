#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

class Object {
private:
    static int m_objectNum;
public:
    Object();
    ~Object();
    static int getObjectNum();

};

#endif // _OBJECT_HPP_
