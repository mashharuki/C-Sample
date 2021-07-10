/**
 * 成績を表示するサンプルプログラム
 */
 
#include <iostream>
#include <string.h>
using namespace std;

// 列挙型変数
enum Subjects{
    Math,
    English,
    Science
};

/**
 * 生徒クラス 
 */
class Student {
    public:
        // IDの値を設定する関数
        void SetID(int num) {
            id = num;
        }
        // 名前を値を設定する関数
        void SetName(char *str) {
            strcpy (name, str);
        }
        // IDを値を取得する関数
        int GetID() {
            return id;
        }
        // 名前の値を取得する関数
        char *GetName() const {
            return (char *) name;
        }
    private:
        /* ID */
        int id;
        /* 名前 */
        char name[30];
};

/**
 * テストクラス
 */
class Exam {
    public:
        // 情報をセットする関数
        void SetInfo(int id, char *name, Subjects s, int num);
        // 点数を取得する関数
        int GetPoint() const {
            return point;
        }
        // 結果を取得する関数
        void GetResult(char *buf) const;
        // Studentクラス型の変数
        Student stduent;
    private:
        /* 科目 */
        Subjects subject;
        /* 点数 */
        int point;
};

/**
 * 結果を取得する関数 
 */
void Exam::GetResult(char *buf) const {
    // 科目を定義する。
    char *subname[] = { "数学", "英語", "理科" };
    sprintf(buf, "%s : %d点", subname[subject], point);
}

/**
 * 結果を出力する関数 
 */
void PrintResult(const Exam &Exam) {
    cout << Exam.stduent.GetName() << endl;
    char buf[30];
    Exam.GetResult(buf);
    cout << buf << endl;
}

/**
 * 平均値を求める関数
 */
double GetAvg(const Exam *Exam, int num) {
    double sum = 0;
    // 合計点を求める。
    for (int i = 0; i < num; i++) {
        sum += Exam[i].GetPoint();
    }
    return sum / num;
}

/**
 * メイン関数
 */
int main() {
    // Examクラスの配列を生成
    Exam Exam[3];
    // データを設定する。
    Exam[0].SetInfo(1, " しおり ", Math, 60);
    Exam[1].SetInfo(1, " しおり ", English, 75);
    Exam[2].SetInfo(1, " しおり ", Science, 88);
    // 結果を出力
    PrintResult(Exam[0]);
    PrintResult(Exam[1]);
    PrintResult(Exam[2]);
    cout << endl;
    // 結果を出力する。
    cout << "平均" << GetAvg(Exam, 3) << "点" << endl;
    return 0;
}