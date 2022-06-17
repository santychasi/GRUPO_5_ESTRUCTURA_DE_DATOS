#pragma once
#include <functional>
#include <string>
using namespace std;
class MenuItem
{
  private:
    string label;
    function<void(void)> doSth;

  public:
    MenuItem(string, function<void(void)>);
    string getLabel();
    function<void(void)> getDoSth();
};
