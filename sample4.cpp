/**
 * コピーコンストラクターを使ったプログラム 
 */
#include <iostream>
#include <string.h>
using namespace std;

/**
 * Personクラス 
 */
class Person {
    public:
        Person(){
            name = new char[50];
        }
        // コピーコンストラクターの宣言
        Person (const Person &psn); 
        // 削除する
        ~Person() {
            delete [] name;
        }
        // 名前を設定する関数
        void SetName(char *newname) {
            strcpy(name, newname);
        }
        // 名前を取得する関数
        void GetName(char *namebuf) {
            strcpy(namebuf, name);
        }
    private:
        char *name;
};

/**
 * コピーコンストラクターの定義
 */ 
Person::Person(const Person &psn) {
    name = new char[strlen(psn.name) + 1];
    strcpy(name, psn.name);
}

/**
 * メイン関数 
 */
int main () {
    // Person型のインスタンスを生成する
    Person *psn1 = new Person;
    // 名前を設定する
    psn1->SetName("Shiori");
    Person *psn2 = new Person(*psn1);
    char name[50];
    psn2->GetName(name);
    cout << name << endl;
    // コンストラクタを消去する
    delete psn1;
    delete psn2;
    return 0;
}