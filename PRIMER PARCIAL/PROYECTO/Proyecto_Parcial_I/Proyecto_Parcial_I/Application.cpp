#include "Application.h"

Application::Application()
{
    this->marquee = new Marquee("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
    this->console = new Console();
    this->login = new Login();
    this->mechanics = new Mechanics();
    this->image = new Image("../img/imagen.png", 48);
}

void Application::run()
{
    marquee->run();
    if (login->run())
    {
        thread = new std::thread(&Application::renderMenu, this);
        thread->join();
    }
}

int Application::exitApp()
{
    return EXIT_SUCCESS;
}

void Application::renderMenu()
{
    Menu menu("-------MECÁNICA ESPE-------               ");
    menu.addMenuItem(0, new MenuItem("Agregar Auto", [&]() {
                         renderAddCar();
                         menu.run();
                     }));
    menu.addMenuItem(1, new MenuItem("Eliminar Auto", [&]() {
                         renderDeleteCar();
                         menu.run();
                     }));
    menu.addMenuItem(2, new MenuItem("Mostrar clientes y autos", [&]() {
                         renderShowAll();
                         menu.run();
                     }));
    menu.addMenuItem(3, new MenuItem("Generar Informe", [&]() { cout << "Generar Informe" << endl; }));
    menu.addMenuItem(4, new MenuItem("Ayuda", [&]() {
                         renderHelp();
                         menu.run();
                     }));
    menu.addMenuItem(5, new MenuItem("Imagen", [&]() { renderImg(); }));
    menu.addMenuItem(6, new MenuItem("Salir", [&]() { exit(0); }));
    menu.changeSymbolSelection("==>");
    menu.run();
}

void Application::renderAddCar()
{

    string dni = Utils::Read::onlyNumbers("\n\nIngrese su cédula: ");
    while (!Utils::Validation::DNI(dni))
    {

        cout << "\n\nCédula invalida, ingrese nuevamente" << endl;
        dni = Utils::Read::onlyNumbers("\n\nIngrese su cédula: ");
    }

    string answer;
    if (!mechanics->existCustomer(dni))
    {
        cout << "\n\nEl cliente no existe" << endl;
        answer = Utils::Read::onlyLettersOrSpace("\nDesea agregarlo? (s/n): ");
    }

    if (answer == "s" || answer == "S")
    {
        console->clearAllScreen();
        cout << endl;
        cout << endl;
        string name = Utils::Read::onlyLettersOrSpace("\n\nIngrese el nombre: ");
        string phone = Utils::Read::onlyNumbers("\n\nIngrese el teléfono: ");
        /* while ( !Utils::Validation::phone( phone ) )
        {
            cout << "\nTeléfono invalido, ingrese nuevamente" << endl;
            phone = Utils::Read::onlyNumbers( "Ingrese su teléfono: " );
        } */
        cout << "\n\n\n-----Datos del Automóvil------" << endl;
        string carBrand = Utils::Read::onlyLettersOrSpace("\n\nIngrese la marca del auto: ");
        string carColor = Utils::Read::onlyLettersOrSpace("\n\nIngrese el color del auto: ");
        string carPlate = Utils::Read::plate("\n\nIngrese la placa del auto (AAA-###): ", "^[A-Z]{3}-\\d{3,4}$");

        mechanics->createCustomer(dni, name, phone, Car(carPlate, carBrand, carColor));
        cout << "\n\nCliente y Auto agregado" << endl;
        cout << "\n\nPresione enter para continuar" << endl;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        return;
    }
    else
    {
        string carBrand = Utils::Read::onlyLettersOrSpace("\n\nIngrese la marca del auto: ");
        string carColor = Utils::Read::onlyLettersOrSpace("\n\nIngrese el color del auto: ");
        string carPlate = Utils::Read::plate("\n\nIngrese la placa del auto (AAA-###): ", "^[A-Z]{3}-\\d{3,4}$");
        mechanics->addCar(dni, Car(carPlate, carBrand, carColor));
        cout << "\n\nAuto agregado" << endl;
        system("pause");
        return;
    }
}

void Application::renderImg()
{
    // 48 #Selecciona RGB de primer plano (foreground color).
    // 38 #Selecciona el color de fondo RGB(background coloR).
    //  art.gray_scale();
    image->fontSize(2, 2);   // tamaño de cada caracter en pixeles.
    image->resize(200, 500); // redimensiona la imagen.
    image->showImage();      // imrpime la imagen en ascii en la consola
    system("pause");
    image->fontSize(8, 16);
    image->Imagefile("ascii_art.txt"); // Guarga el ascii art en un archivo.
}

void Application::renderDeleteCar()
{
    string dni = Utils::Read::onlyNumbers("\n\nIngrese su cédula: ");
    while (!Utils::Validation::DNI(dni))
    {
        cout << "\n\nCédula invalida, ingrese nuevamente" << endl;
        dni = Utils::Read::onlyNumbers("\n\nIngrese su cédula: ");
    }
    if (mechanics->existCustomer(dni))
    {
        cout << "\n\nDatos del cliente" << endl;
        mechanics->showCustomer(dni);
        cout << "\n\nLista de automoviles" << endl;
        mechanics->showCars(dni);
        string carPlate = Utils::Read::plate("\n\nIngrese la placa del auto (AAA-###): ", "^[A-Z]{3}-\\d{3,4}$");
        if (mechanics->existCar(dni, carPlate))
        {
            string answer = Utils::Read::onlyLettersOrSpace("\nDesea eliminarlo? (s/n): ");
            if (answer == "s" || answer == "S")
            {
                mechanics->deleteCar(dni, carPlate);
                cout << "\n\nAuto eliminado" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "\n\nPresione enter para continuar" << endl;
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                return;
            }
        }
    }
}

void Application::renderShowAll()
{
    mechanics->showAllCustomers();
    cout << "\n\nPresione enter para continuar" << endl;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}

void Application::renderHelp()
{
    cout << "\n\n\n-----Ayuda-----" << endl;
    ifstream file;
    file.open("Ayuda.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    cout << "\n\nPresione enter para continuar" << endl;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}
