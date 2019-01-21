//#include <mbed.h>
#include "bluetoof.h"
#include "zap_led.h"
#include "Arduino.h"
#include "translation.h"
#include "onoffbrightnesshandlers.h"


void initRegisterCmds(TranslationLayer * handler, WrapLed * ledWrapped){
  handler->RegisterCommand(new OffHandler(ledWrapped), "off");
  handler->RegisterCommand(new OnHandler(ledWrapped), "on");
  handler->RegisterCommand(new BrtHandler(ledWrapped), "brt");
}

int main() {
  //Serial.begin(38400);
  UartBluetooth ublue;
  WrapLed ledWrapped;
  TranslationLayer * handler = new TranslationLayer();

  initRegisterCmds(handler, &ledWrapped);

  while(1) {
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
