#include "Alfil.h"
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"
#include <iostream>
Tablero t;
Pieza p;
Alfil :: Alfil(int x, int y, bool color) {
	this->posx = x;
	this->posy = y;
	this->color = color;
	
}

void Alfil::mueve(unsigned char key) {

	int m = getX();
	int n = getY();
	if(m<7 && n<7){ 
	if(key=='c')
{
		m++;
		n++;
	}
	if (key == 'q') {
		m--;
		n--;
	}
	if (key == 'e') {
		m++;
		n--;
	}
	if (key == 'z') {
		m--;
		n++;
	}
	}
	else
	{
		m = m;
		n = n;
	}
	setX(m);
	setY(n);
	glutPostRedisplay;
	}

// Método para comprobar si el movimiento del alfil es válido
bool Alfil::movimientoValido(int x_Destino, int y_Destino) const {
	// Un alfil se mueve en diagonal, por lo que el movimiento es válido si la distancia en filas y columnas es la misma
	int distanciaFilas = abs(x_Destino - posx);
	int distanciaColumnas = abs(y_Destino -posy);
	return (distanciaFilas == distanciaColumnas);
}
void Alfil::dibuja() {
	alf.setColor(true);
	if (alf.getColor() == true)
		alf.pintar("imagenes/alfilnegro.png", "imagenes/alfilblanco.png", "imagenes/alfilnblanco.png", "imagenes/alfilnnegro.png", getX()+2, getY()+1);
	else
		alf.pintar("imagenes/alfilblanco.png", "imagenes/alfilnegro.png", "imagenes/alfilnnegro.png", "imagenes/alfilnblanco.png", getX()+2, getY()+1);
}
