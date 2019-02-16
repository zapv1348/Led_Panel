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
  //Serial.begin(38400);
  auto ledWrapped = std::make_shared<WrapLed>();
  auto handler = TranslationLayer{};
  auto bupha = PotatoBupha<char>(128);
  auto ublue = UartBluetooth{&bupha};

  initRegisterCmds(handler, ledWrapped);

  while(1) {
    ublue.UartGo();
    // got data
    if (!bupha.isEmpty()){
      char str[128];
      bupha.popFromBuf(str, bupha.curSize());
      handler.CmdHandler(str);
    }
  }
}
