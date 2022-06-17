#pragma once
#ifndef _MARQUEE_
#define _MARQUEE_

#include "Console.h"
#include <string>
#include <thread>
using namespace std;
class Marquee
{
  private:
    string text;
    thread *background = nullptr;
    Console *console = nullptr;

  public:
    Marquee(string text);

    void run();
    void show();
    void setText(string text);
};
#endif // DEBUG
