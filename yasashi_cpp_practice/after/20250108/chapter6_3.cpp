#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {
	
	int n;

	//何行分出力するかの入力
	cout << "何行分出力しますか\n";
	cin >> n;

	//*を指定行の分だけ出力する。
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {	//各行の個数は列の番号と一致している
			cout << '*';
		}
		cout << '\n';
	}
	
}
