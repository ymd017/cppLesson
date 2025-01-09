#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main()
{
	//要素型int,要素数が6の配列を宣言する
	int a[6];

	//配列の各要素に1~10のランダムな値を代入する
	srand(time(NULL));	//時間を用いたシード値で実行するたびに値が変わるようにする

	//一つ前のインデックスの値と同じだったらもう一度ランダムな値を代入するが、
	//indexが0のときは-1になってしまうのでfor文では1からスタートする。
	a[0] = rand() % 10 + 1;

	//一つ前のインデックスの値と同じだったらもう一度ランダムな値を代入する
	int i = 1;
	do {
		for (; i < 6; i++) {
			a[i] = rand() % 10 + 1;		//1~10のランダムな値の代入
		}
	} while (a[i] == a[i - 1]);


	//要素を出力する
	for (int i = 0; i < 5; i++)
	{
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}