/*
 * DataBase.cpp
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub
}

bool DataBase::getProblem(int numero){
	// Nombrando al archivo problema
	stringstream ss;
	ss << numero;
	string nombre = "problema" + ss.str() + ".txt";

	// Abriendo el archivo
	ifstream archivo(nombre.c_str(),ios::in);
	 if(archivo.fail()){
	    cerr << "Error al abrir el archivo " + nombre << endl;
	 }
	 else{
		 string buf;
		 char linea[128];
		 long contador = 0L;

		 while(!archivo.eof()){
			 archivo.getline(linea, sizeof(linea));
			 cout << linea << endl;
			 if((++contador % 24)==0){
				 cout << "CONTINUA...";
				 cin.ignore();
				 getline(cin,buf);
			 }

		 }
		 archivo.close();
		 getline(cin,buf);
	 }

	return true;

}

void DataBase::setProblem(){

	// Nombrando al archivo problema
		stringstream ss;
		ss << buscaFinProblemas();
		string nombre = "problema" + ss.str() + ".txt";


		// Abriendo el archivo
		ofstream nuevoArchivo(nombre.c_str());

		if(nuevoArchivo.fail()){
			cerr << "Error al crear el archivo " + nombre << endl;
		}
		else{
			bool introducir = true;
			char linea[128];
			while(introducir){
				cout << "Introducir nueva linea?" << endl;
				cout << "1.-Si" << endl;
				cout << "0.-No" << endl;
				cin >> introducir;

				if(introducir == 1 || introducir == 0){
				if(introducir){
					cin.ignore();
					cin.getline(linea, sizeof(linea));
					cin.ignore();
					nuevoArchivo << linea;
					nuevoArchivo << "\n";
				}
				}
				else
					introducir = 0;
			}

		}
		nuevoArchivo.close();
}


int DataBase::buscaFinProblemas(){

	stringstream ss;
	string nombre;

	int i = 1;
	for( bool fin = false; i <= 100; i++ ){
		ss << i;
		//cout << ss.str() << endl;
		nombre = "problema" + ss.str() + ".txt";
		ifstream archivo(nombre.c_str(),ios::in);
		if(archivo){
			// existe el archivo
			fin = false;
			archivo.close();
		}
		else{
			fin = true;
			break;
		}
		ss.str("");// para limpiar el ss
	}

	return i;

}

void DataBase::eraseProblem(int numero){

	if(numero <=0)
		cerr << "Numero de archivo no valido" << endl;
	else{
	stringstream ss;
	ss << buscaFinProblemas()-1;
	string nombre = "problema" + ss.str() + ".txt";

	// Se recorren todos los archivos al espacio que se quiere eliminar
	for(int i = numero; i < buscaFinProblemas()-1; i++)
		copyProblem(i);

    if( remove(nombre.c_str()) == 0)// Eliminamos el archivo
        cout << "El archivo fue eliminado satisfactoriamente" << endl;
    else
        cout << "No se pudo eliminar el archivo" << endl;
	}
}

void DataBase::copyProblem(int numero){

	stringstream ss1,ss2;
	ss1 << numero;
	ss2 << numero + 1;
	string siguiente = "problema" + ss2.str() + ".txt";
	string actual = "problema" + ss1.str() + ".txt";

	ifstream origen(siguiente.c_str());
	char linea[128];

	if(origen.fail())
		cerr << "Error al abrir el archivo Pruebas.txt" << endl;
	else{
		ofstream destino(actual.c_str());
	        if(destino.fail())
	        cerr << "Error al crear la copia del archivo" + actual << endl;
	        else
	        {
	            while(!origen.eof())
	            {
	                origen.getline(linea, sizeof(linea));
	                if(origen.good()) // si lectura ok y
	                if(origen.eof())  // si eof, -> termina
	                	break;
	                else
	                	destino << linea << endl;
	                if(destino.fail())
	                {
	                    cerr << "Fallo de escritura en archivo" << endl;
	                    break;
	                }
	            }
	        }
	        destino.close();
	    }
	    origen.close();

}


DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
}

