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


Caballo::~Caballo() {

}

void Caballo::mover(char p[2], char z) {
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

	bool Caballo::comprobacion(int x, int y) {
		//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
		if (fabs(x - getX()) == 1 && (fabs(y - getY()) == 2)) {
			return true;
		}
		//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
		else if (fabs(x - getX()) == 2 && (fabs(y - getY()) == 1)) {
			return true;
		}
		else return false;
	}

	
	void Caballo::dibuja() {
		setColor(true);
		if (getColor() == true) {
			pintar("imagenes/caballonegro.png", "imagenes/caballoblanco.png", "imagenes/caballon.png", "imagenes/caballonblanco.png", getX() + 1, getY() + 1);
			casilla_cab = true;
		}
		else {
			pintar("imagenes/caballoblanco.png", "imagenes/caballonegro.png", "imagenes/caballon.png", "imagenes/torrenblanca.png", getX() + 1, getY() + 1);
			casilla_cab = true;
		}
	}
	
			


