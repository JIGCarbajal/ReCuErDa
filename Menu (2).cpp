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

int Menu::principal(){ // Menú principal del programa

	int opc;
	cout << "====================================================" << endl;
	cout << "ReCuErDa" << endl;
	cout << "====================================================" << endl;
	cout << "Programa Para practicar los conceptos aprendidos" <<endl;
	cout << "Selecciona una acción:"<<endl;
	cout << "1.- Practicar!"<<endl;
	cout << "2.- Base de Problemas" << endl;
	cout << "0.- Salir"<<endl;
	cin >> opc;

	return opc;

}

void Menu::practicar(DataBase dB, string categoria){
	int num;
	cout << "Hay " << dB.buscaFinProblemas(categoria.c_str())-1 << " problemas de " << categoria.c_str() << endl;
	cout << "Ingrese el numero de problemas que quiere resolver" << endl;
	cin >> num;

	if(num > dB.buscaFinProblemas(categoria.c_str())-1 || num < 1){
		cerr << "Numero de problemas inconsistente" << endl;
		return; // mata el método
	}
	else{
		// Elige un vector de numeros aleatorios para el orden del problema
		bool usado[dB.buscaFinProblemas(categoria.c_str())]; // Verificador de número, para no repetir problema
		srand(time(NULL)); // inicializa la semilla de la funcion rand()

		for(int i = 0; i < dB.buscaFinProblemas(categoria.c_str()); i++) // inicializa los verificadores a falso
			usado[i] = false;

		int index = 0; // declara el numero aleatorio
		for(int i = 0; i < num; i++){
			do{ // Busca aleatoriamente un numero que no ha sido usado
				index = (rand() %(dB.buscaFinProblemas(categoria.c_str())-1)); // numero aleatorio entre 0 y num tot-1
			}while(usado[index]);
			usado[index] = true;
		}

		// Se preguntan los problemas de forma aleatoria
		int aciertos = 0;
		for(int i = 0; i < dB.buscaFinProblemas(categoria.c_str()); i++){
			if(usado[i])
			aciertos += dB.getProblem(categoria.c_str(), i+1);
		}

		cout << "tus aciertos fueron " << aciertos << " de " << num << endl;

	}// else
}

int Menu::baseDeProblemas(){ // Menú de la base de datos

	int opc;
	cout << "Selecciona una acción"<<endl;
	cout << "1.- Resolver Problema"<<endl;
	cout << "2.- Agregar Problema" << endl;
	cout << "3.- Eliminar Problema" << endl;
	cout << "0.- Volver al menú anterior"<<endl;
	cin >> opc;

	return opc;

}

string Menu::categoria(){ // Selecciona una categoria de problemas
	int opc;
	cout << "Selecciona una categoría" << endl;
	cout << "1.- Física" << endl;
	cout << "2.- Química" << endl;
	cout << "3.- Matemáticas" << endl;
	cin >> opc;

	switch(opc){
	case 1:
		return "./Problemas/Fisica";
	case 2:
		return "./Problemas/Quimica";
	case 3:
		return "./Problemas/Matematicas";
	default:
		return "0";
	}
}

bool Menu::resolverProblema(DataBase dB, string categoria){ // muestra el problema para resolverlo
	int opc;
	cout << "Hay " << dB.buscaFinProblemas(categoria.c_str())-1 << " problemas de " << categoria.c_str() << endl;
	cout << "introduce el problema que quieres resolver" << endl;
	cin >> opc;

	return dB.getProblem(categoria.c_str(),opc);
}

void Menu::agregarProblema(DataBase dB, string categoria){
	cout << "Hay " << dB.buscaFinProblemas(categoria.c_str())-1 << " problemas de " << categoria.c_str() << endl;
	cout << "Agregando problema numero " << dB.buscaFinProblemas(categoria.c_str()) << endl;
	dB.setProblem(categoria.c_str());
}

void Menu::eliminarProblema(DataBase dB, string categoria){
	int opc;
	cout << "Hay " << dB.buscaFinProblemas(categoria.c_str())-1 << " problemas de " << categoria.c_str() << endl;
	cout << "Introduce el numero del archivo a borrar:" << endl;
	cin >> opc;
	dB.eraseProblem(categoria.c_str(), opc);
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
