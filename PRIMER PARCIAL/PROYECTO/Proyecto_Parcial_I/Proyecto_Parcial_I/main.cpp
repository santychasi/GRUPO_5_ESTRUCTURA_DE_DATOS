#include "Application.h"
#include <iostream>
int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Application application;
    application.run();
    return application.exitApp();
}
