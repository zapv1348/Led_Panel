#ifndef BLUETOOF_H
#define BLUETOOF_H

#include <Arduino.h>
#include <usb_serial.h>
// yo
class UartBluetooth {
private:
  Stream * internal_port;
  Stream * blue_port;
public:
  UartBluetooth();
  void UartGo();
  void WaitForResponse();
};

#endif //BLUETOOF_H