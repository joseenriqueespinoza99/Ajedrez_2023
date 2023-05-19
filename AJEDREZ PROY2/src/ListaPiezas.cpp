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
				// Mover la última pieza de la lista a la posición eliminada
				piezas[i] = piezas[numero - 1];
				piezas[numero - 1] = nullptr;
				numero--;
			return;
		}
	}

}
void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas 
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

 bool ListaPiezas::comprobar_trayectoria(int or_x, int or_y, int dest_x, int dest_y, int turno) {

	 //obtenemos las coordenadas actuales de la clase Coordenadas	
	 or_x = coor.getX();
	 or_y = coor.getY();

	 //sacamos la x y la y siguiente mediante un doble bucle anidado
	 for (int i = 0; i < 32; i++) {
		 dest_x = (piezas[i]->getX());
		 for (int j = 0; j < 32; j++) {
			 dest_y = (piezas[j]->getY());
			 //ahora particularizamos la trayectoria para cada pieza
			 for (int k = 0; k < 32; k++) {
				 //alfil, solo en diagonal
				 if ((k < 4) && ((dest_x - dest_y) == (or_x - or_y))) {
					 return true;
				 }
				 //torre, solo en horizontal o vertical 
				 else if ((3 < k < 8) && ((or_x - dest_x == 0 && or_y - dest_y != 0)) || ((or_x - dest_x != 0) && (or_y - dest_y == 0))) {
					 return true;
				 }
				 //dama, una mezcla de ambas
				 else if ((13 < k < 16) && (((or_x - dest_x == 0 && or_y - dest_y != 0)) || ((or_x - dest_x != 0) && (or_y - dest_y == 0)) || ((dest_x - dest_y) == (or_x - or_y)))) {
					 return true;
				 }
				 //ninguna otra pieza es necesaria
				 else {
					 return false;
				 }

			 }

		 }
	 }
 }
 