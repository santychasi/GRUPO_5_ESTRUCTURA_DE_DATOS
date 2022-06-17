#include "FileAndPdf.h"

FileAndPdf::FileAndPdf(string name)
{
    this->name = name;
}

void FileAndPdf::write(string dni, string name, string phone)
{

    file.open(this->name, ios_base::out | ios_base::app);
    file << dni << "," << name << "," << phone << endl;
    file.close();
}

void FileAndPdf::write(string dni, Car car)
{
    file.open(this->name, ios_base::out | ios_base::app);
    file << dni << "," << car.getPlateLicense() << "," << car.getBrand() << "," << car.getColor() << endl;
    file.close();
}

CircleDoubleLinkedList<shared_ptr<Customer>> FileAndPdf::customersAndCars()
{
    string line;
    ifstream file("clientes.txt");
    CircleDoubleLinkedList<shared_ptr<Customer>> customers;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            string dni, name, phone;
            getline(ss, dni, ',');
            getline(ss, name, ',');
            getline(ss, phone, ',');
            CircleDoubleLinkedList<shared_ptr<Car>> cars = getCars(dni);
            shared_ptr<Customer> customer = make_shared<Customer>(dni, name, phone, cars);
            customers.pushBack(customer);
        }
        file.close();
    }
    return customers;
}

bool FileAndPdf::search(string dni)
{
    if (file.fail())
    {
        return false;
    }
    string line;
    ifstream file(this->name);
    while (getline(file, line, ','))
    {
        stringstream ss(line);
        string dni_file;
        ss >> dni_file;
        if (dni_file == dni)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

bool FileAndPdf::search(string dni, string plate)
{
    if (file.fail())
    {
        return false;
    }
    string line;
    ifstream file(this->name);
    while (getline(file, line))
    {
        stringstream ss(line);
        string dni_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string plate_license_file = line.substr(0, line.find(","));

        if (dni_file == dni && plate_license_file == plate)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void FileAndPdf::update(string dni, Car car)
{
}

void FileAndPdf::deleteC(string dni, string plate)
{

    if (file.fail())
    {
        return;
    }
    ofstream temp("temp.txt");
    string line;
    ifstream file(this->name);
    while (getline(file, line))
    {
        stringstream ss(line);
        string dni_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string plate_license_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string brand_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string color_file = line;

        if (dni_file == dni && plate_license_file == plate)
        {
            continue;
        }
        else
        {
            temp << dni_file << "," << plate_license_file << "," << brand_file << " " << color_file << endl;
        }
    }
    file.close();
    temp.close();
    remove(this->name.c_str());
    int i = rename("temp.txt", this->name.c_str());
}
CircleDoubleLinkedList<shared_ptr<Car>> FileAndPdf::getCars(string dni)
{
    CircleDoubleLinkedList<shared_ptr<Car>> list;
    string line;
    ifstream file(this->name);
    while (getline(file, line))
    {
        stringstream ss(line);
        string dni_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string plate_license_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string brand_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string color_file = line;

        if (dni_file == dni)
        {
            shared_ptr<Car> car(new Car(plate_license_file, brand_file, color_file));
            list.pushBack(car);
        }
    }
    file.close();
    return list;
}

shared_ptr<Customer> FileAndPdf::getCustomer(string dni)
{
    shared_ptr<Customer> customer;
    string line;
    ifstream file(this->name);
    while (getline(file, line))
    {

        stringstream ss(line);
        string dni_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string name_file = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);
        string phone_file = line;

        if (dni_file == dni)
        {
            customer = make_shared<Customer>(dni_file, name_file, phone_file);
        }
    }
    file.close();
    return customer;
}
