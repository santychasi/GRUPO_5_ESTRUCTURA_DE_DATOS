#include <iostream>
#include "Lista.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char *ingreso(char *);

char *ingreso(char *msj){
	char dato[5];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}
// comentario gggg

int main(int argc, char** argv) {
	/*Lista lst;
	lst.insertar(1);
	lst.insertar(2);
	lst.insertar(3);
	lst.insertar(4);
	lst.insertar(5);
	lst.insertar(6);
	lst.mostrar();
	*/
	int valor;
	char datos[5];
	strcpy(datos,ingreso("Ingrese el datos entero"));
	valor=atoi(datos);
	printf("\n\t%d -->",valor);
	return 0;
}
