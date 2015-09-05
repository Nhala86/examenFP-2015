
#include"Listaprogramas.h"

void inicializarListaProgramas(tListaProgramas & listaProgramas){
	for(int i = 0; i < listaProgramas.contador; i++){
		listaProgramas.programa[i] = nullptr;
	}
	listaProgramas.contador = 0;
}

bool insertar(tListaProgramas & listaProgramas, int pos, tPrograma & programa){
	bool esInsertado = false;
	while(listaProgramas.contador < MAX_COMPONENTES & !esInsertado){
		for(int i = listaProgramas.contador; i > pos; i--){
			listaProgramas.programa[i] = listaProgramas.programa[i - 1];		
		}
		listaProgramas.programa[pos] = new tPrograma(programa);
		listaProgramas.contador++;
		esInsertado = true;
	}
	return esInsertado;
}

bool busquedaPrograma(tListaProgramas & listaProgramas, int & pos, string nombre){
	int ini = 0, fin = listaProgramas.contador - 1, mitad;
	bool Ok = false;
	while((ini <= fin) && !Ok){
		mitad = (ini + fin) / 2;
		if(listaProgramas.programa[mitad]->nombre < nombre){
			fin = mitad + 1;
		}
		else if(nombre < listaProgramas.programa[mitad]->nombre){
			ini = mitad - 1;
		}
		else Ok = true;
	}
	if(Ok) pos = mitad;
	else pos = ini;
	return Ok;
}

void cargar(tListaProgramas & listaProgramas){
	tPrograma programa;
	int pos;
	ifstream archivo;
	archivo.open(FICHERO);	
	inicializarListaProgramas(listaProgramas);
	if(archivo.is_open()){
		if(cargar(archivo, programa)){
			while(!busquedaPrograma(listaProgramas, pos, programa.nombre)){
				insertar(listaProgramas, pos);
			}
		}
		else cout << "Error!! No se ha cargado el programa" << endl;		
	}
	else cout << "No se ha podido abrir el archivo" << endl;
	archivo.close();
}

tPrograma selecPrograma(tListaProgramas & listaProgramas){
	int opcion = 0;
	for(int i = 0; i < listaProgramas.contador; i++){
		cout << i << ".- ";
		mostrar(*listaProgramas.programa[i]);
		cout << endl;
	}
	cout << " Selcciona un programa: ";
	cin >> opcion;
	return *listaProgramas.programa[opcion];
}

void destruir(tListaProgramas & listaProgramas){
	for(int i = 0; i < listaProgramas.contador; i++){
		delete listaProgramas.programa[i];
	}
}
