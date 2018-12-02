
/** Goal of this file is to translate the incoming bluetooth control signals
 *  into a an output that can then be interpreted to execute a command
 */

// need a handful of arguments here
// on and off, set color theme (which leads to more processing), set color strip, and set color strip array (cycles array of colors)
// thus we need a map
// maps command to handler
// in bluetoof, we will also make sure all commands come with a prepended string
// so basically commands come in like "led:on", "led:off", "led:sct:theme", "led:scs:60vals", "led:sca:60vals,60vals,60vals"
// bluetoof has to strip it to "on", "off", "sct:theme", "scs:60vals", "sca:60vals,60vals,60vals"
// this class will strip to "", "", "theme", "60vals", "60vals,60vals,60vals,60vals" then call the appropriate handler function

#include <stdlib.h>
#include "translation.h"


int TranslationLayer::OnFunctionHandle(std::string st){
  this->led2Transfer->AllOn();
  return 0;
}

int TranslationLayer::OffFunctionHandle(std::string st){
  this->led2Transfer->AllOff();
  return 0;
}

int TranslationLayer::SCTFunctionHandle(std::string st){
  return 0;
}

int TranslationLayer::SCSFunctionHandle(std::string st){
  return 0;
}

int TranslationLayer::SCAFunctionHandle(std::string st){
  return 0;
}

int TranslationLayer::BRTFunctionHandle(std::string st){
  return 0;
}

TranslationLayer::TranslationLayer(WrapLed * led2TransFor){
  m["on"] = &TranslationLayer::OnFunctionHandle;
  m["off"] = &TranslationLayer::OffFunctionHandle;
  m["sct"] = &TranslationLayer::SCTFunctionHandle;
  m["scs"] = &TranslationLayer::SCSFunctionHandle;
  m["sca"] = &TranslationLayer::SCAFunctionHandle;
  m["brt"] = &TranslationLayer::BRTFunctionHandle;
  led2Transfer = led2TransFor;
  return;
}

int TranslationLayer::CmdHandler(std::string st){
  int ret = st.compare(0,4,"led:");

  if (ret == 0){
    std::string tmp = st.substr(st.find(":"), st.length());
    std::string tmp2 = tmp.substr(st.find(":"), tmp.length());
    for (auto const& x : this->m){
      if (0 == tmp2.compare(0, tmp2.length(), x.first)) {
        std::string tmp3 = tmp2.substr(st.find(":"), st.length());
        ret = (*this.*m[x.first])(tmp3);
        break;
      }
    }
    ret = 1;
  }
  return ret;
}