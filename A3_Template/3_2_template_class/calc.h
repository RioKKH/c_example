#ifndef _CALC_H_
#define _CALC_H_

/**
  テンプレート宣言
  calc.hに対応するcalc.cppが存在しない。
  テンプレートクラスでは実装はヘッダファイルにすることが推奨されている
*/
template <typename T> class CCalc {
    // T -> 任意のデータ型、クラスに変更出来る
    private:
        T m_n1;
        T m_n2;

    public:
        // inline関数はヘッダーファイル内に処理を記述する
        // 下のようなセッター・ゲッターにconstと合わせて用いると
        // C++のパフォーマンスを向上させると言われている。
        inline void set(const T n1, const T n2)
        {
            m_n1 = n1;
            m_n2 = n2;
        } // 引数のセット

        inline T add() const {
            return m_n1 + m_n2;
        } // 計算結果
};

#endif // _CALC_H_
