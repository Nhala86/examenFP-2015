#ifndef PROGRAMA_H
#define PROGRAMA_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>
#include<ctime>
using namespace std;

const string CENTINELA = "XXX";

typedef time_t tFecha;

typedef struct{
	string nombre;
	tFecha fecha;
	int minutos;
}tPrograma;

bool cargar(ifstream & archivo, tPrograma & programa);

void mostrar(const tPrograma & programa);

string mostrarFecha(tFecha fecha);

#endif