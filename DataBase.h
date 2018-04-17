/*
 * DataBase.h
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <iostream>	// cin, cout, string
#include <fstream>	// ifstream, ofstream
#include <sstream>	// stringstream
#include <stdlib.h>	// rand()
#include <time.h>	// srand(time(NULL))
using namespace std;


class DataBase {
public:
	DataBase();
	bool getProblem(string categoria, int numero);// Plantea el problema y Califica
	void setProblem(string categoria); // Añade un nuevo problema a la base de problemas
	void eraseProblem(string categoria, int numero); // eliminar un problema del archivo
	int buscaFinProblemas(string categoria); // busca entre todos los archivos de la categoría el último
	virtual ~DataBase();

private:
	void copyProblem(string categoria, int numero);// Copia un problema
	int const maxProblems = 200; // numero maximo de problemas en la base de problemas
};

#endif /* DATABASE_H_ */
