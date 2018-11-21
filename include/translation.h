#include <string>
#include <map>

class TranslationLayer{
  private:
    typedef int (*pfunc)(std::string);
    std::map<std::string, pfunc> m;
  public:
    TranslationLayer();
    int cmd_handler(std::string st);
};
