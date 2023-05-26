#include "Dama.h"

Dama::Dama(int x, int y, bool color) {  //Constructor
	this->setX(x);
	this->setY(y);
	this->color = color;
	TipoPieza REINA;
}


void Dama::dibuja() { // Para dibujar las damas
	if (getModo() == false) { // Se usan estas imagenes (tematicas) de forma general
		if (color == true)
			pintar("imagenes/damanegra.png", "imagenes/damablanca.png", "imagenes/damanblanca.png", "imagenes/damannegra.png", getX(), getY() + 1);
		else
			pintar("imagenes/damablanca.png", "imagenes/damanegra.png", "imagenes/damannegra.png", "imagenes/damanblanca.png", getX(), getY() + 1);
	}
	else { // Si se quiere utilizar el ajedrez clásico se ponen estas imágenes
		if (color == true)
			pintar("imagenes/clasicas/clasdamanegra.png", "imagenes/clasicas/clasdamablanca.png", "imagenes/clasicas/clasdamanblanca.png", "imagenes/clasicas/clasdamannegra.png", getX(), getY() + 1);
		else
			pintar("imagenes/clasicas/clasdamablanca.png", "imagenes/clasicas/clasdamanegra.png", "imagenes/clasicas/clasdamannegra.png", "imagenes/clasicas/clasdamanblanca.png", getX(), getY() + 1);
	}
}

bool Dama::esmovimientoValido(int x_Destino, int y_Destino, int comer) { // Método para comprobar si el movimiento de la dama es válido
	// La dama se mueve en diagonal, en horizontal y en vertical
	if (fabs(getX() - x_Destino) == fabs(getY() - y_Destino))
		return true;
	if ((fabs(getX() - x_Destino) == 0) && (fabs(getY() - y_Destino) != 0))
		return true;
	if ((fabs(getX() - x_Destino) != 0) && (fabs(getY() - y_Destino) == 0))
		return true;
	return false;
}

void Dama::mover(int x, int y, int comer) { // Para actualizar la posicion de la dama
	getX();
	getY();
	if (esmovimientoValido(x, y, comer)) { // Comprobar si el movimiento es válido 
		// Actualizar la posición de la dama a la celda de destino
		setX(x);
		setY(y);
	}
	glutPostRedisplay;
}



