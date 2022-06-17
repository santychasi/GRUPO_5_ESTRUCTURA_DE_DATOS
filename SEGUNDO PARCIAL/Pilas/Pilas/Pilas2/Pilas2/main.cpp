#include <iostream>
#include<cstdlib>
#include "Nodo.h"
#include "Pila.h"
using namespace std;

void menu();

int main(){
    Pila pila;
    int x, op;

    do
    {
        menu();  
        cin >> op;
        switch (op)
        {
        case 1: 
            system("cls");
            cout << "Ingrese un numero: "<<endl; 
            cin >> x;
            pila.Apilar(x);
            cout << "\t Numero " << x << " apilado..." << endl;
            break;

        case 2:
            system("cls");
            if (pila.PilaVacia() == true)
                cout << "Pila Vacia...."<<endl;
            else {
                x = pila.Desapilar();
                cout << "Numero " << x << " desapilado"<<endl;
            }
            break;
        case 3:
            system("cls");
            cout << "**MOSTRANDO PILA**"<<endl;
            if (pila.PilaVacia() != true)
                pila.MostrarPila();
            else
                cout << "Pila vacia..!" << endl;
            break;
        case 4:
            system("cls");
            pila.Cima();
            break;  
        }
        cout << endl << endl;
        system("pause");  system("cls");

    } while (op != 5);
}

void menu()
{
    cout << "*****IMPLEMENTACION DE UNA PILA*****" << endl;
    cout << "1. APILAR (PUSH)" << endl;
    cout << "2. DESAPILAR (POP)" << endl;
    cout << "3. MOSTRAR PILA " << endl;
    cout << "4. MOSTRAR CIMA " << endl;
    cout << "5. SALIR" << endl;
    cout << "Ingrese una opcion: " << endl;
}
