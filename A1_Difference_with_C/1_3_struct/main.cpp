#include <iostream>

using namespace std;

struct data
{
    int n;
    double d;
};

int main()
{
    data dt;
    dt.n = 100;
    dt.d = 12.34;
    cout << "dt.n = " << dt.n << endl;
    cout << "dt.d = " << dt.d << endl;

    return 0;
}

/**
  C言語で同じ処理を行う場合の構造体の宣言は
  typedef struct {
    int n;
    double d;
  } data;
  と書く必要がある

  もしくはmain()内で
  struct data dt;とするのでも大丈夫だったと思う。
*/
