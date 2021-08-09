/**
 * バッファオーバーフロー攻撃を体感するためのサンプルコード 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ファイルパスを指定する。
#define FILEPATH "msg_file.txt"

// メイン関数の呼び出し
int main();
// 各種関数の宣言
void vuln(const char* line);
void stack_dump(void* ptr, int counts);
void hello();
 
/**
 * メイン関数 
 */
int main(){
    // ファイルの内容を格納する変数を用意する。
    char linebuf[1024];
    FILE *fp;
    long mark1 = 0x11111111;
    memset(linebuf, 0, sizeof(linebuf));

    fp = fopen(FILEPATH, "r");
    // fpに格納する。
    fgets(linebuf, sizeof(linebuf)-1, fp);
    fclose(fp);
    // vuln関数の呼び出し
    vuln(linebuf);

    printf("------------- end of main() -------------\n");
}

/**
 * ファイルを読み込み、その内容を出力するための関数
 */
void vuln(const char* line){
    char msg[20];
    long mark2 = 0x22222222;
    memset(msg, 0, sizeof(msg));
    // lineの情報をmsgにコピーする。
    strcpy(msg, line);
    // スタック領域に格納する。
    stack_dump(&mark2, 13);
    printf("INPUT[%s]\n", msg);
}
 
/**
 * 与えられてたアドレスからcounts × 4 バイト分のデータを見やすいダンプ形式で表示するための関数 
 */
void stack_dump(void* ptr, int counts){
    // 各種変数を用意する。
    int i;
    unsigned long *ulong_ptr = (unsigned long *)ptr;
    unsigned char uchar_buf[4];

    printf("-----------------------------------------\n");
    printf(" address | long var | +0 +1 +2 +3 | 0123\n");
    printf("-----------------------------------------\n");
    // 出力する。
    for(i=0; i<counts; i++) {
        printf(" %08x| %08x", &ulong_ptr[i], ulong_ptr[i]);
        memcpy(uchar_buf, &ulong_ptr[i], sizeof(uchar_buf));
        printf(" | %02x %02x %02x %02x",
            uchar_buf[0], uchar_buf[1], uchar_buf[2], uchar_buf[3]);
            if(uchar_buf[0]<32 || uchar_buf[0]>126) uchar_buf[0] = '.';
            if(uchar_buf[1]<32 || uchar_buf[1]>126) uchar_buf[1] = '.';
            if(uchar_buf[2]<32 || uchar_buf[2]>126) uchar_buf[2] = '.';
            if(uchar_buf[3]<32 || uchar_buf[3]>126) uchar_buf[3] = '.';
        printf(" | %c%c%c%c\n",uchar_buf[0], uchar_buf[1], uchar_buf[2], uchar_buf[3]);
    }
    printf("-----------------------------------------\n");
}
 
/**
 * hello関数(どこからもよび出されていない関数)
 */
void hello(){
    printf("+----------+\n");
    printf("| HELLO! |\n");
    printf("+----------+\n");
    exit(0);
}