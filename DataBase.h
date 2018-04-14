/*
 * DataBase.h
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class DataBase {
public:
	DataBase();
	bool getProblem(int numero);// Plantea el problema y Califica
	void setProblem(); // Añade un nuevo problema al archivo
	void eraseProblem(int numero); // eliminar un problema del archivo
	int buscaFinProblemas(); // busca entre todos los archivos el último
	virtual ~DataBase();

private:
	void copyProblem(int numero);// Copia un problema

};

#endif /* DATABASE_H_ */
