/*
* 1時間キーボードとマウスの両方が操作されなかったら、スリープ状態にする
*/

#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <powrprof.h>
#include <winuser.h>
#include <thread>
#pragma comment(lib, "powrprof.lib")
using namespace std;

// 操作されていない時間を返す関数
DWORD getIdleTime() {
	// 変数宣言部
	DWORD idleTime;		// 求める操作されてない時間

	// 最後の入力の時刻データ(dwTimeメンバ)を持つ構造体の生成
	LASTINPUTINFO lii;

	// 構造体メンバに値を設定する
	lii.cbSize = sizeof(LASTINPUTINFO);		// バージョン判定用

	GetLastInputInfo(&lii);					// ティックカウント（PC起動からの経過時間）、1秒は1000

	// 操作されてない時間を求める
	idleTime = static_cast<DWORD>(GetTickCount64()) - lii.dwTime;

	// 操作されてない時間を返す
	return idleTime;
}

// PCをスリープ状態にする特権を有効にする関数
void enableSleepPrivilege() {
	// トークンハンドルの作成
	HANDLE hToken;

	TOKEN_PRIVILEGES tp;

	// OpenProcessToken関数で、現在のプロセス（実行時のこのプログラム）を渡し、特権のアクセストークンをもらう。
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	// AdjustTokenPrivileges関数で、現在のプロセスのアクセストークンを有効にする
	AdjustTokenPrivileges(&hToken, false, &tp, 0, NULL, NULL);

	// トークンを閉じる
	CloseHandle(hToken);
}

// スリープ前通知をする関数
void warning() {
	MessageBox(NULL, TEXT("もうすぐスリープ状態になります"), TEXT("通知"), MB_OK);
}

int main() {

	// 変数宣言部
	DWORD idleThreshold = 3600000;	// スリープのしきい値となる時間の設定（ミリ秒）　1時間
	DWORD idleTime;								// キーボードとマウスが操作されてない時間
	DWORD warningTime = idleThreshold - 60000;					// 1分
	bool warningShown = false;

	// 告知
	cout << "1時間以上キーボードとマウスが操作されなければ、スリープします。\n";

	while (true) {

		// キーボードがとマウスがの無操作時間を取得
		idleTime = getIdleTime();

		// 無操作時間の表示
		//cout << "ただいまの無操作時間： " << (idleTime / 1000 / 60) << "分\n";
		cout << "ただいまの無操作時間： " << (idleTime / 1000 ) << "秒\n";

		// 1分前ならスリープ前通知を出す
		if (idleTime > warningTime && warningShown == false) {
			thread warningMsg(warning);
			warningMsg.detach();
			warningShown = true;
		}

		// 操作されてない時間がしきい値の時間以上にならば、 PCをスリープ状態にする
		if (idleTime > idleThreshold) {
			enableSleepPrivilege();

			cout << "1時間無操作だったため、スリープします。\n";
			SetSuspendState(false, false, false);
			break;
		}

		// 1分ごとに繰り返す
		Sleep(5000);
	}
}