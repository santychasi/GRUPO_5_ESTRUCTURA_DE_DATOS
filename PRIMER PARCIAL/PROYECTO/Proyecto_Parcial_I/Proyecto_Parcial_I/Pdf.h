#pragma once
#include <sstream>
#include <string>
using namespace std;
class Pdf
{
  private:
    string name;
    ostringstream html;

  public:
    void create();
};
