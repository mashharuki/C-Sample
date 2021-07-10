#include <iostream>
using namespace std;

/**
 * メイン関数
 */
int main() {
    int num = 0;
    // 参照の宣言
    int &newnum = num;

    num = 200;
    cout << "num = " << num << endl;
    cout << "newnum = " << newnum << endl;
    num = 400;
    cout << "num = " << num << endl;
    cout << "newnum = " << newnum << endl;

    return 0;
}
