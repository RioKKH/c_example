#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack<int> stk;     // スタックのデータ構造を宣言
    queue<int> que;     // キューのデータ構造を宣言
    int data[] = {1, 2, 3}; // 登録するデータ
    int i;

    // データの登録
    for (i = 0; i < 3; i++) {
        stk.push(data[i]);
        que.push(data[i]);
    }
    // データの出力(stack)
    cout << "stack : ";                 // LIFO
    while (!stk.empty()) {
        // topで要素を取得し、popでその要素をstkから取り除く
        // (２段階の作業が必要)
        cout << stk.top() << " ";       // 取得
        stk.pop();                      // 除去
    }
    cout << endl;
    // データの出力(queue)
    cout << "queue : ";                 // FIFO
    while (!que.empty()) {
        // frontで要素を取得し、popでその要素をqueから取り除く
        // (2段階の作業が必要)
        cout << que.front() << " ";     // 取得
        que.pop();                      // 除去
    }
    cout << endl;
    return 0;
}
