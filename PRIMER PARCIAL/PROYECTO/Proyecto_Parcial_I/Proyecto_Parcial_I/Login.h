#pragma once
#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Login
{
  private:
    string username;
    string password;

  public:
    Login() = default;
    bool run();
    string getUsername();
    string getPassword();
    void setUsername(string username);
    void setPassword(string password);
    void encryptPassword();
    void decryptPassword();
};
