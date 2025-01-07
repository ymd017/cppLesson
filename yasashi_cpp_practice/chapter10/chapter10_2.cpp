//動的なメモリを使用した後はdeleteでメモリ解放をしたほうが良い

#include <iostream>
using namespace std;

int main(){
	int* pA;
	pA = new int;
	*pA = 10;

	delete pA;

	return 0;
}
