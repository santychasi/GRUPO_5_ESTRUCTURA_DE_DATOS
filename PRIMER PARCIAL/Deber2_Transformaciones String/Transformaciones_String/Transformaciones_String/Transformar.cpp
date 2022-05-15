/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA INGRESAR UN STRING Y TRANSFORMAR A ENTERO
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/12
* FECHA DE MODIFICACION: 2022/05/12
* VERSION 2
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include "Transformar.h"

using namespace std;

int Transformar::transformarInt(string numero){
    int num;
    num = stoi(numero);
    return num;
}

float Transformar::transformarFloat(string numero){
    float num;
    num = stof(numero);
    return num;
}

char Transformar::transformarChar(string palabra){
    char* c = const_cast<char*>(palabra.c_str());
    return *c;
}


