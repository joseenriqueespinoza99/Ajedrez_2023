#include "Rey.h"

Rey::Rey(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza REY;
}

void Rey::dibuja() {
	if (color == true)
		pintar("imagenes/reynegro.png", "imagenes/reyblanco.png", "imagenes/reynblanco.png", "imagenes/reynnegro.png", getX(), getY() + 1);
	else
		pintar("imagenes/reyblanco.png", "imagenes/reynegro.png", "imagenes/reynnegro.png", "imagenes/reynblanco.png", getX(), getY() + 1);
}

// M�todo para comprobar si el movimiento del rey es v�lido
bool Rey::esmovimientoValido(int x_Destino, int y_Destino, bool comer) {
	// El rey se puede mover 1 casilla a su alrededor
	if (abs(x_Destino - getX()) == 1 && abs(y_Destino - getY()) == 0)
		return 1;
	else if (abs(x_Destino - getX()) == 1 && abs(y_Destino - getY()) == 1)
		return 1;
	else if (abs(x_Destino - getX()) == 0 && abs(y_Destino - getY()) == 1)
		return 1;
	else { 
		return 0;
	}
}

void Rey::mover(int x, int y, bool comer) {
	getX();
	getY();
	// Comprobar si el movimiento es v�lido 
	if (esmovimientoValido(x, y, comer)) {
		// Actualizar la posici�n del rey a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}