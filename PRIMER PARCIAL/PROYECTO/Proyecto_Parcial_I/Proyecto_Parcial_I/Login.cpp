#include "Login.h"

bool Login::run()
{
    while (true)
    {
        cout << "\n\nIngrese su usuario: ";
        string user;
        getline(cin, user);
        username = user;
        cout << "Ingrese su contrasena: ";
        char character = ' ';
        while (character != 0x0D)
        {
            character = _getch();
            cout << "*";
            if (character != 0x0D)
            {
                password += character;
            }
        }
        if ("admin" == this->username && "admin" == this->password)
        {
            break;
        }
        password.clear();
    }
    return "admin" == username && "admin" == password;
}

string Login::getUsername()
{
    return username;
}

string Login::getPassword()
{
    return password;
}

void Login::setUsername(string username)
{
    this->username = username;
}

void Login::setPassword(string password)
{
    this->password = password;
}

void Login::encryptPassword()
{
    stringstream ss;
    string passwordEncrypt;
    for (auto &c : password)
    {
        ss << hex << (int)c << ".";
    }
    password = ss.str();
}

void Login::decryptPassword()
{
    stringstream stream;
    string passwordEncrypt = password;
    password.clear();
    string token;
    size_t pos = 0;
    string delimiter = ".";
    int decimal = 0;
    while ((pos = passwordEncrypt.find(delimiter)) != string::npos)
    {
        stringstream stream;
        token = passwordEncrypt.substr(0, pos);
        stream << hex << token;
        stream >> decimal;
        cout << decimal << endl;
        password += decimal;
        passwordEncrypt.erase(0, pos + delimiter.length());
    }
}
