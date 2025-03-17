#include <iostream>
#include <lgpio.h>
#include <unistd.h>


int main(){


    // 変数宣言部
    int gpio_led = 16;
    int repeat;


    // GPIOチップを開く
    int h = lgGpiochipOpen(0);


    if(h < 0){
        std::cout << "GPIOチップを開けませんでした。\n";
        return 1;
    }
    
    // GPIOを出力に設定する
    int gpio_fd = lgGpioClaimOutput(h, 0, gpio_led, 0);


    if(gpio_fd < 0){
        std::cout << "GPIOピンの使用権が得られませんでした。\n";
        return 1;
    }


    // 点灯消灯の繰り返し回数の入力
    std::cout << "LEDの点灯消灯を繰り返す回数を入力してください。\n";
    std::cin >> repeat;


    // LEDの点灯消灯を繰り返す
    for(int i = 0; i < repeat; i++){
    // 点灯
    lgGpioWrite(h, gpio_led, 1);
    sleep(2);


    // 消灯
    lgGpioWrite(h, gpio_led, 0);
    sleep(2);
    }


    // 確実にピンをLOWにしてから解放する
    lgGpioWrite(h, gpio_led, 0);


    // GPIOピンの権利を解放
    close(gpio_fd);


    // GPIOチップを閉じる
    lgGpiochipClose(h);


    return 0;
}
