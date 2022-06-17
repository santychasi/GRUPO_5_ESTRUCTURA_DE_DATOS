#include "Mechanics.h"

Mechanics::Mechanics()
{
    fileCustomers = new FileAndPdf("clientes.txt");
    fileCars = new FileAndPdf("carros.txt");
}

void Mechanics::createCustomer(string dni, string name, string phone, Car car)
{
    fileCustomers->write(dni, name, phone);
    fileCars->write(dni, car);
}

void Mechanics::addCar(string dni, Car car)
{
    fileCars->write(dni, car);
}

void Mechanics::deleteCar(string dni, string plate)
{
    fileCars->deleteC(dni, plate);
}

void Mechanics::updateCar(string, Car)
{
}

void Mechanics::showCars(string dni)
{
    CircleDoubleLinkedList<shared_ptr<Car>> cars = fileCars->getCars(dni);
    if (cars.getSize() == 0)
    {
        cout << "El cliente no tiene carros" << endl;
    }
    else
    {
        cout << "Los carros del cliente son:" << endl;
        cars.forEach([](shared_ptr<Car> car) {
            cout << car.get()->getPlateLicense() << " " << car.get()->getBrand() << " " << car.get()->getColor()
                 << endl;
        });
    }
}

void Mechanics::generateReport(string)
{
}

void Mechanics::showCustomer(string dni)
{
    shared_ptr<Customer> customer = getCustomer(dni);
    cout << "Cedula: " << customer->getDni() << endl
         << "Nombre: " << customer->getName() << endl
         << "Telefono: " << customer->getPhone() << endl;
}

CircleDoubleLinkedList<shared_ptr<Customer>> Mechanics::getCustomers()
{
    return fileCars->customersAndCars();
}

bool Mechanics::existCustomer(string dni)
{
    return fileCustomers->search(dni);
}

bool Mechanics::existCar(string dni, string plate)
{
    return fileCars->search(dni, plate);
}

void Mechanics::showAllCustomers()
{
    customers = getCustomers();
    if (customers.getSize() == 0)
    {
        cout << "No hay clientes" << endl;
    }
    else
    {
        cout << "Los clientes son:" << endl;
        customers.forEach([](shared_ptr<Customer> customer) {
            cout << "\n\n-------------------------" << endl;
            cout << customer.get()->getDni() << " " << customer.get()->getName() << " " << customer.get()->getPhone()
                 << endl;
            cout << "Lista de carros" << endl;
            customer.get()->getCars().forEach([](shared_ptr<Car> car) {
                cout << car.get()->getPlateLicense() << " " << car.get()->getBrand() << " " << car.get()->getColor()
                     << endl;
            });
        });
    }
}

shared_ptr<Customer> Mechanics::getCustomer(string dni)
{
    return fileCustomers->getCustomer(dni);
}
