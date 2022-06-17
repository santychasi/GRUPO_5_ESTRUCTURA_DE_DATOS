#pragma once
#include "Console.h"
#include "MenuItem.h"
#include <algorithm>
#include <conio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Menu
{
  private:
    string title{""};
    map<size_t, MenuItem *> menuItems;
    string symbol = ">";
    Console console;
    enum $
    {
        KEY_UP = 72,
        KEY_DOWN = 80,
        KEY_ENTER = 13,
        KEY_ESCAPE = 27
    };

  public:
    Menu(string);
    void addMenuItem(size_t, MenuItem *);
    void changeSymbolSelection(string);
    void viewMenuItemConsole(size_t);
    void navigation();
    void run();
    int stop();
    size_t sizeMenuItems();
};
