#pragma once
#include "Image.h"
#include "Login.h"
#include "Marquee.h"
#include "Mechanics.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;
class Application
{
  public:
    Application();
    void run();
    int exitApp();

  private:
    void renderMenu();
    void renderAddCar();
    void renderImg();
    void renderDeleteCar();
    void renderShowAll();
    void renderHelp();
    Mechanics *mechanics = nullptr;
    Marquee *marquee = nullptr;
    Console *console = nullptr;
    thread *thread = nullptr;
    Login *login = nullptr;
    Image *image = nullptr;
};
