#include<iostream>
#include "Pila.h"
#include "Nodo.h"

using namespace std;

Pila::Pila(){
	cima = NULL;
}

bool Pila::PilaVacia(){
    if (cima == NULL)
        return true;
    else
        return false;
}

void Pila::Apilar(int x){
    nodo nodito;
    nodito = new(class Nodo);
    nodito->nro = x;
    nodito->siguiente = cima;
    cima = nodito;
}

void Pila::Cima(){
    int x;
    if (cima == NULL)
        cout << "Pila Vacia...!" << endl;

    else {
        x = cima->nro;
        cout << "La Cima es :" << x << endl;
    }
}

int Pila::Desapilar(){
    int x;
    nodo nodito;
    if (cima == NULL)
        cout << "Pila Vacia !!"<<endl;
    else {
        nodito = cima;
        x = nodito->nro;
        cima = cima->siguiente;
        delete(nodito);
    }
    return x;
}

void Pila::MostrarPila(){
    nodo nodito;
    nodito = cima;

    while (nodito != NULL) {
        cout << "\t " << nodito->nro << endl;
        nodito = nodito->siguiente;
    }
}






















