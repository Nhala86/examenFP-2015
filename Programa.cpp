
#include"Programa.h"

bool cargar(ifstream & archivo, tPrograma & programa){
	bool esCargado = false;
	char a;
	getline(archivo, programa.nombre);
	if(programa.nombre != CENTINELA){
		archivo >> programa.fecha;
		archivo >> programa.minutos;
		cin.get(a);
		esCargado = true;
	}
	return esCargado;
}

void mostrar(const tPrograma & programa){
	cout << programa.nombre << " . " << setw(5) << mostrarFecha(programa.fecha) << " . " << setw(5) << "Duracion " << programa.minutos << " minutos" << endl;
}

string mostrarFecha(tFecha fecha){
	stringstream resultado; tm ltm;
	localtime_s(&ltm, &fecha);
	resultado << ltm.tm_mday << " / " << 1 + ltm.tm_mon << " / " << 1900 + ltm.tm_year;
	return resultado.str();
}