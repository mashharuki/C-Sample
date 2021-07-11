/**
 * 人を表すクラスを使ったサンプルプログラム
 */
#include <iostream>
#include <string.h>
using namespace std;

/**
 * 人を扱うクラス 
 */
class Person {
    public:
        // コンストラクタを用意する。
        Person();
        Person::Person(const char *str);
        Person::Person(const char *str, int yy, const char* pn);
        // コピーコンストラクタ
        Person(const Person &psn);
        // コンストラクタを削除する
        ~Person(){
            if(name != NULL) {
                // メモリ解放
                delete [] name;
            }
        }
        // 初期化する関数
        void init(const char *str, int yy, const char* pn);
        // 名前を設定する関数
        void SetName(const char *str);
        // 年齢を設定する関数
        void SetAge (const int yy) {
            age = yy;
        }
        // 電話番号を設定する関数
        void SetPhoneNum (const char *pn) {
            strcpy(phonenum, pn);
        }
        // 名前を取得する関数
        char *GetName() {
            return name;
        }
        // 年齢を取得する関数
        int GetAge() {
            return age;
        }
        // 電話番号を取得する関数
        char *GetPhoneNum() {
            return phonenum;
        }
    private:
        /* 名前 */
        char *name;
        /* 年齢 */
        int age;
        /* 電話番号 */
        char phonenum[15];
};

// 初期化する関数
void Person::init(const char *str, int yy, const char* pn) {
    name = new char[strlen(str) + 1];
    strcpy(name, str);
    age = yy;
    strcpy(phonenum, pn);
}

// コンストラクタ生成関数
Person::Person() {
    name = NULL;
    age = 0;
    phonenum[0] = '0';
}

Person::Person(const char *str) {
    // 初期化関数
    init(str, 0, "");
}

Person::Person(const char *str, int yy, const char* pn) {
    // 初期化関数
    init(str, yy, pn);
}

Person::Person(const Person &psn) {
    // 初期化関数
    init(psn.name, psn.age, psn.phonenum);
}

/**
 * 名前を設定する関数 
 */
void Person::SetName(const char *str) {
    if (name != NULL) {
        delete [] name;
    }
    name = new char[strlen(str) + 1];
    strcpy(name, str);
}

/**
 * メイン関数
 */
int main() {
    // コンストラクタを初期化する。
    Person Shiori1("しおりお嬢さん");
    // 値をセットする。
    Shiori1.SetAge(20);
    Shiori1.SetPhoneNum("222-3333-4444");
    // コンストラクタを生成する。
    Person Shiori2("しおり先生", 30, "001-1111-2222");
    // 3つ目のコンストラクタ
    Person Shiori3(Shiori2);
    // 値を設定する
    Shiori3.SetName("しおり兄貴");
    Shiori3.SetAge(24);
    // 配列を用意する。
    Person *p[] = {
        &Shiori1,
        &Shiori2,
        &Shiori3
    };

    for (int i = 0; i < 3; i++) {
        cout << "名前：" << p[i]->GetName() << "年齢：" << p[i]->GetAge() << "電話番号：" << p[i]->GetPhoneNum() << endl;
    }

    return 0;
}