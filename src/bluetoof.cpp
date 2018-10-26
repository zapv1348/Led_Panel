#include "bluetoof.h"
//#include <Arduino.h>
#include <HardwareSerial.h>

UartBluetooth::UartBluetooth(){
  Serial.begin(9600);
  //while(!Serial);
  //delay(10000);
  Serial.write("this is a test\n");
  this->internal_port = &Serial;

  //Serial1.begin(57600);
  //this->blue_port=&Serial1;
  //delay(1000);

  // Should respond with OK
  //Serial1.print("AT");
  //this->waitForResponse();

  // Should respond with its version
  //Serial1.print("AT+VERSION");
  //this->waitForResponse();

  // Set pin to 0000
  //Serial1.print("AT+PIN0000");
  //this->waitForResponse();

  // Set the name to ROBOT_NAME
  //Serial1.print("AT+NAME");
  //Serial1.print("SUPER_CONNECT");
  //this->waitForResponse();

  // Set baudrate to 57600
  //Serial1.print("AT+BAUD7");
  //Serial1.flush();
  //Serial1.end();
  Serial1.begin(115200);
  this->blue_port = &Serial1;
  this->waitForResponse();

  this->internal_port->println("Done!");
  return;
}

void UartBluetooth::uart_go(){
  int sup;
  while (this->blue_port->available()) {
    sup = this->blue_port->read();
    this->internal_port->print(sup);
  }
  while (this->internal_port->available()){
    sup = this->internal_port->read();
    this->blue_port->println(sup);
  }
  //this->internal_port->println("test");
  return;
}


void UartBluetooth::waitForResponse() {
  int sup;
  while (this->blue_port->available()) {
    sup = this->blue_port->read();
    this->internal_port->print(sup);
    this->blue_port->print(sup);
  }
  this->internal_port->print("\n");
}
