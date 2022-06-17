#include "Car.h"

Car::Car(string plateLicense, string brand, string color)
{
    this->plateLicense = plateLicense;
    this->brand = brand;
    this->color = color;
}

void Car::setPlateLicense(string PlateLicense)
{
    this->plateLicense = PlateLicense;
}

void Car::setBrand(string Brand)
{
    this->brand = Brand;
}

void Car::setColor(string Color)
{
    this->color = Color;
}

string Car::getPlateLicense()
{
    return plateLicense;
}

string Car::getBrand()
{
    return brand;
}

string Car::getColor()
{
    return color;
}
