#include "Torre.h"


Torre::Torre(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza TORRE;
}


void Torre::mueve(unsigned char key) 
{
	int i = getX();
	int j = getY();
	if (key == 'a')
	{
		i--;
	}
	if (key == 'd')
	{
		i++;
	}
	if (key == 'w')
	{
		j++;
	}
	if (key == 's')
	{
		j--;
	}
	setX(i);
	setY(j);
	glutPostRedisplay;
}

void Torre::dibuja() {
			if (color == true) {
				pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getX(), getY()+1);
				casilla_torre = true;
			}
			else {
				pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getX(), getY()+1);
				casilla_torre = true;
			}
}

void Torre::mover(int x, int y)
{
	if (esmovimientoValido(x, y)) {
		// Actualizar la posición del alfil a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}

bool Torre::esmovimientoValido(int x_Destino, int y_Destino) {
	if (((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0)) || ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0)))
		return true;
	return false;
}
