#include <iostream>
#include <vector>

/**
 * リンゴクラス 
 */
class Ringo {
    public:
        // 列挙型変数を用意する。
        enum color_index{
            color_red,
            color_green,
            color_yellow
        };
        /** 色 */
        color_index color;
        /** 重さ */
        double weight;
        /** 品種 */
        std::string kind;
        
        /**
         * コンストラクター 
         */
        Ringo () {
            color = color_red;
            weight = 320.0;
            kind = "ふじ";
        }

        Ringo (const enum color_index &c, const double w, const char *k) {
            color = c;
            weight = w;
            kind = k;
        }

        /**
         * 色の名前を取得する関数
         */
        const char *GetColorName() {
            static const char *color_name[] = {"赤", "青", "緑"};
            return color_name[color];
        }

        /**
         * データを出力する関数 
         */
        void PrintData() {
            printf("色 =%s 重さ =%5.1fg 品種 =%s¥n", GetColorName(), weight, kind.c_str());
        }
};

/**
 * リンゴクラス 
 */
class RingoBox {
    public:
        // コンストラクター
        RingoBox() {
            Empty();
        }

        /**
         * 追加関数
         */
        bool Add(Ringo &r);

        /**
         * 削除関数
         */
        bool Del(int index);

        /**
         * 空白にする関数
         */
        void Empty(){
            ringo.clear();
        }

        /**
         * 合計個数を算出する関数
         */
        int GetTotalNum() {
            return (int) ringo.size();
        }

        /**
         * 合計重量を算出する関数
         */
        double GetTotalWeight();

        /**
         * データを全て表示する関数
         */
        void PrintData();

    private:
        /** Ringo型の変数 */
        std::vector<Ringo> ringo;
};

/**
 * Add関数のオーバーロード
 */
bool RingoBox::Add (Ringo &r) {
    if (ringo.size() > 40) return false;
    ringo.push_back(r);
    return true;
}

/**
 * Del関数のオーバーロード
 */
bool RingoBox::Del (int index) {
    if (index < 1 || index > (int)ringo.size()) return false;
    ringo.erase(ringo.begin() + index - 1);
    return true;
}

/**
 * GetTotalWeight関数のオーバーロード
 */
double RingoBox::GetTotalWeight () {
    double w = 0;
    for (std::vector<Ringo>::iterator i = ringo.begin(); i != ringo.end(); i++) {
        w += (*i).weight;
    }
    return w;
}

/**
 * PrintData関数のオーバーロード
 */
void RingoBox::PrintData () {
    int n = GetTotalNum();

    for (int i=0; i < n; i++) {
        ringo[i].PrintData();
    }
    printf("%d個のりんごがあります。¥n", n);
    printf("総重量 %5.1fg¥n", GetTotalWeight());
}

/**
 * メイン関数 
 */
int main () {
    // 総数を宣言する。
    static const char init_num= 4;
    // Ringo型のコンストラクターを生成する。
    Ringo myRingo[] = {
        Ringo(Ringo::color_red, 316.2, "ふじ"),
        Ringo(Ringo::color_green, 352.1, "王林"),
        Ringo(Ringo::color_red, 341.8, "つがる"),
        Ringo(Ringo::color_yellow, 320.7, "ゴールデンデリシャス")
    };
    // RingoBos型のインスタンスを生成
    RingoBox myRingoBox;
    // 箱に全て入れる
    for (int i=0; i < init_num; i++) {
        bool ret = myRingoBox.Add(myRingo[i]);
        if (ret) {
            std::cout << "1個追加" << std::endl;
        }
    }

    // 2番目のものを箱から取り出す。
    bool ret = myRingoBox.Del(2);
    if (ret) {
            std::cout << "1個削除" << std::endl;
        }

    // データを全て表示する。
    myRingoBox.PrintData();

    return 0;
}