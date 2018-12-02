//#include <mbed.h>
#include "bluetoof.h"
#include "zap_led.h"
#include "Arduino.h"
#include "translation.h"

int main() {
    // put your setup code here, to run once:
    //Serial.begin(38400);
    UartBluetooth ublue;
    WrapLed ledWrapped;
    TranslationLayer * handler = new TranslationLayer(&ledWrapped);

    //led_init();
    //int data;
    while(1) {
        // put your main code here, to run repeatedly:
        //if (Serial.available() ){
          //data = Serial.read();
          //Serial.println("echo: ");
        //  Serial.write(data);
        //  Serial.write('\n');
        //}
        ublue.UartGo();

        //Serial.println("yo wtf");
        //led_go();
    }
}
