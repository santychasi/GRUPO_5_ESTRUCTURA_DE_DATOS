#pragma once
#ifndef _FILE_
#define _FILE_

#include "Customer.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class FileAndPdf
{
  private:
    string name;
    ofstream file;
    CircleDoubleLinkedList<shared_ptr<Car>> cars;

  public:
    FileAndPdf(string name);
    void write(string dni, string name, string phone);
    void write(string dni, Car car);
    CircleDoubleLinkedList<shared_ptr<Customer>> customersAndCars();
    bool search(string dni);
    bool search(string dni, string plate);
    void update(string dni, Car car);
    void deleteC(string dni, string plate);
    CircleDoubleLinkedList<shared_ptr<Car>> getCars(string dni);
    shared_ptr<Customer> getCustomer(string dni);
};
#endif // _FILE_
