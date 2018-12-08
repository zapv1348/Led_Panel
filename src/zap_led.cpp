#include "zap_led.h"



//implement stuff
WrapLed::WrapLed(){
  FastLED.addLeds<NEOPIXEL, 10>(zapled, NUMLEDS);
  FastLED.setBrightness(0);                          
}

void WrapLed::AllOff(){
  FastLED.setBrightness(0);
}

void WrapLed::AllOn(){
  FastLED.setBrightness(this->brightness);
}

void WrapLed::SetBrightness(int brightness){
  this->brightness = brightness;
  FastLED.setBrightness(this->brightness);
}

void WrapLed::OneColor(std::vector<int> color){
  return;
}

void WrapLed::ArrColor(std::vector<std::vector<int>> &colors){
  return;
}

void WrapLed::IceTheme(){
  return;
}
