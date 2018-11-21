
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

int OnFunctionHandle(std::string){
  return 0;
}

int OffFunctionHandle(std::string){
  return 0;
}

int SCTFunctionHandle(std::string){
  return 0;
}

int SCSFunctionHandle(std::string){
  return 0;
}

int SCAFunctionHandle(std::string){
  return 0;
}

TranslationLayer::TranslationLayer(){
  m["on"] = OnFunctionHandle;
  m["off"] = OffFunctionHandle;
  m["sct"] = SCTFunctionHandle;
  m["scs"] = SCSFunctionHandle;
  m["sca"] = SCAFunctionHandle;
  return;
}

int TranslationLayer::cmd_handler(std::string st){
  return 0;
}