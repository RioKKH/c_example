#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <iostream>
#include <string>

using namespace std;

class CSample {
    private:
        string m_str;
    public:
        CSample();
        void setStr(const string str);  // 引数をconstにした
        string getStr() const;          // メンバ関数のconst
    public:
        static const int m_cst = 100;   // 定数
        // 通常のメンバ変数と違い、ヘッダファイル内で定義出来る
        // ただし、この場合、戦闘にconstをつける必要がある

        // staticを使うのは、クラスの全てのオブジェクトが1つの
        // 変数を共有したい時。グローバル変数を使うことも出来るが、
        // それはオブジェクト試行プログラミングに反する。
        // このようなときに静的メンバ変数を用いる。静的メンバ変数は
        // 全てのオブジェクトが共有するクラス内グローバル変数と呼べる。
};

#endif // _SAMPLE_H_
