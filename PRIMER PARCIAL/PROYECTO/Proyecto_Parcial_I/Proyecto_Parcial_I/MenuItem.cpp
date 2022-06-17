#include "MenuItem.h"

MenuItem::MenuItem(string label, function<void(void)> doSth) : label(label), doSth(doSth)
{
}

string MenuItem::getLabel()
{
    return label;
}

function<void(void)> MenuItem::getDoSth()
{
    return doSth;
}
