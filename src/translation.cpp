
/** Goal of this file is to translate the incoming bluetoof control signals
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
#include "onoffbrightnesshandlers.h"

TranslationLayer::TranslationLayer(){}

CMD_REGISTER_E TranslationLayer::RegisterCommand(BaseCommandHandler * cmd, std::string cmd_call) {
  if (cmd == NULL) return BAD_PNTR;
  if (cmd_call.length() == 0) return NO_STRING;
  if (m.find(cmd_call) == m.end()){
    m[cmd_call] = cmd;
    return SUCCESS_REGISTER;
  } else {
    return CMD_EXISTS;
  }
}

int TranslationLayer::CmdHandler(std::string st){
  int ret = st.compare(0,4,"led:");


  if (ret == 0){
    // gets everything after led:
    std::string tmp = st.substr(st.find(":") + 1);
    for (auto x : tmp) {
      Serial.print(x);
    }

    for (auto const& x : this->m){
      if (0 == tmp.compare(0, tmp.find(":"), x.first)) {
        std::string tmp3 = tmp.substr(st.find(":") + 1);
        ret = x.second->executeCommand(tmp3);
        ret = 1;
        break;
      }
    }
  }
  return ret;
}