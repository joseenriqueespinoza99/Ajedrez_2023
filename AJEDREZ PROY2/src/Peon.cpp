#include "Peon.h"


Peon::Peon(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza PEON;
}
void Peon::mueve(unsigned char key) {}

// Método para comprobar si el movimiento del peon es válido
bool Peon::esmovimientoValido(int x_Destino, int y_Destino) {
	if (abs(x_Destino - getX()) == 0) {
		if ((color == 1) && (y_Destino - getY()) == 1) {
			return 1;
		}
		else if ((color == 0) && (y_Destino - getY()) == -1) {
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

void Peon::dibuja() {
	if (color == true)
		pintar("imagenes/peonnegro.png", "imagenes/peonblanco.png", "imagenes/peonnblanco.png", "imagenes/peonnnegro.png", getX(), getY() + 1);
	else
		pintar("imagenes/peonblanco.png", "imagenes/peonnegro.png", "imagenes/peonnnegro.png", "imagenes/peonnblanco.png", getX(), getY() + 1);
}

void Peon::mover(int x, int y) {
	getX();
	getY();
	// Comprobar si el movimiento es válido 
	if (esmovimientoValido(x, y)) {
		// Actualizar la posición del rey a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}