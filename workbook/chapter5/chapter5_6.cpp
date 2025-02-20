#include <iostream>
using namespace std;

/* int型で6つの要素数を持つ配列に1~10のランダムな整数を代入する
* 既に選んだ値は選ばないようにする
*/

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main(){
	
	//int型で要素を6つの配列のメモリを確保する
	int a[6];

	//配列の各要素に1~10のランダムな整数を代入する
	//既に選んだ値を選んだ場合はもう一度選びなおす
	srand(time(NULL)); //時間を用いたシード値で、実行のたびに値が変わるようにする

	for (int i = 0; i < 6;i++) {

		int j = 0; //今までに値が格納された要素の値を調べるのに使用するカウンター
		do{
			a[i] = rand() % 10 + 1;

			for (; j < i; j++) {
				if (a[i] == a[j]) {
					break;		//同じ値が見つかったらfor文を途中で抜ける
				}
			}
		} while (j != i); // 内側のfor文を途中で抜けたときはもう一度値を選びなおす
	}

	//配列の要素を出力する
	for (int i = 0; i < 6; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}

}
