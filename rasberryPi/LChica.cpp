#include
#include <lgpio.h>
#include <unistd.h>

#define LED_PIN 19

using namespace std;

int main() {

    int h;
    h = lgGpiochipOpen(0);

    if (h < 0) {
        cout << "lgpio初期化失敗\n";
        return 1;
    }

    if (lgGpioClaimOutput(h, LG_SET_PULL_NONE, LED_PIN, 0) < 0) {
        cout << "GPIOを出力モードにできませんでした\n";
        return 1;
    }

    lgGpioWrite(h, LED_PIN, 1);
    cout << "LED点灯\n";

    usleep(2000000);

    lgGpioWrite(h, LED_PIN, 0);
    cout << "LED消灯\n";

    lgGpiochipClose(h);
    return 0;

}
