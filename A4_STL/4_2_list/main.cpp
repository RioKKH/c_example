#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> li;
    li.push_back(1);    // 後ろにデータを挿入 1
    li.push_back(2);    // 後ろにデータを挿入 1 2
    li.push_front(3);    // 前にデータを挿入  3 1 2

    // listはvectorのよなインデックスをもちいた要素へのアクセスが出来ない
    // その代わりにイテレータを用いてアクセスする
    // イテレータは要素にアクセスするための一種のポインタである。
    list<int>::iterator itr;
    // データの挿入
    itr = li.begin();   // イテレータを先頭に設定 この時点で>3 1 2
    itr++;              // 1つ移動する 3 >1 2
    li.insert(itr, 4);  // iteratorの次に値の挿入 3 >1 4 2
    // データの表示
    for (itr = li.begin(); itr != li.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}

