
#include "onoffbrightnesshandlers.h"

enum STR2INT_ERROR { SUCCESS, OVERFLO, UNDERFLO, INCONVERTIBLE };

static STR2INT_ERROR stoi(std::string &st, int &ret, int base = 10){
  int tmp = 0;
  for (auto& i : st){
    if (i >= '0' && i <= '9'){
      tmp = tmp * base + (i - '0');
    } else {
      return INCONVERTIBLE;
    }
  }
  ret = tmp;
  return SUCCESS;
}


OnHandler::OnHandler(WrapLed * Led2Control){
  this->led2control = Led2Control;
}

OnHandler::~OnHandler(){

}

int OnHandler::executeCommand(std::string st){
  this->led2control->AllOn();
  return 0;
}

OffHandler::OffHandler(WrapLed * Led2Control){
  this->led2control = Led2Control;
}

OffHandler::~OffHandler(){

}

int OffHandler::executeCommand(std::string st){
  this->led2control->AllOff();
  return 0;
}

BrtHandler::BrtHandler(WrapLed * Led2Control){
    this->led2control = Led2Control;
}

BrtHandler::~BrtHandler(){

}

int BrtHandler::executeCommand(std::string st){
  int ret = 0;
  STR2INT_ERROR err = stoi(st, ret, 10);
  if (err != SUCCESS){
    return -1;
  }
  if (ret < 256 && ret > 0){
    this->led2control->SetBrightness(ret);
    return 0;
  }
  else return -1;
}