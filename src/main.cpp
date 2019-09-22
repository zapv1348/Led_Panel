//#include <mbed.h>
#include <memory>
#include <string>
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
  auto ledWrapped = std::make_shared<WrapLed>();
  //auto ledWrapped = WrapLed();
  //auto handler = TranslationLayer{};
  //auto bupha = PotatoBupha<char>(128);
  //auto ublue = UartBluetooth{&bupha};

  ledWrapped->AllOff();


  //initRegisterCmds(handler, ledWrapped);

  //Serial.begin(115200);
  //Serial.println("whytf");
  //pinMode(13, OUTPUT);

  //digitalWrite(13, HIGH);
  //int cnt = 0;
  while(1) {
    //ublue.UartGo();
    //uint32_t tmp = bupha.curSize();
    //// got data
    //if (tmp > 0) {
    //  char str[128];
    //  bupha.popFromBuf(&str[0], tmp);
    //  if (!handler.CmdHandler(str) && tmp < 20){
    //    bupha.pushToBuf(&str[0], tmp);
    //  }
    //  if (tmp > 20) bupha.clear();
    //  cnt++;
    //}
    //if (cnt > 1000) {
    //  cnt = 0;
    //  bupha.clear();
    //}
  }
}
