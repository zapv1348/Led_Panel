#ifndef ZAP_LED_
#define ZAP_LED_

#include "FastLED.h"
#include <string>
#include <vector>

#define NUMLEDS 5

class WrapLed {
  private:
    CRGB zapled[NUMLEDS];
    int brightness = 200;
  public:
    WrapLed();
    void AllOn();
    void AllOff();
    void SetBrightness(int brightness);
    void OneColor(std::vector<int> color);
    void ArrColor(std::vector<std::vector<int>> &colors);
    void IceTheme();
};

#endif //ZAP_LED_