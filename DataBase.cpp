/*
 * DataBase.cpp
 *
 *  Created on: 13/04/2018
 *      Author: isaac
 */

#include "DataBase.h"

DataBase::DataBase(){
	// TODO Auto-generated constructor stub
}

bool DataBase::getProblem(string categoria, int numero){
	// Declarando variables a usar
	string buf; // para atrapar las cadenas extra ingresadas por el usuario
	string opciones1[4]; // las respuestas ordenadas en el archivo
	string opcionesDesordenadas[4]; // las respuestas desordenadas
	int indice = 0; // cuenta cuantas respuestas se han extraido del archivo
	int correcto; // guarda el indice de la respuesta correcta en el arreglo desordenado

	// Nombrando al archivo problema
	stringstream ss;
	ss << numero;
	string nombre = categoria.c_str() + ss.str() + ".txt"; // nombre del archivo problema

	// Abriendo el archivo
	ifstream archivo(nombre.c_str(),ios::in); // abre el archivo en forma lextura
	 if(archivo.fail()){ // si no se puede abrir el archivo
	    cerr << "Error al abrir el archivo " + nombre << endl;
	    return false;
	 }
	 else{ // si se puede abrir
		 char linea[128]; // tamaño de la linea del archivo
		 long contador = 0L; // inicio del archivo

		 cout << "-----------------------" << endl;
		 cout << nombre << endl;
		 cout << "-----------------------" << endl;

		 // Solo muestra el enunciado del problema
		 bool enunciado = false; // indica si es o no el enunciado
		 while(!archivo.eof()){ // mientras no se recorra todo el archivo
			 archivo.getline(linea, sizeof(linea)); // extrae una linea de texto
			 if(linea[0] == '-'){ // si la linea es una linea punteada
				 enunciado = !enunciado; // Comienza o termina el enunciado
				 if(!enunciado){ // para poner la ultima linea ---
					 cout << linea << endl;
				 }
			 }
			 if(enunciado){ // si es el enunciado
				 cout << linea << endl; // imprime el texto en pantalla
				 if((++contador % 24)==0){ // de 24 lineas en 24 lineas
					 cout << "CONTINUA...";
					 cin.ignore();			// ignora el ENTER ingresado
					 getline(cin,buf);		// Captura un ENTER en buf
				 }
			 }
			 else // si no es el enunciado (Comienzan las respuestas)
				 if(indice < 4){ // mientras no sean 4 respuestas
					 if(linea[0] != '-'){ // y no es la punteada del fin del enunciado
						 opciones1[indice] = linea; // captura la linea de texto en las respuestas
					 	 indice ++; // y aumenta el contador
					 }
				 }
		 }
		 // se cierra el archivo del problema
		 archivo.close();

		 // Se Desordena el vector de los enunciados aleatoriamente

		 bool usado[4]; // Verificador de indice, para no repetir respuesta
		 srand(time(NULL)); // inicializa la semilla de la funcion rand()

		 for(int i = 0; i < 4; i++) // inicializa los verificadores a falso
			 usado[i] = false;

		 int index = 0; // declara el indice aleatorio
		 for(int i = 0; i < 4; i++){
			 do{ // Busca aleatoriamente un indice que no ha sido usado
				 index = (rand()%4); // numero aleatorio entre 0 y 3
			 }while(usado[index]);
			 if(index == 0) // si el indice es 0 guarda el indice i
				 correcto = i; // porque es la respuesta correcta
			 opcionesDesordenadas[i] = opciones1[index];
			 usado[index] = true;
			 }
		 }
	 //getline(cin,buf);

	 // Mostrar las opciones para contestar
	 int respuesta;
	 cout << "1.- "<< opcionesDesordenadas[0] << endl;
	 cout << "2.- "<< opcionesDesordenadas[1] << endl;
	 cout << "3.- "<< opcionesDesordenadas[2] << endl;
	 cout << "4.- "<< opcionesDesordenadas[3] << endl;
	 cin >> respuesta;

	 if(respuesta == correcto+1) // califica la respuesta
		 return true;
	return false;
}

void DataBase::setProblem(string categoria){

	// Nombrando al archivo problema
		stringstream ss;
		ss << buscaFinProblemas(categoria.c_str());
		string nombre = categoria.c_str() + ss.str() + ".txt"; // nombre del nuevo archivo (ultimo)


		// Abriendo el archivo
		ofstream nuevoArchivo(nombre.c_str()); // se abre el archivo en modo escritura

		if(nuevoArchivo.fail()){ // si no se puede abrir
			cerr << "Error al crear el archivo " + nombre << endl;
		}
		else{ // si se puede
			bool introducir = true; // Verificador de introduccion de linea nueva
			char linea[128]; // tamaño de la linea del archivo
			while(introducir){ // mientras se desee introducir una linea nueva
				cout << "Introducir nueva linea?" << endl;
				cout << "1.-Si" << endl;
				cout << "0.-No" << endl;
				cin >> introducir;

				if(introducir == 1 || introducir == 0){ // Si es SI o NO
					if(introducir){ // si es SI
						cin.ignore(); // ignora el enter de "cin >> introducir;"
						cin.getline(linea, sizeof(linea)); // Se captura la linea a introducir en el archivo
						//cin.ignore(); // se ignora un enter
						nuevoArchivo << linea; // se introduce la linea en el archivo
						nuevoArchivo << "\n"; // y se introduce un salto de linea
					}
				}
				else // Si no es SI o NO
					introducir = 0; // Se cambia a NO
			}

		}
		nuevoArchivo.close(); // se cierra el archivo nuevo
}

int DataBase::buscaFinProblemas(string categoria){

	stringstream ss; // para armar los nombres de los archivos
	string nombre; // nombres de los archivos problema

	int i = 1;
	bool fin = false;
	for(; i <= this -> maxProblems; i++ ){ // Desde 1 hasta maximo de problemas
		ss << i; // se le asigna el valor del indice a la variable ss
		nombre = categoria.c_str() + ss.str() + ".txt"; // Se arma el nombre problema
		ifstream archivo(nombre.c_str(),ios::in); // se intenta abrir el archivo en modo lectura
		if(archivo){
			// existe el archivo
			fin = false;
			archivo.close(); // Se cierra el archivo para poder abrir más
		}
		else{
			// No existe
			fin = true;
			archivo.close();
			break;
		}
		ss.str("");// para limpiar el ss y poder ingresar otro indice
	}

	return i; // Retorna el valor del archivo "que sigue" en la base de problemas

}

void DataBase::eraseProblem(string categoria, int numero){

	if(numero <=0) // si se intenta eliminar un archivo con nombre menor que 1
		cerr << "Numero de archivo no valido" << endl;
	else{
	stringstream ss;
	ss << buscaFinProblemas(categoria.c_str())-1; // Se inicia el valor de ss en el ultimo problema
	string nombre = categoria.c_str() + ss.str() + ".txt"; // nombre del ultimo problema

	// Se recorren todos los archivos al espacio que se quiere eliminar
	for(int i = numero; i < buscaFinProblemas(categoria.c_str())-1; i++)
		copyProblem(categoria.c_str(),i); // Copia el archivo i+1 al i

    if( remove(nombre.c_str()) == 0)// Eliminamos el ultimo archivo (que ahora está repetido)
        cout << "El archivo fue eliminado satisfactoriamente" << endl;
    else
        cout << "No se pudo eliminar el archivo" << endl;
	}
}

void DataBase::copyProblem(string categoria, int numero){

	stringstream ss1,ss2;
	ss1 << numero; // El archivo elegido (Actual)
	ss2 << numero + 1; // el archivo siguiente
	string siguiente = categoria.c_str() + ss2.str() + ".txt"; // nombre del archivo siguiente
	string actual = categoria.c_str() + ss1.str() + ".txt"; // nombre del archivo actual

	ifstream origen(siguiente.c_str()); // se abre el archivo siguiente en modo lectura
	char linea[128]; // tamaño de la linea en el archivo de texto

	if(origen.fail()) // si hay un error al abrir el archivo
		cerr << "Error al abrir el archivo Pruebas.txt" << endl;
	else{ // si se puede abrir
		ofstream destino(actual.c_str()); // se abre el archivo actual en modo sobreescribir
	        if(destino.fail()) // si no se puede abrir
	        cerr << "Error al crear la copia del archivo" + actual << endl;
	        else
	        { // si se puede abrir
	            while(!origen.eof()) // mientras no se termine el archivo siguiente
	            {
	                origen.getline(linea, sizeof(linea)); // se extrae una linea de texto
	                if(origen.good()) // si se pudo extraer la linea
	                if(origen.eof())  // y ya se terminó el texto
	                	break; // se rompe la estructura de control
	                else // si aun no se termina
	                	destino << linea << endl; // se copea la linea extraida en el archivo actual
	                if(destino.fail()) // si la escritura falló
	                {
	                    cerr << "Fallo de escritura en archivo" << endl;
	                    break; // se rompe el método
	                }
	            }
	        }
	        destino.close(); // se cierra el archivo actual
	    }
	    origen.close(); // se cierra el archivo siguiente
}

DataBase::~DataBase(){
	// TODO Auto-generated destructor stub
}

