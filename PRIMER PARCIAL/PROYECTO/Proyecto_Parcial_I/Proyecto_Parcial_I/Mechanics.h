#pragma once
#include "FileAndPdf.h"
#include <iostream>
using namespace std;
class Mechanics
{
  private:
    CircleDoubleLinkedList<shared_ptr<Customer>> customers;
    FileAndPdf *fileCustomers = nullptr;
    FileAndPdf *fileCars = nullptr;

  public:
    Mechanics();
    void createCustomer(string dni, string name, string phone, Car car);
    void addCar(string, Car);
    void deleteCar(string, string);
    void updateCar(string, Car);
    void showCars(string);
    void generateReport(string);
    void showCustomer(string dni);
    bool existCustomer(string);
    bool existCar(string, string);
    void showAllCustomers();
    CircleDoubleLinkedList<shared_ptr<Customer>> getCustomers();
    shared_ptr<Customer> getCustomer(string);
};
