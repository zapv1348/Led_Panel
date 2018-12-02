#ifndef TRANSLATION_
#define TRANSLATION_

#include <string>
#include <map>
#include "zap_led.h"

class TranslationLayer{
  private:
    typedef int (TranslationLayer::*pfunc)(std::string);
    std::map<std::string, pfunc> m = {
      {"on", NULL},
      {"off", NULL},
      {"sct", NULL},
      {"scs", NULL},
      {"sca", NULL}
    };
    WrapLed * led2Transfer;
  public:
    TranslationLayer(WrapLed * led2TransFor);
    int CmdHandler(std::string st);
    int OnFunctionHandle(std::string st);
    int OffFunctionHandle(std::string st);
    int SCTFunctionHandle(std::string st);
    int SCSFunctionHandle(std::string st);
    int SCAFunctionHandle(std::string st);
    int BRTFunctionHandle(std::string st);
};

#endif //TRANSLATION_