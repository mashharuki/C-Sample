/**
 * 平成30年度秋情報処理安全確保支援士試験コード
 */

#include <cstdio>
#include <iostream>

/**
 * メイン関数
 */
int main (int argc, char *argv[]) {
    // ポインタ変数を用意する。
    char *a, *x;
    // 省略
    // foo関数を呼び出す。
    foo(a, x);
    // 省略

    /**
     * foo関数
     */
    int foo(char *b, char *c) {
        // 100バイトのサイズでchar型用意
        char d[100];
        // 省略
        // コピーする
        strcpy(d, b);
        // dが0だった場合実行
        if(d[0] == 0) {
            err_out(c);
        }

        return 0;
    }

     /**
      * err_out関数
      */
     int err_out (char *errmsg) {
        // 100バイトのサイズでchar型用意
        char c1[100];
        // インクリメント用の変数
        int i = 0;
        // 省略
        // ***脆弱性あり***
        // \0(終端)まで繰り返してs1に格納する。
        while((s1[i++] = *errmsg++) != '\0');
        // 出力する。
        fprintf(stderr, "Error : %s \n", s1);
        // 省略
        return 0;
     }
}
