#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main()
{
	//要素型int, 要素数が6の配列を宣言する
	int a[6];

	//全要素を1~10の乱数で埋めつくす
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		a[i] = rand() % 10 + 1;
	}

	//要素を出力する
	for (int i = 0; i < 6; i++)
	{
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}

