#include "Torre.h"

Torre::Torre(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza TORRE;
}

bool Torre::esmovimientoValido(int x_Destino, int y_Destino, int comer) {
	if (((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0)) || ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0)))
		return true;
	return false;
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
	}
	glutPostRedisplay;
}


