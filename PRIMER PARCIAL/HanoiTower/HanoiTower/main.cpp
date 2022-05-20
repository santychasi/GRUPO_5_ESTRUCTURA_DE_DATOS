/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* PROGRAMA PARA REALIZAR LA TORRE DE HANOI CON RECURSIVIDAD
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/19
* FECHA DE MODIFICACION: 2022/05/19
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include <iostream>
#include "TorreHanoi.h"
using namespace std;

int main(){
    
    TorreHanoi<char> objHanoi;

    int num;

    cout << "Digite el numero de discos: " << endl;
    cin >> num;
    objHanoi.torreDeHanoi(num,'1','2','3');

    system("pause");
    return 0;
}

