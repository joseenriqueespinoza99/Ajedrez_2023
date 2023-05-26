#include "Alfil.h"

Alfil :: Alfil(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza ALFIL;
}

void Alfil::dibuja() {
	if (getModo() == false) {
		if (color == true)
			pintar("imagenes/alfilnegro.png", "imagenes/alfilblanco.png", "imagenes/alfilnblanco.png", "imagenes/alfilnnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/alfilblanco.png", "imagenes/alfilnegro.png", "imagenes/alfilnnegro.png", "imagenes/alfilnblanco.png", getX(), getY() + 1);
	}
	else {
		if (color == true)
			pintar("imagenes/clasicas/clasalfilnegro.png", "imagenes/clasicas/clasalfilblanco.png", "imagenes/clasicas/clasalfilnblanco.png", "imagenes/clasicas/clasalfilnnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/clasalfilblanco.png", "imagenes/clasicas/clasalfilnegro.png", "imagenes/clasicas/clasalfilnnegro.png", "imagenes/clasicas/clasalfilnblanco.png", getX(), getY() + 1);
	}
}

// Método para comprobar si el movimiento del alfil es válido
bool Alfil::esmovimientoValido(int x_Destino, int y_Destino, int comer) {
	// Un alfil se mueve en diagonal, por lo que el movimiento es válido si la distancia en filas y columnas es la misma
	int distanciaX = abs(x_Destino - getX());
	int distanciaY = abs(y_Destino - getY());
	if (distanciaX == distanciaY) {

		return true;

	}
	else
		return false;
}

void Alfil::mover(int x, int y, int comer) {
	getX();
	getY();
	// Comprobar si el movimiento es válido para el alfil
	if(esmovimientoValido(x,y, comer)){
		// Actualizar la posición del alfil a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}



