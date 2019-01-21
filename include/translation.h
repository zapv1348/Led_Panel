#ifndef TRANSLATION_
#define TRANSLATION_

#include <string>
#include <map>
#include "zap_led.h"
#include "basecommandhandler.h"

enum CMD_REGISTER_E{
  SUCCESS_REGISTER = 0,
  CMD_EXISTS = 1,
  BAD_PNTR = 2,
  NO_STRING = 3,
};


/*****************************************************************
 * Class that functions as the layer which parses commands
 * then calls the appropriate handler for those commands
 * currently doesn't support destruction because it is a runtime
 * initialization only. Ideally would have a destructor which also
 * got rid of all the BaseCommandHandler classes.
 ****************************************************************/

class TranslationLayer{
  private:
    // deprecated
    // typedef int (TranslationLayer::*pfunc)(std::string);
    std::map<std::string, BaseCommandHandler *> m = {};
    WrapLed * led2Transfer;
  public:
    TranslationLayer();
    CMD_REGISTER_E RegisterCommand(BaseCommandHandler * cmd, std::string cmd_call);
    int CmdHandler(std::string st);
};

#endif //TRANSLATION_