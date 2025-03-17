#include <iostream>
#include <lgpio.h>
#include <unistd.h>

int main(){

    // 変数宣言部
    int gpio_led1 = 16;     // LED1のGPIO番号
    int gpio_led2 = 17;     // LED2のGPIO番号
    int repeat;

    // GPIOチップを開く
    int h = lgGpiochipOpen(0);

    if(h < 0){
        std::cout << "GPIOチップを開けませんでした。\n";
        return 1;
    }
    
    // GPIOを出力に設定する
    // LED1は初期状態をHIGHにする、LED2はLOWにする
    int gpio_fd1 = lgGpioClaimOutput(h, 0, gpio_led1, 1);
    int gpio_fd2 = lgGpioClaimOutput(h, 0, gpio_led2, 0);

    if(gpio_fd1 < 0 || gpio_fd2 < 0){
        std::cout << "GPIOピンの使用権が得られませんでした。\n";
        return 1;
    }

    // 点灯消灯の繰り返し回数の入力
    std::cout << "LEDの点灯消灯を繰り返す回数を入力してください。\n";
    std::cin >> repeat;

    // LEDを交互に点灯させる
    for(int i = 0; i < repeat; i++){
        // LED1消灯、LED2点灯
        lgGpioWrite(h, gpio_led1, 0);
        lgGpioWrite(h, gpio_led2, 1);
        sleep(1);
        // LED1点灯、LED2消灯
        lgGpioWrite(h, gpio_led1, 1);
        lgGpioWrite(h, gpio_led2, 0);
        sleep(1);
    }

    // 確実にピンをLOWにしてから解放する
    lgGpioWrite(h, gpio_led1, 0);
    lgGpioWrite(h, gpio_led2, 0);

    // GPIOピンの権利を解放
    close(gpio_fd1);
    close(gpio_fd2);

    // GPIOチップを閉じる
    lgGpiochipClose(h);

    return 0;
}
