#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Reina {
	public:
		bool** validar;
		char** tablero;
		fstream archivo;
		int contador;
		int n;
		void encerarTablero();
		void crearArchivo();
		Reina(int);
		void bloquear(int,int);
		void mostrar();
		void quitarRelleno(int,int);
		void solucion(int,int,int);
		void solucionReinas();
};
