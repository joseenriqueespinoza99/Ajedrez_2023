#include <iostream>
#include "freeglut.h"
#include "caballo.h"
#include <math.h>

Caballo::Caballo(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza CABALLO;

}

bool Caballo::esmovimientoValido(int x_Destino, int y_Destino) {
	//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
	if (fabs(x_Destino - getX()) == 1 && (fabs(y_Destino - getY()) == 2)) {
		return true;
	}
	//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
	else if (fabs(x_Destino - getX()) == 2 && (fabs(y_Destino - getY()) == 1)) {
		return true;
	}
	else return false;
}

void Caballo::mover(int x, int y) {
	getX();
	getY();
	// Comprobar si el movimiento es válido para el alfil
	if (esmovimientoValido(x, y)) {
		// Actualizar la posición del alfil a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}

void Caballo::mueve(unsigned char key) {

}

Caballo::~Caballo() {

}

void Caballo::movaje(char p[2], char z) {
	int k = getX();
	int l = getY();
	if (p == "rd") {
		l = l + 2;
		if (z == 'a') {
			k++;
		}
		else if (z == 'd') {
			k--;
		}
	}
	else if (p == "ri") {
		l = l - 2;
		if (z == 'a') {
			k++;
		}
		else if (z == 'd') {
			k--;
		}
	}
	else if (p == "nd") {
		l++;
		if (z == 'a') {
			k = k + 2;
		}
		else if (z == 'd') {
			k = k - 2;
		}
	}
	else if (p == "ni") {
		l--;
		if (z == 'a') {
			k = k + 2;
		}
		else if (z == 'd') {
			k = k - 2;
		}
		setX(k);
		setY(l);
		glutPostRedisplay;
	}

}




void Caballo::dibuja() {
	if (color == true) {
		pintar("imagenes/caballonegro.png", "imagenes/caballoblanco.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
		casilla_cab = true;
	}
	else {
		pintar("imagenes/caballoblanco.png", "imagenes/caballonegro.png", "imagenes/caballonnegro.png", "imagenes/caballonblanco.png", getX(), getY() + 1);
		casilla_cab = true;
	}
}