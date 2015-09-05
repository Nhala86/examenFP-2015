
#include"Grabaciones.h"
#include"Listaprogramas.h"


int menu(int & opcion);

int main(){
	tListaGrabaciones listaGrabaciones;
	tListaProgramas listaProgramas;
	int opcion;
	
	cargar(listaProgramas);
	crear(listaGrabaciones);
	do{
		opcion = menu(opcion);
		switch(opcion){
			case 1:
				selecPrograma(listaProgramas);
				if(insertar(listaGrabaciones, listaGrabaciones.grabacion[listaGrabaciones.contador])){
					cout << "La grabacion se ha programado correctamente" << endl;
				}
				else cout << "Error!! No se ha podido programar" << endl;
				break;
			case 2:
				mostrar(listaGrabaciones);
				system("pause");
				break;
			case 3:
				destruir(listaGrabaciones);
				break;
		}
	}while(opcion > 0 && opcion < 4);	
	system("pause");
	return 0;
}


int menu(int & opcion){
	do{
		cout << "Elige una opcion: " << endl;
		cout << " 1.- Programar una grabacion nueva." << endl;
		cout << " 2.- Mostrar las grabaciones programadas hasta ahora." << endl;
		cout << " 3.- Salir." << endl;
		cin >> opcion;
	}while(opcion > 0 && opcion < 4);
	return opcion;
}