#ifndef BLUETOOF_H
#define BLUETOOF_H

#include <Arduino.h>
#include <usb_serial.h>
#include "potato_bupha.h"

// yo
class UartBluetooth {
private:
  Stream * internal_port;
  Stream * blue_port;
  PotatoBupha<char> * buf;
public:
  UartBluetooth(PotatoBupha<char> * buph);
  void UartGo();
  void WaitForResponse();
};

#endif //BLUETOOF_H