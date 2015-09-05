
#include"Grabaciones.h"

void crear(tListaGrabaciones & listaGrabaciones){
	for(int i = 0; i < listaGrabaciones.contador; i++){
		listaGrabaciones.grabacion = new tGrabacion;
	}
	listaGrabaciones.contador = 0;
}

bool solapan(const tGrabacion & grabacion1, tGrabacion & grabacion2){
	bool esSolapado = false;
	return esSolapado;
}

bool insertar(tListaGrabaciones & listaGrabaciones, tGrabacion & grabacion){
	bool esInsertado = false;
	if(!solapan && !esInsertado){
		listaGrabaciones.grabacion[listaGrabaciones.contador] = grabacion;
		listaGrabaciones.contador++;
		esInsertado = true;
	}
	return esInsertado;
}

void mostrar(const tListaGrabaciones & listaGrabaciones){
	for (int i = 0; i < listaGrabaciones.contador; i++){
		if(!listaGrabaciones.grabacion[i].grabado){
			mostrar(listaGrabaciones.grabacion[i]->listaProgramas.programa[listaProgramas.contador]);
		}		
	}
}

void destruir(tListaGrabaciones & listaGrabaciones){
	for(int i = 0; i < listaGrabaciones.contador; i++){
		destruir(listaGrabaciones.grabacion[i].listaProgramas);
		delete[] listaGrabaciones.grabacion;
	}
}