/*
 * Menu.cpp
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#include "Menu.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub
}

int Menu::principal(){

	int opc;

	cout << "====================================================" << endl;
	cout << "ReCuErDa" << endl;
	cout << "====================================================" << endl;
	cout << "Programa Para practicar los conceptos aprendidos" <<endl;
	cout << "Selecciona una accion:"<<endl;
	cout << "1.- Practicar!"<<endl;
	cout << "2.- Base de Problemas" << endl;
	cout << "0.- Salir"<<endl;

	cin >> opc;

	return opc;

}

int Menu::baseDeProblemas(){

	int opc;

	cout << "Selecciona una acción"<<endl;
	cout << "1.- Ver Problemas"<<endl;
	cout << "2.- Agregar Problemas" << endl;
	cout << "3.- Eliminar Problemas" << endl;
	cout << "0.- Salir"<<endl;

	cin >> opc;

	return opc;

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

