/**
 * 平成30年度情報処理安全確保支援士試験コード
 */

#include <cstdio>
#include <iostream>

// 構造体の宣言
struct Note {
    // 名前
    char *name;
    // メッセージ
    char *msg;
};

/**
 * NoteManagerクラス
 */
class NoteManager{
    // Note型の変数
    Note *m_note;

    public:
        // 初期化関数
        NoteManager() {
            m_note = NULL;
        }

        // ノート作成関数
        void CreateNote() {
            if (m_note = new Note()) {
                // 値を初期化する。
                m_note -> name = NULL;
                m_note -> msg = NULL;
            }
        }

        // 名前を登録する関数
        void RegisterName() {
            // ノート生成済みかつ名前用のアドレス領域が確保されていない場合に実行
            if (m_note && !m_note -> name) {
                // メモリ領域を確保する。
                m_note -> name = new char[8];
            }

             // ノート生成済みかつ名前用のアドレス領域が確保されている場合に実行
            if (m_note && m_note -> name) {
                printf("Input name: ");
                scanf("%7s%*[^\n]%*c", m_note -> name);
            }
        }

        // メッセージを登録する関数
        void RegisterMsg() {
            // ノート生成済みかつメッセージ用のアドレス領域が確保されていない場合に実行
            if (m_note && !m_note -> msg) {
                // メモリ領域を確保する。
                m_note -> msg = new char[100];
            }

             // ノート生成済みかつメッセージ用のアドレス領域が確保されている場合に実行
            if (m_note && m_note -> msg) {
                printf("Input message: ");
                scanf("%99s%*[^\n]%*c", m_note -> msg);
            }
        }

        // ノートの状態(名前とメッセージ)を出力する関数
        void DisplayNote() {
            if (m_note && m_note -> name) {
                printf("Name: %s\n", m_note -> name);
            }

            if (m_note && m_note -> msg) {
                printf("Messagge: %s\n", m_note -> msg);
            }
        }

        // ノートを削除する関数
        void DeleteNote() {
            // name変数のメモリを解放
            delete[] m_note -> name;
            // msg変数のメモリを解放
            delete[] m_note -> msg;
            // m_noteのメモリを解放
            delete m_note;
            // **脆弱性対応**
            // メモリ上のデータを削除する。
            m_note = NULL;
        }
};