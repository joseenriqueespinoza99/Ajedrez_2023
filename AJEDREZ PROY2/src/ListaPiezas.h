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

		void destruirContenido();

};

