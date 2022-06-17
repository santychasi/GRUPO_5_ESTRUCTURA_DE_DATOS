#pragma once
#ifndef _CONSOLE_
#define _CONSOLE_
#include <Windows.h>
#include <stdexcept>
using namespace std;
class Console
{
  private:
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {0, 0};

  public:
    Console()
    {
        position = {0, 0};
    }
    void clearAllScreen()
    {
        char fill = ' ';
        COORD tl = {0, 0};
        CONSOLE_SCREEN_BUFFER_INFO s;
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(console, &s);
        DWORD written, cells = s.dwSize.X * s.dwSize.Y;
        FillConsoleOutputCharacter(console, fill, cells, tl, &written);
        FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
        SetConsoleCursorPosition(console, tl);
    }

    void newPositionCursor(short x, short y)
    {
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(handle, position);
    }

    int consoleExit()
    {
        return EXIT_SUCCESS;
    }

    void colorSelection()
    {
        SetConsoleTextAttribute(handle, BACKGROUND_GREEN | BACKGROUND_BLUE);
    }

    void colorDefault()
    {
        SetConsoleTextAttribute(handle, 15);
    }

    void write(string text)
    {
        auto *buffer = (CHAR_INFO *)calloc(text.size(), sizeof(CHAR_INFO));

        if (buffer == nullptr)
        {
            return;
        }

        SMALL_RECT area = {
            position.X,                                     // left
            position.Y,                                     // top
            static_cast<SHORT>(position.X + text.length()), // right
            static_cast<SHORT>(position.Y + 1)              // bottom
        };
        COORD sizeBuffer = {static_cast<SHORT>(text.size()), 1};

        int i = 0;
        for (auto &c : text)
        {
            buffer[i].Char.AsciiChar = c;
            buffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            i++;
        }

        WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE), buffer, sizeBuffer, {0, 0}, &area);
        free(buffer);
    }
    short getX()
    {
        return position.X;
    }
    short getY()
    {
        return position.Y;
    }
    void setX(short x)
    {
        position.X = x;
    }
    void setY(short y)
    {
        position.Y = y;
    }
};
#endif // _CONSOLE_
