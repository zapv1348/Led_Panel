#include <string>
#include "zap_led.h"

#ifndef __BASE_COMMAND_HANDLER__
#define __BASE_COMMAND_HANDLER__

class BaseCommandHandler
{
public:
  virtual ~BaseCommandHandler(){};
  virtual int executeCommand(std::string st) = 0;
};

#endif //__BASE_COMMAND_HANDLER__