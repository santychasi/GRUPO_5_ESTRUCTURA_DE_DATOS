/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA OBTENER EL MCD Y MCM DE DOS NUMEROS CON RECURSIVIDAD
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/19
* FECHA DE MODIFICACION: 2022/05/19
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include <iostream>
#include "MaximoComunDivisor.h"
#include "MinimoComunMultiplo.h"

using namespace std;

int main(){

    MaximoComunDivisor<int> objMax;
    MinimoComunMultiplo<int> ObjMin;

    int a = 0, b = 0;
    cout << "Ingrese el primer numero: " << endl;
    cin >> a;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> b;

    cout << "El maximo comun divisor de los dos numeros ingresados es: " << objMax.mcd(a,b) << endl;
    cout << "El minimo comun multiplo es: " << ObjMin.mcm(a,b) << endl;

    system("pause");
    return 0;
}