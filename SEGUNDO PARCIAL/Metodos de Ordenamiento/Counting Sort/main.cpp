#include<iostream>
#include<algorithm>
#include "Ordenar.h"
#include <string.h>
#include <windows.h>

HANDLE wHnd; // ventana de win

using namespace std;

int main(int argc, char** argv) {
	Ordenar objOrden;
	char dato[10];
	int n, opcion;
	/*
	vENTANA DE WINDOWS
	*/
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = {0, 0, 65, 25}; // 0,0,ancho, altura
	SetConsoleWindowInfo(wHnd, 1, &windowSize);

	int *arr = new int[n+1];//creamos el arreglo con new
	
	do{
		system("cls");
		system("color 70");
      	printf("\t\t===================================\n");
      	printf("\t\tMENU ORDENAMIENTO POR DISTRIBUCION\n");
      	printf("\t\t===================================\n");
      	printf("\t\t\t[1] Agregar\n");
      	printf("\t\t\t[2] Mostrar\n");
      	printf("\t\t\t[3] Salir\n");
      	printf("\t\t=================================\n");
      	strcpy(dato, objOrden.validarEntero("Seleccione una opcion [1-3]... "));
      	opcion = atoi(dato);
		printf("\t\t=================================\n");
      	system("cls");

      	switch(opcion){
      		case 1:
     			printf("\n==========================================================\n");
            	printf("OPCION 1: Agregar\n");
            	printf("==========================================================\n");
            	strcpy(dato, objOrden.validarEntero("Digite el tamano del vector: "));
				n = atoi(dato);
				//cout << "\nDigite los elementos:" << endl;
				for(int i = 1; i<=n; i++) {
				    strcpy(dato, objOrden.validarEntero("\nDigite los elementos:"));
					arr[i] = atoi(dato);
					//cin >> arr[i];
				}
		        cout<<"\n";
		        printf("==========================================================\n");
				system("pause");     			
      			break;
      		case 2:
      			printf("==========================================================\n");
            	printf("OPCION 2: Mostrar\n");
            	printf("==========================================================\n");
            	cout << "SIN ORDENAR: ";
				objOrden.mostrar(arr,n);
				objOrden.countingSort(arr,n);
				cout << "ORDENADO: ";
				objOrden.mostrar(arr,n);
		        cout<<"\n";
	        	printf("==========================================================\n");
            	system("pause");
      			break;
      		case 3:
      			printf("==========================================================\n");
            	printf("OPCION 3: REGRESE PRONTO...\n");
            	printf("==========================================================\n");
            	system("pause");
      			break;
		  }
	}while(opcion !=3);
}
