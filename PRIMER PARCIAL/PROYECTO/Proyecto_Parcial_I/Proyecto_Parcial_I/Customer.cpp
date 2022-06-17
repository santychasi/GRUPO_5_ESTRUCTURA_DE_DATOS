#include "Customer.h"

Customer::Customer(string dni, string name, string phone)
{
    this->dni = dni;
    this->name = name;
    this->phone = phone;
}

Customer::Customer(string dni, string name, string phone, CircleDoubleLinkedList<shared_ptr<Car>> cars)
{
    this->dni = dni;
    this->name = name;
    this->phone = phone;
    this->cars = cars;
}

string Customer::getDni()
{
    return dni;
}

string Customer::getName()
{
    return name;
}

string Customer::getPhone()
{
    return phone;
}

CircleDoubleLinkedList<shared_ptr<Car>> Customer::getCars()
{
    return cars;
}

void Customer::setCar(Car car)
{
    shared_ptr<Car> carPtr = make_shared<Car>(car);
    this->cars.pushBack(carPtr);
}

void Customer::setDni(string dni)
{
    this->dni = dni;
}

void Customer::setName(string name)
{
    this->name = name;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}
