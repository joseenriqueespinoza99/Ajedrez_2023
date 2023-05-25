#include "Torre.h"

Torre::Torre(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza TORRE;
}

bool Torre::esmovimientoValido(int x_Destino, int y_Destino, int comer) {
	if (comer == 4) {
		if (((x_Destino - getX()) == -2) && (getMov() == 0)) { // Se puede hacer enroque si estaba en la posicion inicial
			return 1;
		}
	}
	else if (comer == 5) {
		if (((x_Destino - getX()) == 3) && (getMov() == 0)) { // Se puede hacer enroque si estaba en la posicion inicial
			return 1;
		}
	}
	else {
		if (((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0)) || ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0)))
			return true;
		else return false;
	}
}


void Torre::dibuja() {
	if (color == true) 
		pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getX(), getY()+1);
	else 
		pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getX(), getY()+1);
}

void Torre::mover(int x, int y, int comer)
{
	if (esmovimientoValido(x, y, comer)) {
		// Actualizar la posición del alfil a la celda de destino
		setX(x);
		setY(y);
		setMov();
	}
	glutPostRedisplay;
}


