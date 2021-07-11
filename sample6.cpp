#include <iostream>
#include <string.h>
using namespace std;

class DrinkBox {
    public:
        // コンストラクター
        DrinkBox();
        DrinkBox(char *str, int n1, int n2) {
            name = new char[strlen(str) + 1];
            strcpy (name, str);
            price = n1;
            count = n2;
        }
        // デストラクター
        ~DrinkBox() {
            // メモリ解放
            delete [] name;
        }

        /*
         * 合計金額の計算する関数
         */
        int GetTotalPrice() {
            return count * price;
        }

        /*
         * タイトルを表示する関数
         */
        void PrintTitle() {
            cout << "商品名 ¥t¥t 単価 ¥t 数量 ¥t 金額" << endl;
        }

        /*
         * 商品データの表示する関数
         */
        void PrintData() {
            cout << name << "¥t" << price << "¥t" << count << "¥t" << GetTotalPrice() << endl;
        }

        /** 商品名 */
        char *name;
        /** 単価 */
        int price;
        /** 数量 */
        int count;
};

/**
 * DrinkBoxを継承したアルコールクラス
 */
class AlcholBox : public DrinkBox {
    public:
        // コンストラクター
        AlcholBox(char *str, int n1, int n2, float f) {
            name = new char[strlen(str) + 1];
            strcpy(name, str);
            price = n1;
            price = n2;
            alcper = f;
        }

        /*
         * タイトルを表示する関数
         */
        void PrintTitle() {
            cout << "商品名 (度数[%]) ¥t 単価 ¥t 数量 ¥t 金額" << endl;
        }

        /*
         * 商品データの表示する関数
         */
        void PrintData() {
            cout << name << "(" << alcper << ")" << "¥t" << price << "¥t" << count << "¥t" << GetTotalPrice() << endl;
        }
    private:
        /** アルコールの度数 */
        float alcper;
};

/**
 * メイン関数
 */ 
int main() {
    // コンストラクタを作成
    DrinkBox cofee("コーヒー", 200, 3);
    DrinkBox oolongtea("ウーロン茶", 150, 2);
    AlcholBox wine("ワイン", 300, 2, 15.0);
    // 関数を呼び出す。
    cofee.PrintTitle();
    cofee.PrintData();
    oolongtea.PrintData();
    wine.PrintTitle();
    wine.PrintData();

    int sum = cofee.GetTotalPrice() + oolongtea.GetTotalPrice() + wine.GetTotalPrice();
    cout << "¥n*** 合計金額" << sum << "円 ***" << endl; 
    return 0;
}