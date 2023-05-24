#include "Dama.h"

Dama::Dama(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza REINA;
}


void Dama::dibuja() {
	if (color == true)
		pintar("imagenes/damanegra.png", "imagenes/damablanca.png", "imagenes/damanblanca.png", "imagenes/damannegra.png", getX(), getY() + 1);
	else
		pintar("imagenes/damablanca.png", "imagenes/damanegra.png", "imagenes/damannegra.png", "imagenes/damanblanca.png", getX(), getY() + 1);
}

// Método para comprobar si el movimiento del alfil es válido
bool Dama::esmovimientoValido(int x_Destino, int y_Destino, int comer) {
	// Un alfil se mueve en diagonal, por lo que el movimiento es válido si la distancia en filas y columnas es la misma
	if (fabs(getX() - x_Destino) == fabs(getY() - y_Destino))
		return true;
	if ((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0))
		return true;
	if ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0))
		return true;
	return false;
}

void Dama::mover(int x, int y, int comer) {
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



