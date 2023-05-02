#pragma once
#include "Pieza.h"
#define MAX_PIEZAS 32

class ListaPiezas
{
	private:
		int numero;
		Pieza* piezas[MAX_PIEZAS];

	public:
		ListaPiezas();
		bool agregar(Pieza* p);
		void eliminar(Pieza* p);
		Pieza* getPiezas(int i){ return piezas[i]; };
		Pieza* getPieza(int fila, int columna);
		Pieza* getPiezass(int ind) {
			if (ind < 0 || ind >= size()) {
				// si el índice es inválido, retornar un puntero nulo
				return nullptr;
			}
			return piezas[ind]; // retornar el puntero a la pieza en el índice dado
		}
		bool buscarPieza(Pieza* pieza) const;
		void getClass() {

		}
	

		void destruirContenido();
		int size() {
			return numero;
		}

};

