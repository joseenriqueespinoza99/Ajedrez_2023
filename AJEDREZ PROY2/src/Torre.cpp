#include "Torre.h"

Torre::Torre(int x, int y, bool color) { //Constructor
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza TORRE;
}


void Torre::dibuja() { // Para dibujar las torres
	if (getModo() == false) { // Se usan estas imagenes (tematicas) de forma general
		if (color == true)
			pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getX(), getY() + 1);
		else
			pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getX(), getY() + 1);
	}
	else { // Si se quiere utilizar el ajedrez clásico se ponen estas imágenes
		if (color == true)
			pintar("imagenes/clasicas/clastorrenegra.png", "imagenes/clasicas/clastorreblanca.png", "imagenes/clasicas/clastorrenblanca.png", "imagenes/clasicas/clastorrennegra.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/clastorreblanca.png", "imagenes/clasicas/clastorrenegra.png", "imagenes/clasicas/clastorrennegra.png", "imagenes/clasicas/clastorrenblanca.png", getX(), getY() + 1);
	}
}

bool Torre::esmovimientoValido(int x_Destino, int y_Destino, int comer) { // Método para comprobar si el movimiento de la torre es válido
	if (comer == 4) { // Solo para enroque
		if (((x_Destino - getX()) == -2) && (getMov() == 0)) { // Se puede hacer enroque corto si estaba en la posicion inicial y se tiene que desplazar dos casillas a la izquierda
			return 1;
		}
	}
	else if (comer == 5) { // Solo para enroque
		if (((x_Destino - getX()) == 3) && (getMov() == 0)) { // Se puede hacer enroque largo si estaba en la posicion inicial y se tiene que desplazar tres casillas a la derecha
			return 1;
		}
	}
	else {
		if (((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0)) || ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0))) // La torre se puede mover en linea recta, en cualquier direccion
			return true;
		else return false;
	}
}

void Torre::mover(int x, int y, int comer) { // Para actualizar la posicion de la torre
	if (esmovimientoValido(x, y, comer)) { // Comprobar si el movimiento es válido 
		// Actualizar la posición de la torre a la celda de destino
		setX(x);
		setY(y);
		setMov(); // Al cambiar de posición se suma 1 a movimientos (para controlar el enroque)
	}
	glutPostRedisplay;
}


