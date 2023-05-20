#pragma once
#include "Pieza.h"
#define MAX_PIEZAS 32

class ListaPiezas
{
	private:
		int numero = 0;
		Pieza* piezas[MAX_PIEZAS];

	public:
		ListaPiezas();
		bool agregar(Pieza* p);
		void eliminar(int index);
		void eliminar(Pieza* p);
		void destruirContenido();
		Pieza* getPiezas(int i){ return piezas[i]; };
		Pieza* getPieza(int fila, int columna);
		int getNumero() { return numero; }
//funciona igual sin lo de abajo
		void dibuja();
		void mueve(float t);
		Pieza* operator [](int i);
		void choque();
		
};


	
