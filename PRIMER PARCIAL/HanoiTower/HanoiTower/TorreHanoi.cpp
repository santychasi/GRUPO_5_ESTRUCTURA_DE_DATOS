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
#include<iostream>
#include "TorreHanoi.h"

using namespace std;

template <class T>
/**
 * Funcion para realizar los movimientos de la torre de Hanoi.
 * 
 * \param n
 * \param desde_torre
 * \param hacia_torre
 * \param aux
 */
void TorreHanoi<T>::torreDeHanoi(T n, T desde_torre,T hacia_torre,T aux){
	if (n == 0 ) {
		return;
	}
	torreDeHanoi(n-1,desde_torre,aux,hacia_torre);
	cout << "Mover el disco " << n << " desde la torre " << desde_torre << " hacia la torre " << hacia_torre << endl;
	torreDeHanoi(n-1,aux,hacia_torre,desde_torre);
}

template class TorreHanoi<char>;
