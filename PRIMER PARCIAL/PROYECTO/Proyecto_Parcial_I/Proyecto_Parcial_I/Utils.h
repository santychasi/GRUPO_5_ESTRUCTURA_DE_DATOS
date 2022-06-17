#pragma once
#include <cmath>
#include <conio.h>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
namespace Utils
{
namespace Validation
{
// Validacion de Cedula Algoritmo
// Link:
// https://medium.com/@bryansuarez/c%C3%B3mo-validar-c%C3%A9dula-y-ruc-en-ecuador-b62c5666186f#:~:text=El%20proceso%20para%20la%20validaci%C3%B3n,3%2C4%2C5).
inline bool DNI(string &dni)
{
    if (dni.size() > 10)
    {
        return false;
    }
    int sum = 0;
    int lastDigitDni = dni.at(dni.size() - 1) - '0';
    for (int i = 0; i < dni.size() - 1; i++)
    {
        int digit = (dni[i] - '0');
        if (i % 2 == 0)
        {
            sum += ((digit * 2) >= 10) ? ((digit * 2) - 9) : (digit * 2);
        }
        else
        {
            sum += digit;
        }
    }
    int lastDigitProcess = (((to_string(sum)[0] - '0') + 1) * 10) - sum;
    if (sum == 10 || lastDigitProcess == 10)
    {
        return lastDigitDni == 0;
    }
    return lastDigitProcess == lastDigitDni;
}

inline bool isCharacterOrSpace(char c)
{
    return (isalpha(c) || isspace(c));
}
inline bool isPlate(string &plate, string regularExpression)
{
    regex regex(regularExpression);
    return regex_match(plate, regex);

} // namespace Validation
} // namespace Validation

namespace Read
{
inline string onlyLettersOrSpace(string label)
{
    string input;
    cout << label;
    char character = ' ';

    while (character != 0x0D)
    {

        character = _getch();
        if (character == '\b' && !input.empty())
        {
            input.pop_back();
            Console console;
            console.clearAllScreen();
            cout << "\n\n" + label;
            cout << input;
            continue;
        }

        if (Utils::Validation::isCharacterOrSpace(character) && character != 0x0D)
        {
            cout << character;
            input += character;
            continue;
        }
    }

    return input;
}

inline string onlyNumbers(string label)
{
    string input;
    cout << label;
    char character = ' ';
    while (character != 0x0D)
    {
        if (input.size() >= 10)
        {
            return input;
        }
        character = _getch();
        if (isdigit(character))
        {
            cout << character;
            input += character;
            continue;
        }
        else
        {
            Console console;
            console.clearAllScreen();
            cout << "\n\nSolo se permite numeros!." << endl;
            cout << label;
            character = ' ';
            input.clear();
            continue;
        }
    }
    return input;
}
inline string plate(string label, string regularExpression)
{
    regex regex(regularExpression);
    string input;
    cout << label;
    getline(cin, input);
    if (Utils::Validation::isPlate(input, regularExpression))
    {
        return input;
    }
    else
    {
        Console console;
        console.clearAllScreen();
        cout << "\n\nEl formato debe ser: (AAA-###)." << endl;
        input.clear();
        return plate(label, regularExpression);
    }
}
} // namespace Read
} // namespace Utils
