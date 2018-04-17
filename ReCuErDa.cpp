//============================================================================
// Name        : ReCuErDa.cpp
// Author      : José Isaac González Carbajal
// Version     : 1.0
// Description : Program to practice the concepts of physics, chemistry and
// 				 Mathematics
//============================================================================

#include <iostream>
#include "Menu.h"
#include "DataBase.h"
using namespace std;

int main() {
	Menu menu; // Instancia de la clase Menu
	DataBase dB;// Instancia de la base de Problemas

	int opc1, opc2; // opciones para los menús
	string buf;		// variable para meter "basura"

	do{
		opc1 = menu.principal(); // Menú Principal
		switch(opc1){ // opciones del menú principal

		case 1:{ // Practicar!
			menu.practicar(dB,menu.categoria());
			break;
		}
		case 2:{ // Operaciones en la base de datos
			do{
				opc2 = menu.baseDeProblemas(); // Menú de la base de datos de problemas
				switch(opc2){ // opciones del menú de datos

				case 1:// Resolver problemas
					if(menu.resolverProblema(dB, menu.categoria()))
						cout << "Correcto" << endl;
					else
						cout << "Incorrecto" << endl;
					break;
				case 2:// Agregar Problemas
					menu.agregarProblema(dB, menu.categoria());
					break;
				case 3:// Eliminar Problemas
					menu.eliminarProblema(dB, menu.categoria());
					break;
				case 0:
					break;
				default:
					cout << "opcion invalida" << endl;
				}
			}while(opc2 != 0);
			break;
		}
		case 0: // Salir
			break;
		default:
			cout << "Opcion inválida" << endl;
			cin.ignore();// ignora el enter de cuando ingresamos opc
			getline(cin,buf); // captura el enter para continuar con la ejecucion

		}

	}while(opc1 != 0); // mientras no se presione salir

	return 0;
}
