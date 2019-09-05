#include "bluetoof.h"
#include <HardwareSerial.h>

UartBluetooth::UartBluetooth(PotatoBupha<char> * buph){
  buf = buph;
  //while(!Serial);
  //delay(10000);
  //Serial.write("this is a test\n");
  //internal_port = &Serial;

  //Serial1.begin(57600);
  //blue_port=&Serial1;
  //delay(1000);

  // Should respond with OK
  //Serial1.print("AT");
  //waitForResponse();

  // Should respond with its version
  //Serial1.print("AT+VERSION");
  //waitForResponse();

  // Set pin to 0000
  //Serial1.print("AT+PIN0000");
  //waitForResponse();

  // Set the name to ROBOT_NAME
  //Serial1.print("AT+NAME");
  //Serial1.print("SUPER_CONNECT");
  //waitForResponse();

  // Set baudrate to 57600
  //Serial1.print("AT+BAUD7");
  //Serial1.flush();
  //Serial1.end();
  Serial1.begin(115200);
  blue_port = &Serial1;
  WaitForResponse();

  //internal_port->println("Done!");
  return;
}

void UartBluetooth::UartGo(){
  char sup = '\0';
  //internal_port->print("hello\n");
  while (blue_port->available()) {
    sup = blue_port->read();
    //internal_port->print(sup);
    blue_port->print(sup);
    buf->pushToBuf((char *) &sup, 1);
  }
  if (sup != '\0') {
    //internal_port->println();
    blue_port->print("\n");
  }

  return;
}


void UartBluetooth::WaitForResponse() {
  int sup;
  while (blue_port->available()) {
    sup = blue_port->read();
    //internal_port->print(sup);
    blue_port->print(sup);
  }
  //internal_port->print("\n");
}
