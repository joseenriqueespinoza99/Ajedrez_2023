#pragma once
#include "Pieza.h"
#include "Coordenadas.h"
#define MAX_PIEZAS 32

class ListaPiezas
{
	private:
		int numero;
		Pieza* piezas[MAX_PIEZAS];
		Coordenadas coor;

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
		void getClass() {

		}

		void destruirContenido();
		int size() {
			return numero;
		}
		bool comprobar_trayectoria(int or_x, int or_y, int dest_x, int dest_y, int turno);

};

