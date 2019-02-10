#include "basecommandhandler.h"
#include <string>
#include <memory>
#include "zap_led.h"

#ifndef __ON_OFF_BRIGHTNESS_HANDLERS__
#define __ON_OFF_BRIGHTNESS_HANDLERS__

class OnHandler: public BaseCommandHandler{
private:
  std::shared_ptr<WrapLed> led2control;
public:
  OnHandler(std::shared_ptr<WrapLed> Led2Control);
  ~OnHandler();
  int executeCommand(std::string st) override;
};

class OffHandler: public BaseCommandHandler{
private:
  std::shared_ptr<WrapLed> led2control;
public:
  OffHandler(std::shared_ptr<WrapLed> Led2Control);
  ~OffHandler();
  int executeCommand(std::string st) override;
};

class BrtHandler: public BaseCommandHandler{
private:
  std::shared_ptr<WrapLed> led2control;
public:
  BrtHandler(std::shared_ptr<WrapLed> Led2Control);
  ~BrtHandler();
  int executeCommand (std::string st) override;
};

#endif //__ON_OFF_BRIGHTNESS_HANDLERS__