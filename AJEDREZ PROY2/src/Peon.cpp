#include "Peon.h"


Peon::Peon(int x, int y, bool color) {
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza PEON;
}
void Peon::mueve(unsigned char key) {}

// Método para comprobar si el movimiento del peon es válido
bool Peon::esmovimientoValido(int x_Destino, int y_Destino) {
	
	if (abs(x_Destino - getX()) == 0) { // Solo se puede mover hacia delante
		if ((color == 1) && (y_Destino - getY()) == 1) { // Solo se puede mover 1 casilla hacia delante
			return 1;
		}
		else if ((color == 1) && ((y_Destino - getY()) == 2) && (getMov() == 0)) { // Se puede mover 2 casillas si estaba en la posicion inicial
			return 1;
		}
		else if ((color == 0) && (y_Destino - getY()) == -1) {
			return 1;
		}
		else if ((color == 0) && ((y_Destino - getY()) == -2) && (getMov() == 0)) {
			return 1;
		}
		else { return 0; }
	}
	else if (1 == 1) { // Solo si va a comer
			// Solo se puede comer 1 casilla en diagonal 
			if ((color == 1) && (x_Destino - getX()) == 1 && (y_Destino - getY()) == 1) { // Superior derecha
				return 1;
			}
			else if ((color == 1) && (x_Destino - getX()) == -1 && (y_Destino - getY()) == 1) { // Superior izquierda
				return 1;
			}
			else if ((color == 0) && (x_Destino - getX()) == -1 && (y_Destino - getY()) == -1) { // inferior izquierda
				return 1;
			}
			else if ((color == 0) && (x_Destino - getX()) == 1 && (y_Destino - getY()) == -1) { // inferior derecha
				return 1;
			}
			else { return 0; }
		}
	else		
		return 0;
}

void Peon::dibuja() {
	if (color == true)
		pintar("imagenes/peonnegro.png", "imagenes/peonblanco.png", "imagenes/peonnblanco.png", "imagenes/peonnnegro.png", getX(), getY() + 1);
	else
		pintar("imagenes/peonblanco.png", "imagenes/peonnegro.png", "imagenes/peonnnegro.png", "imagenes/peonnblanco.png", getX(), getY() + 1);
}

void Peon::mover(int x, int y) {
	getX();
	getY();
	// Comprobar si el movimiento es válido 
	if (esmovimientoValido(x, y)) {
		// Actualizar la posición del rey a la celda de destino
		setX(x);
		setY(y);
		setMov(); // Al cambiar de posición se suma 1 a movimientos
	}
	glutPostRedisplay;
}