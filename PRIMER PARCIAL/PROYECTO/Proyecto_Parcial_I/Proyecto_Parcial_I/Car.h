#pragma once
#include <string>
using namespace std;
class Car
{
  private:
    string plateLicense;
    string brand;
    string color;

  public:
    Car() = default;
    Car(string, string, string);
    void setPlateLicense(string);
    void setBrand(string);
    void setColor(string);
    string getPlateLicense();
    string getBrand();
    string getColor();
};
