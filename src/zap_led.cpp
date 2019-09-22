#include "zap_led.h"


#define DATA_PIN 3

//implement stuff
WrapLed::WrapLed(){
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(zapled, NUMLEDS);
  for (int i = 0; i < NUMLEDS; ++i) {
    this->zapled[i] = 0;
  }
  FastLED.setBrightness(40);
  FastLED.show();
}

void WrapLed::AllOff(){
  FastLED.setBrightness(0);
  FastLED.show();
}

void WrapLed::AllOn(){
  FastLED.setBrightness(this->brightness);
  FastLED.show();
}

void WrapLed::SetBrightness(int brightness){
  this->brightness = brightness;
  FastLED.setBrightness(this->brightness);
  FastLED.show();
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
