#pragma once
#include "Pieza.h"
#define MAX_PIEZAS 32

class ListaPiezas{
	private:
		int numero = 0; // El nuemro real de piezas existences en cada momento
		Pieza* piezas[MAX_PIEZAS]; // Vector de piezas de capacidad maxima 32

	public:
		ListaPiezas(); // Constructor

		int getNumero() { return numero; }
		Pieza* getPiezas(int i) { return piezas[i]; };

		bool agregar(Pieza* p); // Para a�adir nuevas piezas
		void eliminar(int index); // Eliminaci�n correcta ajustando el resto de piezas
		void eliminar(Pieza* p); // Eliminaci�n de la pieza indicada
		void destruirContenido(); // Destrucci�n controlada de las piezas 
		Pieza* getPieza(int fila, int columna); // Busca si en unas coordenadas hay una pieza y qu� pieza es
		void reemplazar(Pieza* piezaExistente, Pieza* nuevaPieza);  //Para la coronaci�n, intercambia una pieza por otra nueva
};


	
