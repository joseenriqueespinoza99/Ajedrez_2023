#include "ListaPiezas.h"
ListaPiezas lista;
ListaPiezas::ListaPiezas()
{
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		piezas[i] = 0;
}

bool ListaPiezas::agregar(Pieza* p) {
	if (numero < MAX_PIEZAS) {
		piezas[numero++] = p;
		return true;
	}
	else
		return false;
}

void ListaPiezas::eliminar(Pieza* p)
{
	for (int i = 0; i < numero; i++)
	{
		if (piezas[i] == p) {
			delete piezas[i];
				piezas[i] = nullptr;
				// Mover la �ltima pieza de la lista a la posici�n eliminada
				piezas[i] = piezas[numero - 1];
				piezas[numero - 1] = nullptr;
				numero--;
			return;
		}
	}

}
void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas 
		delete piezas[i];
	numero = 0; // inicializa lista 
}
 Pieza* ListaPiezas::getPieza(int fila, int columna) {
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getX() == fila && piezas[i]->getY() == columna) {
			return piezas[i];
		}
	}
	return nullptr;
}
 