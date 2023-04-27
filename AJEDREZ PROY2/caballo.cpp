#include <iostream>
#include "freeglut.h"
#include "caballo.h"


using namespace std;

caballo Caballo;

caballo::~caballo() {

}

void caballo::mueveCab(char p[2], char z) {
	
	if (p == "rd") {
		columna = columna + 2;
		if (z == 'a') {
			fila++;		
		}
		else if (z == 'd') {
			fila--;
		}
	}
	else if (p == "ri") {
		columna = columna - 2;
		if (z == 'a') {
			fila++;
		}
		else if (z == 'd') {
			fila--;
		}
	}
	else if (p == "nd") {
		columna++;
		if (z == 'a') {
			fila = fila + 2;
		}
		else if (z == 'd') {
			fila = fila - 2;
		}
	}
	else if (p == "ni") {
		columna--;
		if (z == 'a') {
			fila = fila + 2;
		}
		else if (z == 'd') {
			fila = fila - 2;
		}
		setx(fila);
		sety(columna);
		glutPostRedisplay;
	}
	
	}
/*
		bool caballo::comprobacion(int x, int y) {
			//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
			//x =  posSig[0];
			//y = posSig[1];

			if ((x - fila) == 1 && ((y - columna) == 2)) {
				return true;
			}
			//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
			else if ((x - fila) == 2 && ((y - columna) == 1)) {
				return true;
			}
			else return false;
		}

	
		void caballo::dibujaCab() {
			Caballo.setColor(true);
			if (Caballo.getColor() == true) {
				Caballo.pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getx(), gety() + 1);
				casilla_torre = true;
			}
			else {
				torre.pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getx(), gety() + 1);
				casilla_torre = true;
			}
			*/


