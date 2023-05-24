#include "caballo.h"
#include <math.h>

Caballo::Caballo(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza CABALLO;
}


void Caballo::dibuja() {
	if (color == true)
		pintar("imagenes/caballonegro.png", "imagenes/caballoblanco.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
	else
		pintar("imagenes/caballoblanco.png", "imagenes/caballonegro.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
}

bool Caballo::esmovimientoValido(int x_Destino, int y_Destino, bool 






) {
	//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
	if (fabs(x_Destino - getX()) == 1 && (fabs(y_Destino - getY()) == 2)) {
		return true;
	}
	//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
	else if (fabs(x_Destino - getX()) == 2 && (fabs(y_Destino - getY()) == 1)) {
		return true;
	}
	else return false;
}

void Caballo::mover(int x, int y, bool comer) {
	getX();
	getY();
	// Comprobar si el movimiento es válido para el alfil
	if (esmovimientoValido(x, y, comer)) {
		// Actualizar la posición del alfil a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}



