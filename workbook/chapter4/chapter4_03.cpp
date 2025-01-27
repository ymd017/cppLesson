/*
* 問題文：
* 全ての文字について、数字、英大文字、英小文字、記号文字がわかる一覧表を出力するプログラムを作成せよ
* 一番左の列に文字、2番目に文字コード、3番目に文字種類を表示する
*/

#include <iostream>
#include <climits>
#include <cctype>
#include <iomanip>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int i;			// ループインデックス

	// for文で文字コードに相当するiを使って、CHAR_MINからCHSR_MAXまで全ての文字を走査する
	for (i = 0; i <= CHAR_MAX; i++) {
		// 一番左の列に文字を出力する
		// 文字が出力できるものかどうかをisprint(i)によって調べる
		// 文字出力できるものはそのまま出力し、できないものはスペースを出力する
		switch (i) {
		case '\a':
			cout << setw(4) << "\\a";
			break;
		case '\b':
			cout << setw(4) << "\\b";
			break;
		case '\f':
			cout << setw(4) << "\\f";
			break;
		case '\n':
			cout << setw(4) << "\\n";
			break;
		case '\r':
			cout << setw(4) << "\\r";
			break;
		case '\t':
			cout << setw(4) << "\\t";
			break;
		case '\v':
			cout << setw(4) << "\\v";
			break;
		default:
			if (isprint(i) != 0) {
				cout << setw(4) << static_cast<char>(i);
			}
			else {
				cout << setw(4) << ' ';
			}
			break;
		}

		// 2番目の列に文字コードに相当するiを表示する
		cout << setw(4) << hex <<  i;

		// if文と各種関数で文字種類を特定し、出力する
		if (isspace(i) != 0) {
			cout << setw(16) << "空白類文字" << "\n";
		}
		else if (isdigit(i) != 0) {
			cout << setw(16) << "数字文字" << "\n";
		}
		else if (islower(i) != 0) {
			cout << setw(16) << "英小文字" << "\n";
		}
		else if (isupper(i) != 0) {
			cout << setw(16) << "英大文字" << "\n";
		}
		else if (ispunct(i) != 0) {
			cout << setw(16) << "記号文字" << "\n";
		}
		else if (iscntrl(i) != 0) {
			cout << setw(16) << "制御文字" << "\n";
		}
		else {
		}

		// 文字コードがCHAR_MAXを超えるとエラーになってしまうので、iがCHAR_MAXになった回の最後にbreakする
		if (i == CHAR_MAX) {
			break;
		}
	}
}