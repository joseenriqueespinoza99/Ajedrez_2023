#include "freeglut.h"
#include "Tablero.h"
#include <string>

int casillasDisponibles = 0;

void Tablero::inicializa() {
	x_ojo = 4.0;
	y_ojo = 4.0;
	z_ojo = 14.0;

	//ALFILES
	p[0] = new Alfil(2, 0, true);
	p[1] = new Alfil(5, 0, true);
	p[2] = new Alfil(5, 7, false);
	p[3] = new Alfil(2, 7, false);

	//TORRES	
	p[4] = new Torre(0, 0, true);
	p[5] = new Torre(7, 0, true);
	p[6] = new Torre(0, 7, false);
	p[7] = new Torre(7, 7, false);

	//CABALLOS
	p[8] = new Caballo(1,0 ,true);
	p[9] = new Caballo(6, 0, true);
	p[10] = new Caballo(1, 7, false);
	p[11] = new Caballo(6, 7, false);

	//REYES
	p[12] = new Rey(4, 0, true);
	p[13] = new Rey(4, 7, false);

	//DAMAS
	p[14] = new Dama(3, 0, true);
	p[15] = new Dama(3, 7, false);

	//PEONES
	for (int i = 0; i < 8; i++) {
		p[16 + i] = new Peon(i, 1, true);
		p[24 + i] = new Peon(i, 6, false);
	}
	for (int i = 0; i < 32; i++)
		listapiezas.agregar(p[i]);	
}


void Tablero::dibuja() {
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
        4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
        0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	//A partir de aqui esta el codigo de dibujo
	if (piezaSelecc != nullptr) {//dibujar 
		glLineWidth(4.0);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(piezaSelecc->getX(), piezaSelecc->getY());
		glVertex2f(piezaSelecc->getX() + 1, piezaSelecc->getY());
		glVertex2f(piezaSelecc->getX() + 1, piezaSelecc->getY() + 1);
		glVertex2f(piezaSelecc->getX(), piezaSelecc->getY() + 1);
		glEnd();
	}

	// --> PARA SELECCIONAR LAS CASILLAS QUE TE PUEDES COMER
	if (piezaSelecc != nullptr) {
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (piezaSelecc->esmovimientoValido(i, j, 0) == 1) {
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), i, j)) {
						Pieza* piezaDestino = listapiezas.getPieza(i, j);
						if (piezaDestino != nullptr && piezaDestino->getColor() != piezaSelecc->getColor()) {
							glLineWidth(4.0);
							glBegin(GL_LINE_LOOP);
							glColor3f(0, 1, 0);
							glVertex2f(piezaDestino->getX(), piezaDestino->getY());
							glVertex2f(piezaDestino->getX() + 1, piezaDestino->getY());
							glVertex2f(piezaDestino->getX()+1, piezaDestino->getY()+1);
							glVertex2f(piezaDestino->getX(), piezaDestino->getY()+1);
							glEnd();
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		listapiezas.getPiezas(i)->dibuja();
	}

	// --> PARA SELECCIONAR LAS CASILLAS DONDE SE PUEDEN MOVER
	if (piezaSelecc != nullptr) {
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (piezaSelecc->esmovimientoValido(i, j, 0) == 1) {
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), i, j)) {
						glPushMatrix();
						glTranslatef(i, j, 0.0); // Posición de la casilla disponible

						if (turno && piezaSelecc->getColor() == true) {
							glColor3f(0.9, 0.9, 0.4); // Color del cuadrado para el jugador 1
						}
						else if (!turno && piezaSelecc->getColor() == false) {
							glColor3f(0.4, 0.9, 0.9); // Color del cuadrado para el jugador 2
						}
						else {
							Pieza* piezaDestino = listapiezas.getPieza(i, j);
							if (piezaDestino != nullptr && piezaDestino->getColor() != piezaSelecc->getColor()) {
								glColor3f(0, 1, 0); // Color verde para las casillas que pueden ser capturadas
							}
							else {
								glPopMatrix();
								continue; // Si no es el turno del jugador correspondiente y la casilla no puede ser capturada, se pasa a la siguiente iteración
							}
						}

						glBegin(GL_QUADS);
						glVertex2f(0.05, 0.05);
						glVertex2f(0.95, 0.05);
						glVertex2f(0.95, 0.95);
						glVertex2f(0.05, 0.95);
						glEnd();

						glPopMatrix();
					}
				}
			}
		}
	}

	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Coordenadas p{ i + 1, j + 1 };
			int indices = i + j;
			if ((indices % 2) == 0) {
				glBegin(GL_POLYGON);
				glColor3f(0, 0.5, 0.5);
				glVertex2i(i + 1, j + 1);
				glVertex2i(i + 1, j);
				glVertex2i(i, j);
				glVertex2i(i, j + 1);
				glEnd();
			}
			if ((indices % 2) != 0) {
				glBegin(GL_POLYGON);
				glColor3f(255, 255, 255);
				glVertex2i(i + 1, j + 1);
				glVertex2i(i + 1, j);
				glVertex2i(i, j);
				glVertex2i(i, j + 1);
				glEnd();
			}
		}
	}
}


void Tablero::mueve() {

}

void Tablero::seleccionar_pieza(int x, int y) {
	Pieza* nueva_Pieza_Seleccionada = listapiezas.getPieza(x, y);
	if (nueva_Pieza_Seleccionada != nullptr) {
		// mueva a una nueva casilla estando seleccioanda la pieza
		if (piezaSelecc != nullptr) {
			if (listapiezas.getPieza(x, y) != nullptr) {
				// Si la casilla seleccionada está ocupada, mueve la pieza seleccionada encima de la pieza allí 
				//dentro de la funcion mover se elimina la esa pieza que esta debajo de la lista
				
				mover( x, y, 0);
				piezaSelecc = nullptr;
			}
			//else {
			//	// mueve la pieza si la casilla seleccionada esta vacia
			//	mover( x, y, 0);
			//	piezaSelecc = nullptr;
			//}
		}
		else {
			// No hay ninguna pieza seleccionada, selecciona la pieza en la nueva casilla
			piezaSelecc = nueva_Pieza_Seleccionada;
		}
		
		glutPostRedisplay();

	}

	}

void Tablero::tecla(unsigned char key)
{
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		listapiezas.getPiezas(i)->mueve(key);
	}
}

bool Tablero::casillaOcupada(int x, int y) {
	Pieza* piezaEnCasilla = listapiezas.getPieza(x, y);
	if (piezaEnCasilla == nullptr) {
		return false; // Casilla vacía
	}
	else {
		//std::cout << "Esta ocupada";
		return true; // Casilla ocupada
	
	}
}

bool Tablero::comprobar_color(bool color)
{
	if (piezaSelecc->getColor() == color) return true;
	else return false;
}

// --> PARA VER DE QUIEN ES TURNO
bool Tablero::su_turno() {
	if (piezaSelecc != nullptr) {
		if (piezaSelecc->getColor() == turno) {
			std::cout << "turno = color" << std::endl;
			return true;
		}
		else {
			std::cout << "No le toca a ese color" << std::endl;
			return false;
		}
	}
}

void Tablero::mover(int x, int y, bool comer) {
	Pieza* piezaDestino = listapiezas.getPieza(x, y);
	if (piezaSelecc != nullptr) {
		// Intentar mover la pieza a la nueva posición
		if (casillaOcupada(x, y)) {
			if (piezaDestino != nullptr && (!comprobar_color(piezaDestino->getColor()))) { // La casilla seleccionada contiene una pieza del equipo contrario
				comer = true;
				if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), x, y)) 
					{
						listapiezas.eliminar(piezaDestino);
						std::cout << "Se está eliminando la pieza" << std::endl;
						piezaSelecc->mover(x, y, comer);
						ETSIDI::play("sonidos/comida.mp3");
						if (piezaSelecc->getColor() == true) { 
							std::cout << "Turno blancas" << std::endl;
							turno = false;
						}
						else {
							std::cout << "Turno negras" << std::endl;
							turno = true;
						}
						piezaSelecc = nullptr;
					}
					else
						std::cout << "Hay piezas en el camino. No se puede mover la pieza" << std::endl;
					
				}
				else {
					std::cout << "Movimiento no valido para la pieza" << std::endl;
				}
			}
		}
		else {
			if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
				
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), x, y)) 
					{
						comer = false;
						piezaSelecc->mover(x, y, comer);
						ETSIDI::play("sonidos/mueve.mp3");
						if (piezaSelecc->getColor() == true) { 
							std::cout << "Turno blancas" << std::endl;
							turno = false;
						}
						else {
							std::cout << "Turno negras" << std::endl;
							turno = true;
						}
						piezaSelecc = nullptr;
					}
					else
						std::cout << "Hay piezas en el camino. No se puede mover la pieza" << std::endl;
				
			}

			else {
				std::cout << "Movimiento no valido para la pieza" << std::endl;
			}
		}
		if (comprobar_jaqueRey(turno)) {
			std::cout << "¡El rey esta en jaque!" << std::endl;
		}
		glutPostRedisplay();
	}
}

void Tablero::coord_a_celda(int x, int y)
{
	celda.x = (((x - 163) / 59.5) + 1); // Posicion en x del raton, la separacion a la izquierda desde que empieza la ventana hasta que empieza el tablero (163) y 59.5 el ancho de celda aproximado
	celda.y = (9 - ((y - 61) / 59.5)); // Pos en y del raton, la separacion por arriba desde que empieza la ventana hasta que empieza el tablero (61) y 59.5 el ancho de celda aproximado


	if ((x < 163 || x > 637 || y < 61 || y > 535)) {
		celda = { 0, 0 }; // si se selecciona fuera del tablero
	}
	seleccionar_pieza(celda.x - 1, celda.y - 1);
	destino.x = x;
	destino.y = y;
	mover(celda.x - 1, celda.y - 1, 0);

}

bool Tablero::comprobar_camino(int origen_x, int origen_y, int destino_x, int destino_y) { // Para evitar que las piezas se salten otras piezas
	// Verificar si el movimiento es horizontal, vertical o diagonal
	if (origen_x == destino_x || origen_y == destino_y || abs(destino_x - origen_x) == abs(destino_y - origen_y)) {
		int xmov, ymov;

		if (destino_x > origen_x) {
			xmov = 1;
		}
		else if (destino_x < origen_x) {
			xmov = -1;
		}
		else {
			xmov = 0;
		}

		if (destino_y > origen_y) {
			ymov = 1;
		}
		else if (destino_y < origen_y) {
			ymov = -1;
		}
		else {
			ymov = 0;
		}
		int x = origen_x + xmov;
		int y = origen_y + ymov;

		// Verificar las casillas intermedias en el camino
		while (x != destino_x || y != destino_y) {
			if (casillaOcupada(x, y)) {
				return true; // Hay una pieza en el camino
			}
			x += xmov;
			y += ymov;
		}
	}

	return false; // No hay piezas en el camino
}

// --> JAQUE
bool Tablero::comprobar_jaqueRey(bool color)
{

	Pieza* Rey = nullptr;
	Pieza* pieza;
	tipo = REY;
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		if (listapiezas.getPiezas(i)->getClass() == tipo && listapiezas.getPiezas(i)->getColor() == color) {//identifica si la pieza es un rey y 
			Rey = listapiezas.getPiezas(i);
			break;
		}
	}

	if (Rey == nullptr) {
		return false;
	}

	for (int i = 0; i < listapiezas.getNumero(); i++) {
		pieza = listapiezas.getPiezas(i);
		if (pieza->getColor() != color) {
			if (pieza->esmovimientoValido(Rey->getX(), Rey->getY(), true) == 1) {
				if (!comprobar_camino(pieza->getX(), pieza->getY(), Rey->getX(), Rey->getY())) {
					return true; // El rey está en jaque
				}
			}
		}
	}

	return false; // El rey no está en jaque
}

