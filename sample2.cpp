#include <iostream>
using namespace std;

/**
 * 値を変える関数 
 */
void ChangeValue(double &a) {
    a = 200;
}

/**
 * メイン関数
 */
int main() {
    double numl = 100;
    cout << "numl = " << numl << endl;
    ChangeValue(numl);
    cout << "numl = " << numl << endl;
    return 0;
}