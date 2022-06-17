#include "Menu.h"

Menu::Menu(string title) : title(title)
{
}

void Menu::addMenuItem(size_t id, MenuItem *item)
{
    menuItems.insert(pair<size_t, MenuItem *>(id, item));
}

void Menu::changeSymbolSelection(string syb)
{
    this->symbol = syb;
}

void Menu::viewMenuItemConsole(size_t option)
{
    console.clearAllScreen();
    cout << endl;
    cout << endl;
    cout << title << endl;
    string spaces = symbol + " ";
    fill(spaces.begin(), spaces.end(), ' ');
    for (short i = 0; i < menuItems.size(); i++)
    {
        if ((short)option == i + 1)
        {
            console.newPositionCursor(1, i + 3);
            console.colorSelection();
            cout << symbol << menuItems[i]->getLabel() << endl;
            console.colorDefault();
        }
        else
        {
            cout << spaces << menuItems[i]->getLabel() << endl;
        }
    }
}

void Menu::navigation()
{
    size_t i{1};
    viewMenuItemConsole(1);
    while (true)
    {
        int option = _getch();
        switch (option)
        {
        case $::KEY_UP: {
            if (i != 1)
            {
                i--;
                viewMenuItemConsole(i);
            }
            break;
        }
        case $::KEY_DOWN: {
            if (i != menuItems.size())
            {
                i++;
                viewMenuItemConsole(i);
            }
            break;
        }
        case $::KEY_ENTER: {
            console.clearAllScreen();
            menuItems.at(i - 1)->getDoSth()();
            cin.get();
            break;
        }
        case $::KEY_ESCAPE: {
            console.clearAllScreen();
            stop();
            break;
        }
        default:
            break;
        }
    }
}

void Menu::run()
{
    navigation();
}

int Menu::stop()
{
    return console.consoleExit();
}

size_t Menu::sizeMenuItems()
{
    return menuItems.size();
}
