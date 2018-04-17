/*
 * Menu.h
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include "DataBase.h"
using namespace std;

class Menu {
public:
	Menu();
	int principal();
	void practicar(DataBase dB, string categoria);
	int baseDeProblemas();
	string categoria();
	bool resolverProblema(DataBase dB, string categoria);
	void agregarProblema(DataBase dB, string categoria);
	void eliminarProblema(DataBase dB, string categoria);
	virtual ~Menu();
};

#endif /* MENU_H_ */
