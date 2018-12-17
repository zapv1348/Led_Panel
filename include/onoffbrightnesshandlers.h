#include "basecommandHandler.h"
#include <string>
#include "zap_led.h"

class OnHandler: public BaseCommandHandler{
private:
  WrapLed * led2control;
public:
  OnHandler(WrapLed * Led2Control);
  int OnHandler::executeCommand(std::string st);
};

class OffHandler: public BaseCommandHandler{
private:
  WrapLed * led2control;
public:
    OffHandler(WrapLed * Led2Control);
    int OffHandler::executeCommand(std::string st);
};

class BrtHandler: public BaseCommandHandler{
private:
  WrapLed * led2control;
public:
    BrtHandler(WrapLed * Led2Control);
    int BrtHandler::executeCommand(std::string st);
};