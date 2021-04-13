#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<string> v;
    list<string> l;
    v.push_back("HELLO");
    v.push_back("WORLD");
    l.push_back("hello");
    l.push_back("world");
    l.push_back("!");

    // vectorでのイテレータ
    vector<string>::iterator i1;
    for (i1 = v.begin(); i1 != v.end(); i1++) {
        cout << *i1 << endl;
    }

    // listでのイテレータ
    list<string>::iterator i2;
    i2 = l.begin();
    // listの要素の削除
    l.remove(*i2);      // 要素の削除(listにしか出来ない)
    for (i2 = l.begin(); i2 != l.end(); i2++) {
        cout << *i2 << endl;
    }
    // l.push_front()
    // l.push_back()
    // l.pop_front()
    // l.pop_back()
    // insert()
    // erase()
    // clear()
}
