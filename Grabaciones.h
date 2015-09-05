#ifndef GRABACIONES_H
#define GRABACIONES_H

#include"Listaprogramas.h"

const int MAX_CAPACIDAD = 20;

typedef struct{
	tListaProgramas listaProgramas;
	bool grabado;	
}tGrabacion;

typedef struct{
	tGrabacion* grabacion;
	int contador;
}tListaGrabaciones;

void crear(tListaGrabaciones & listaGrabaciones);

bool solapan(const tGrabacion & grabacion1, tGrabacion & grabacion2);

bool insertar(tListaGrabaciones & listaGrabaciones, tGrabacion & grabacion);

void mostrar(const tListaGrabaciones & listaGrabaciones);

void destruir(tListaGrabaciones & listaGrabaciones);



#endif