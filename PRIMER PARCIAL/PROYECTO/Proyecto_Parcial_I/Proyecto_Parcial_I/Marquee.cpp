#include "Marquee.h"

Marquee::Marquee(string text)
{
    string temp = " ";
    this->text = temp.append(text);
    this->console = new Console();
    console->setX((short)(-1 * text.size()));
}

void Marquee::run()
{
    if (!background)
    {
        background = new thread(&Marquee::show, this);
        background->detach();
    }
}

void Marquee::setText(string text)
{
    this->text = text;
}

void Marquee::show()
{
    string temp = text;
    while (true)
    {
        this->console->write(temp);
        this->console->setX(console->getX() + 1);
        if (console->getX() > 75)
        {
            temp.pop_back();
            if (temp.empty())
            {
                console->setX((short)(-1 * text.size()));
                temp = text;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(75));
    }
}
