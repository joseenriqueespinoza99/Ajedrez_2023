#include "Alfil.h"
#include "Pieza.h"
#include "freeglut.h"
#include <iostream>
Alfil :: Alfil(int x, int y, bool color) {
	this->posx = x;
	this->posy = y;
	this->color = color;
	
}

void Alfil::move(int i, int j) {
	this->posx = i;
	this->posy = j;
}

// Método para comprobar si el movimiento del alfil es válido
bool Alfil:: movimientoValido(int x_Destino, int y_Destino) const {
	// Un alfil se mueve en diagonal, por lo que el movimiento es válido si la distancia en filas y columnas es la misma
	int distanciaFilas = abs(x_Destino - posx);
	int distanciaColumnas = abs(y_Destino -posy);
	return (distanciaFilas == distanciaColumnas);
}