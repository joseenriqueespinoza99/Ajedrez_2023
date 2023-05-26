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

		bool agregar(Pieza* p); // Para añadir nuevas piezas
		void eliminar(int index); // Eliminación correcta ajustando el resto de piezas
		void eliminar(Pieza* p); // Eliminación de la pieza indicada
		void destruirContenido(); // Destrucción controlada de las piezas 
		Pieza* getPieza(int fila, int columna); // Busca si en unas coordenadas hay una pieza y qué pieza es
		void reemplazar(Pieza* piezaExistente, Pieza* nuevaPieza);  //Para la coronación, intercambia una pieza por otra nueva
	        void ListaPiezas::destruirContenido();//Eliminación o liberación del contenido de la lista de piezas. 
};


	
