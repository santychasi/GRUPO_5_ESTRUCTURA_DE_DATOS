#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_
#include "Car.h"
#include "CircleDoubleLinkedList.h"
using namespace std;
class Customer
{
  private:
    string dni;
    string name;
    string phone;
    CircleDoubleLinkedList<shared_ptr<Car>> cars;
    Car car;

  public:
    Customer() = default;
    Customer(string dni, string name, string phone);
    Customer(string dni, string name, string phone, CircleDoubleLinkedList<shared_ptr<Car>> cars);
    string getDni();
    string getName();
    string getPhone();
    CircleDoubleLinkedList<shared_ptr<Car>> getCars();
    void setCar(Car car);
    void setDni(string dni);
    void setName(string name);
    void setPhone(string phone);
};
#endif // _CUSTOMER_
