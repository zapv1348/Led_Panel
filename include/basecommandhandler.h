#include <string>
#include "zap_led.h"

class BaseCommandHandler
{
public:
  virtual ~BaseCommandHandler(void);
  virtual int executeCommand(std::string st) = 0;
}