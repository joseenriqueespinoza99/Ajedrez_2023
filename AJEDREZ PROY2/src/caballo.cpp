#include <iostream>
#include "freeglut.h"
#include "caballo.h"
#include <math.h>


using namespace std;



Caballo::Caballo(int xc, int yc, bool color) {
	xc = fila;
	yc = columna;
	color = Color;
}


Caballo::~Caballo() {

}

void Caballo::mueveCab(char p[2], char z) {
	int k = Getx();
	int l = Gety();
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
		setx(k);
		sety(l);
		glutPostRedisplay;
	}
	
	}

	bool Caballo::comprobacion(int x, int y) {
		//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
		if (fabs(x - fila) == 1 && (fabs(y - columna) == 2)) {
			return true;
		}
		//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
		else if (fabs(x - fila) == 2 && (fabs(y - columna) == 1)) {
			return true;
		}
		else return false;
	}

	
	void Caballo::dibujaCab() {
		caballo.setColor(true);
		if (caballo.getColor() == true) {
			caballo.pintar("imagenes/caballonegro.png", "imagenes/caballoblanco.png", "imagenes/caballon.png", "imagenes/caballonblanco.png", Getx() + 1, Gety() + 1);
			casilla_cab = true;
		}
		else {
			caballo.pintar("imagenes/caballoblanco.png", "imagenes/caballonegro.png", "imagenes/caballon.png", "imagenes/torrenblanca.png", Getx() + 1, Gety() + 1);
			casilla_cab = true;
		}
	}
	
			


