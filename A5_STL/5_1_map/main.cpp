#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int>score;      // mapのデータ構造を用意する
    string names[] = {"Tom", "Bob", "Mike"};
    score[names[0]] = 100;      // キーと値の関連付け1 Tom : 100
    score[names[1]] = 80;       // キーと値の関連付け2 Bob :  80
    score[names[2]] = 120;      // キーと値の関連付け3 Mike: 120

    int i;
    for (i = 0; i < 3; i++) {
        cout << names[i] << ":" << score[names[i]] << endl;
    }
    cout << score.size() << endl;
    map<string, int>::iterator itr;
    itr = score.find("Tom");    // Iteratorをどのように使うのかが不明
    
    return 0;
    // score.clear()
    // score.empty()
    // score.erase()
    // score.size()
    // score.find()
}

