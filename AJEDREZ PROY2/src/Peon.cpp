#include "Peon.h"

Peon::Peon(int x, int y, bool color) { //Constructor
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza PEON;
}

void Peon::dibuja() { // Para dibujar los peones
	if (getModo() == false) { // Se usan estas imagenes (tematicas) de forma general
		if (color == true)
			pintar("imagenes/peonnegro.png", "imagenes/peonblanco.png", "imagenes/peonnblanco.png", "imagenes/peonnnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/peonblanco.png", "imagenes/peonnegro.png", "imagenes/peonnnegro.png", "imagenes/peonnblanco.png", getX(), getY() + 1);
	}
	else { // Si se quiere utilizar el ajedrez clásico se ponen estas imágenes
		if (color == true) 
			pintar("imagenes/clasicas/claspeonnegro.png", "imagenes/clasicas/claspeonblanco.png", "imagenes/clasicas/claspeonnblanco.png", "imagenes/clasicas/claspeonnnegro.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/claspeonblanco.png", "imagenes/clasicas/claspeonnegro.png", "imagenes/clasicas/claspeonnnegro.png", "imagenes/clasicas/claspeonnblanco.png", getX(), getY() + 1);
	}
}

bool Peon::esmovimientoValido(int x_Destino, int y_Destino, int comer) { // Método para comprobar si el movimiento del peon es válido
	if (comer == 0) { // Cuando no va a comer
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
	}
	if (comer == 1) { // Solo si va a comer
		// Solo se puede comer 1 casilla en diagonal 
		if ((color == 1) && ((x_Destino - getX()) == 1 && (y_Destino - getY()) == 1)) { // Superior derecha
			return 1;
		}
		else if ((color == 1) && ((x_Destino - getX()) == -1 && (y_Destino - getY()) == 1)) { // Superior izquierda
			return 1;
		}
		else if ((color == 0) && ((x_Destino - getX()) == -1 && (y_Destino - getY()) == -1)) { // inferior izquierda
			return 1;
		}
		else if ((color == 0) && ((x_Destino - getX()) == 1 && (y_Destino - getY()) == -1)) { // inferior derecha
			return 1;
		}
		else { return 0; }
	}

	if (comer == 2) { // Solo para comer al paso a la derecha
		// Solo se puede comer 1 casilla en diagonal 
		if ((color == 1) && ((x_Destino - getX()) == 1 && (y_Destino - getY()) == 1)) { // Superior derecha
			return 1;
		}
		else if ((color == 0) && ((x_Destino - getX()) == 1 && (y_Destino - getY()) == -1)) { // inferior derecha
			return 1;
		}
		else { return 0; }
	}

	if (comer == 3) { // Solo para comer al paso a la izquierda
		// Solo se puede comer 1 casilla en diagonal 
		if ((color == 1) && ((x_Destino - getX()) == -1 && (y_Destino - getY()) == 1)) { // Superior izquierda
			return 1;
		}
		else if ((color == 0) && ((x_Destino - getX()) == -1 && (y_Destino - getY()) == -1)) { // inferior izquierda
			return 1;
		}
		else { return 0; }
	}

	return 0;
}


void Peon::mover(int x, int y, int comer) { // Para actualizar la posicion del peon
	getX();
	getY();
	if (esmovimientoValido(x, y, comer)) { // Comprobar si el movimiento es válido 
		// Actualizar la posición del peon a la celda de destino
		setX(x);
		setY(y);
		setMov(); // Al cambiar de posición se suma 1 a movimientos (para controlar lo de mover 2 casillas)
	}
	glutPostRedisplay;
}