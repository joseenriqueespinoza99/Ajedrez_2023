#include "ListaPiezas.h"
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

void ListaPiezas::dibuja()
{
	for (int i = 0; i < numero; i++)
		piezas[i]->dibuja();
}
/* void ListaPiezas::mueve(float f)
{
	for (int i = 0; i < numero; i++)
		piezas[i]->mueve(f);
}*/

void ListaPiezas::eliminar(Pieza* p)
{
	for (int i = 0; i < numero; i++)
		if (piezas[i] == p)
		{
			delete piezas[i];
			return;


		}
}
void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas 
		delete piezas[i];
	numero = 0; // inicializa lista 
}