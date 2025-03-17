#include <iostream>
#include <lgpio.h>
#include <unistd.h>

int main(){
    // 変数宣言部
    int gpioLed = 16;
    int gpioSensor = 17;

    // GPIOチップを開く
    int h = lgGpiochipOpen(0);

    if (h < 0){
        std::cout << "GPIOチップが開けませんでした\n";
    }

    // LEDを出力に設定
    // センサーを入力に設定
    int gpioFd_led = lgGpioClaimOutput(h, 0, gpioLed, 0);
    int gpioFd_sensor = lgGpioClaimInput(h, 0, gpioSensor);

    if (gpioFd_led < 0 || gpioFd_sensor < 0){
        std::cout << "GPIOピンの使用権を得られませんでした/n";
    }

    // sensorの出力がHighならLEDを2秒間光らせる
    // 出力がLowのときはLEDは光らせず、監視を続ける
    for(int i=0; i<10; i++){

        int response = lgGpioRead(h, gpioSensor);

        if (response == 1){
            lgGpioWrite(h, gpioLed, 1);
            sleep(2);
            lgGpioWrite(h, gpioLed, 0);
        }
    }

    // 確実にピンをLOWにしてから終了する
    lgGpioWrite(h, gpioLed, 0);

    // Gpioピンの権利を解放
    close(gpioFd_led);
    close(gpioFd_sensor);

    // GPIOチップを閉じる
    lgGpiochipClose(h);

}
