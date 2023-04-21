#include "Alfil.h"
#include "Tablero.h"
Alfil ::Alfil(int x, int y, bool color) {
	this->x = x;
	this->y = y;
	this->color = color;
	
}

void Alfil::move(int i, int j) {
	this->x = i;
	this->y = j;
}

// M�todo para comprobar si el movimiento del alfil es v�lido
bool Alfil:: movimientoValido(int filaDestino, int columnaDestino) const {
	// Un alfil se mueve en diagonal, por lo que el movimiento es v�lido si la distancia en filas y columnas es la misma
	int distanciaFilas = abs(filaDestino - x);
	int distanciaColumnas = abs(columnaDestino -y);
	return (distanciaFilas == distanciaColumnas);
}