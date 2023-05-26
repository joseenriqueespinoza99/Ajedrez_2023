#include "caballo.h"
#include <math.h>

Caballo::Caballo(int x, int y, bool color) { //Constructor
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza CABALLO;
}


void Caballo::dibuja() {// Para dibujar los caballos
	if (getModo() == false) { // Se usan estas imagenes (tematicas) de forma general
		if (color == true)
			pintar("imagenes/caballonegro.png", "imagenes/caballoblanco.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
		else
			pintar("imagenes/caballoblanco.png", "imagenes/caballonegro.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
	}
	else {// Si se quiere utilizar el ajedrez clásico se ponen estas imágenes
		if (color == true)
			pintar("imagenes/clasicas/clascaballonegro.png", "imagenes/clasicas/clascaballoblanco.png", "imagenes/clasicas/clascaballonnegro.png", "imagenes/clasicas/clascaballonblanco.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/clascaballoblanco.png", "imagenes/clasicas/clascaballonegro.png", "imagenes/clasicas/clascaballonnegro.png", "imagenes/clasicas/clascaballonblanco.png", getX(), getY() + 1);

	}
}

bool Caballo::esmovimientoValido(int x_Destino, int y_Destino, int comer) { // Método para comprobar si el movimiento del peon es válido
	if (fabs(x_Destino - getX()) == 1 && (fabs(y_Destino - getY()) == 2)) { //si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
		return true;
	}
	else if (fabs(x_Destino - getX()) == 2 && (fabs(y_Destino - getY()) == 1)) { //si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
		return true;
	}
	else return false;
}

void Caballo::mover(int x, int y, int comer) { // Para actualizar la posicion del caballo
	getX();
	getY();
	if (esmovimientoValido(x, y, comer)) {// Comprobar si el movimiento es válido para el caballo
		// Actualizar la posición del caballo a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}



