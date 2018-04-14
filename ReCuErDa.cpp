//============================================================================
// Name        : ReCuErDa.cpp
// Author      : José Isaac González Carbajal
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Menu.h"
#include "DataBase.h"
using namespace std;

int main() {
	Menu menu; // Instancia de la clase Menu
	DataBase dB;// Instancia de la base de Problemas

	int opc1, opc2;
	int opc;
	string buf;

	do{
		opc1 = menu.principal();

		switch(opc1){

		case 2:{
			do{
				opc2 = menu.baseDeProblemas();
				switch(opc2){

				case 1:// Mostrar/Ver problemas
					cout << "Hay " << dB.buscaFinProblemas()-1 << " problemas" << endl;
					cout << "introduce el problema que quieres ver" << endl;
					cin >> opc;
					cout << dB.getProblem(opc) << endl;
					break;
				case 2:// Agregar Problemas
					cout << "Hay " << dB.buscaFinProblemas()-1 << " problemas" << endl;
					cout << "Agregando problema numero " << dB.buscaFinProblemas() << endl;
					dB.setProblem();
					break;
				case 3:// Eliminar Problemas
					cout << "Hay " << dB.buscaFinProblemas()-1 << " problemas" << endl;
					cout << "Introduce el numero del archivo a borrar:" << endl;
					cin >> opc;
					dB.eraseProblem(opc);
					break;
				case 0:
					break;
				default:
					cout << "opcion invalida" << endl;
				}
			}while(opc2 != 0);
			break;
		}
		case 0:
			break;
		default:
			cout << "Opcion inválida" << endl;
			cin.ignore();// ignora el enter de cuando ingresamos opc
			getline(cin,buf); // captura el enter para continuar con la ejecucion

		}


	}while(opc1 != 0);

	return 0;
}
