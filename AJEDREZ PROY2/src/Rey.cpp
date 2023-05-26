#include "Rey.h"

Rey::Rey(int x, int y, bool color) { //Constructor
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza REY;
}

void Rey::dibuja() { // Para dibujar los reyes
	if (getModo() == false) { // Se usan estas imagenes (tematicas) de forma general
		if (color == true)
			pintar("imagenes/reynegro.png", "imagenes/reyblanco.png", "imagenes/reynblanco.png", "imagenes/reynnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/reyblanco.png", "imagenes/reynegro.png", "imagenes/reynnegro.png", "imagenes/reynblanco.png", getX(), getY() + 1);
	}
	else {// Si se quiere utilizar el ajedrez clásico se ponen estas imágenes
		if (color == true)
			pintar("imagenes/clasicas/clasreynegro.png", "imagenes/clasicas/clasreyblanco.png", "imagenes/clasicas/clasreynblanco.png", "imagenes/clasicas/clasreynnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/clasreyblanco.png", "imagenes/clasicas/clasreynegro.png", "imagenes/clasicas/clasreynnegro.png", "imagenes/clasicas/clasreynblanco.png", getX(), getY() + 1);
	}
	
}

bool Rey::esmovimientoValido(int x_Destino, int y_Destino, int comer) { // Método para comprobar si el movimiento del rey es válido
	if (comer == 4) { // Solo para enroque
		if (((x_Destino - getX()) == 2) && (getMov() == 0)) { // Se puede hacer enroque corto si estaba en la posicion inicial y se tiene que desplazar dos casillas a la derecha
			return 1;
		}
	}
	else if (comer == 5) {// Solo para enroque
		if (((x_Destino - getX()) == -2) && (getMov() == 0)) { // Se puede hacer enroque largo si estaba en la posicion inicial y se tiene que desplazar dos casillas a la izquierda
			return 1;
			return 1;
		}
	}
	else {
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
}

void Rey::mover(int x, int y, int comer) { // Para actualizar la posicion del rey
	getX();
	getY();
	if (esmovimientoValido(x, y, comer)) { // Comprobar si el movimiento es válido 
		// Actualizar la posición del rey a la celda de destino
		setX(x);
		setY(y);
		setMov(); // Al cambiar de posición se suma 1 a movimientos (para controlar el enroque)
	}
	glutPostRedisplay;
}