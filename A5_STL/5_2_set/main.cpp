#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<string> names;  // setのデータ構造を用意する
    // 値を代入する
    names.insert("Tom");
    names.insert("Mike");
    names.insert("Mike");   // 名前をわざと重複させる
    names.insert("Bob");

    // 登録されている全データを表示する
    // 重複して登録したMikeが１つしか無いことを確認する
    set<string>::iterator itr;  // イテレータを用意する
    for (itr = names.begin(); itr != names.end(); itr++) {
        cout << *itr << endl;
    }
    // Bot, Steveがデータ内に存在するかを調べる
    string n[] = {"Bob", "Steve"};
    int i;
    for (i = 0; i < 2; i++) {
        itr = names.find(n[i]);
        // 存在しない場合:set classのend()メソッドが戻り値になる
        if (itr == names.end()) {
            // データがset内に存在しない
            cout << n[i] << "is not in a set." << endl;
        } else {
            // データがset内に存在する
            cout << n[i] << " is in a set." << endl;
        }
    }
    return 0;
    // clear()
    // empty()
    // erase()
    // size()
}

