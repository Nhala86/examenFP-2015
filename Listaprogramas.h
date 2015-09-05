#ifndef LISTAPROGRAMAS_H
#define LISTAPROGRAMAS_H

#include"Programa.h"

const int MAX_COMPONENTES = 20;
const string FICHERO = "programas.txt";

//typedef tPrograma* tPrograma ;

typedef struct{
	tPrograma* programa[MAX_COMPONENTES];
	int contador;
}tListaProgramas;

void inicializarListaProgramas(tListaProgramas & listaProgramas);

bool insertar(tListaProgramas & listaProgramas, int pos, tPrograma & programa);

bool busquedaPrograma(tListaProgramas & listaProgramas, int & pos, string nombre);

void cargar(tListaProgramas & listaProgramas, tPrograma & programa);

tPrograma selecPrograma(tListaProgramas & listaProgramas);

void destruir(tListaProgramas & listaProgramas);



#endif