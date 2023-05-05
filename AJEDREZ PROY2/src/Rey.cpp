#include "Rey.h"


Rey::Rey(int x, int y, bool color) {
	this->posx = x;
	this->posy = y;
	this->color = color;
	TipoPieza REY;
}

// M�todo para comprobar si el movimiento del rey es v�lido
bool Rey::esmovimientoValido(int x_Destino, int y_Destino) {
	// Le rey se puede mover 1 casilla a su alrededor
	if (abs(x_Destino - posx) == 1 || abs(y_Destino - posy)==1)
		return 1;
	else { return 0; }
}

void Rey::dibuja() {
	if (color == true)
		pintar("imagenes/reynegro.png", "imagenes/reyblanco.png", "imagenes/reynblanco.png", "imagenes/reynnegro.png", getX(), getY() + 1);
	else
		pintar("imagenes/reyblanco.png", "imagenes/reynegro.png", "imagenes/reynnegro.png", "imagenes/reynblanco.png", getX(), getY() + 1);
}

void Rey::mover(int x, int y) {
	getX();
	getY();
	// Comprobar si el movimiento es v�lido 
	if (esmovimientoValido(x, y)) {
		// Actualizar la posici�n del rey a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}