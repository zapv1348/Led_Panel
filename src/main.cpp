//#include <mbed.h>
#include <memory>
#include "bluetoof.h"
#include "zap_led.h"
#include "Arduino.h"
#include "translation.h"
#include "onoffbrightnesshandlers.h"
#include "potato_bupha.h"

/*************************************************************
 * register the commands to the translation layer
 ************************************************************/
void initRegisterCmds(TranslationLayer &handler, std::shared_ptr<WrapLed> ledWrapped){
  handler.RegisterCommand(new OffHandler(ledWrapped), "off");
  handler.RegisterCommand(new OnHandler(ledWrapped), "on");
  handler.RegisterCommand(new BrtHandler(ledWrapped), "brt");
}

int main() {
  //Serial.begin(38400);
  auto ledWrapped = std::make_shared<WrapLed>();
  auto handler = TranslationLayer{};
  auto bupha = PotatoBupha<char>(128);
  auto ublue = UartBluetooth{&bupha};
  // TranslationLayer * handler = new TranslationLayer();

  initRegisterCmds(handler, ledWrapped);

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
