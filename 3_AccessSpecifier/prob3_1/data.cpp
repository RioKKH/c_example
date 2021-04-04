#include "data.hpp"

void CData::init()
{
    number = 0;
    comment = "";
}

void CData::setNumber(int num)
{
    number = num;
}

void CData::setComment(string s)
{
    comment.append(s);
}

int CData::getNumber()
{
    return number;
}

string CData::getComment()
{
    return comment;
}
