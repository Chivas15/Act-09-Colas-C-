// Act-09-Colas-C++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<iostream>

using namespace std;
#define MaxtamC 10 // se define el tamaño maximo de cola 

typedef int Tipodato;

void ingresar_valores(int &frente, int &final, Tipodato A[], int &contador){
	if ((final + 1) % MaxtamC == frente) {
		cout << "Desbordamiento de la cola" << endl;
			return ;
	}

	cout << "Ingrese un elemento para la cola: ";
	Tipodato elemento;
	cin >> elemento;

	final = (final + 1) % MaxtamC;
	A[final] = elemento;
	
	contador++;
	cout << "Elemento " << contador << " agregado a la cola: " << elemento << endl;
}

void eliminar_elemento(int& frente, int final, int& contador) {
	if (frente == final) {
		cout << "La cola esta vacia, no se puede eliminar" << endl;
		return ;
	}
	frente = (frente + 1) % MaxtamC;
	contador--;
	cout << "Elemento eliminado de la cola." << endl;
}

void imprimir(int& frente, int& final, Tipodato A[]) {

	cout << "Elementos de la cola en el orden de ingreso:" << endl;
	for (int i = frente + 1; i <= final; i = (i + 1) % MaxtamC) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main() {
	Tipodato A[MaxtamC];
	int contador = 0;

	int frente = 0;
	int final = 0;
	
	cout << "Desea agregar elementos a la cola? (s/n): ";
	char respuesta;
	cin >> respuesta; 
	while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
		ingresar_valores(frente, final, A, contador);

		if (contador < 10) {
			cout << "Desea agregar mas elementos a la cola? (s/n): ";
			cin >> respuesta;
		}
	}
	if (frente == final) {
		cout << "La cola esta vacia." << endl;
		return 1;
	}
	Tipodato primerElmento = A[(frente + 1) % MaxtamC];
	cout << "El primer elemento de la cola es: " << primerElmento << endl;
	eliminar_elemento(frente, final, contador);
	imprimir(frente, final, A);

	return 0;
}
