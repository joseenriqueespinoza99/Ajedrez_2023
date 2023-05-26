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

	//DAMAS
	p[12] = new Dama(3, 0, true);
	p[13] = new Dama(3, 7, false);

	//REYES
	p[14] = new Rey(4, 0, true);
	p[15] = new Rey(4, 7, false);

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

	if ((piezaSelecc != nullptr) && (su_turno() == true)) { // Selecciona las casilla donde hay piezas que te puedes comer
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (piezaSelecc->esmovimientoValido(i, j, 1) == 1) {
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


	if (piezaSelecc != nullptr) { // Selecciona las casillas vacías a las que te puedes mover
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
				if (modo == false) {
					glBegin(GL_POLYGON);
					glColor3f(0, 0.5, 0.5);
					glVertex2i(i + 1, j + 1);
					glVertex2i(i + 1, j);
					glVertex2i(i, j);
					glVertex2i(i, j + 1);
					glEnd();
				}
				else {
					glBegin(GL_POLYGON);
					glColor3f(0, 0, 0);
					glVertex2i(i + 1, j + 1);
					glVertex2i(i + 1, j);
					glVertex2i(i, j);
					glVertex2i(i, j + 1);
					glEnd();
				}
				
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

	if (turno == true) {
		ETSIDI::setTextColor(0.9, 0.9, 0.4);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 15);
		ETSIDI::printxy("Mueven las BLANCAS", -2.5, -1);
	}
	else {
		ETSIDI::setTextColor(0.4, 0.9, 0.9);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 15);
		ETSIDI::printxy("Mueven las NEGRAS", 6.5, -1);
	}
}

void Tablero::mueve()
{

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
		return true; // Casilla ocupada
	
	}
}

bool Tablero::comprobar_color(bool color)
{
	if (piezaSelecc->getColor() == color) return true;
	else return false;
}


bool Tablero::su_turno() {
	if (piezaSelecc != nullptr) {
		if (piezaSelecc->getColor() == turno) {
			return true;
		}
		else {
			return false;
		}
	}
}

void Tablero::cambio_turno() {
	if (piezaSelecc != nullptr) {
		if (piezaSelecc->getColor() == true) {
			turno = false;
		}
		else {
			turno = true;
		}
	}
}
Tablero::~Tablero()
{
	
}
void Tablero::mover(int x, int y, int comer) {
	Pieza* piezaDestino = listapiezas.getPieza(x, y);
	Pieza* amenaza = PiezaAmenazaRey();
	if (getNumeroReyes() < 2) {
		setJaqueMate(true);
		return;
	}
	if (piezaSelecc != nullptr) {
		comprobar_enroque_corto(turno);
		comprobar_enroque_largo(turno);
		bool jaqueRey = comprobar_jaqueRey(piezaSelecc->getColor());
		if (jaqueRey) {
			if (casillaOcupada(x, y)) { // Mover comiendo
				if (piezaDestino != nullptr && (!comprobar_color(piezaDestino->getColor()))) { // La casilla seleccionada contiene una pieza del equipo contrario
					comer = 1;
					alpaso = 0;
					if (piezaSelecc->getClass() == REY && (piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario

						if (!comprobar_camino(x,y,piezaSelecc->getX(), piezaSelecc->getY())) {
							coronacion(x, y); // Implementación
							if (casillaEnJaque(piezaSelecc->getColor(), x, y))
							{
								listapiezas.eliminar(piezaDestino);
								piezaSelecc->mover(x, y, comer);
								ETSIDI::play("sonidos/comida.mp3");
								cambio_turno();
								enroque_c = 0;
								enroque_l = 0;
								piezaSelecc = nullptr;
							}
						}

					}
					else {
						if (comprobar_jaqueRey(piezaSelecc->getColor()))
						{
							if (amenaza != nullptr && piezaSelecc->esmovimientoValido(x, y, comer) && su_turno()) {
								listapiezas.eliminar(amenaza);
								piezaSelecc->mover(x, y, comer);
								ETSIDI::play("sonidos/comida.mp3");
								cambio_turno();
								enroque_c = 0;
								enroque_l = 0;
								piezaSelecc = nullptr;
								glutPostRedisplay();
								return;
							}
						}
					}
				}

			}
			else if (!casillaOcupada(x, y)) {
				// Verificar si la pieza seleccionada es el rey y si el movimiento es válido para el rey
				if (piezaSelecc->getClass() == REY && piezaSelecc->esmovimientoValido(x, y, comer) == 1) {
					if (!casillaEnJaque(piezaSelecc->getColor(), x, y)) {
						// Mover al rey para salir del jaque
						if (!comprobar_camino(x,y,piezaSelecc->getX(), piezaSelecc->getY())) {
							comer = 0;
							coronacion(x, y);
							piezaSelecc->mover(x, y, comer);
							ETSIDI::play("sonidos/mueve.mp3");
							if (piezaSelecc->getColor() == true) {
								turno = false;
							}
							else {
								turno = true;
							}
							piezaSelecc = nullptr;
						}
					}
				}
				else {
					if (piezaSelecc->getClass() != REY && piezaSelecc->esmovimientoValido(x, y, comer) == 1) {
						if (casillaEnJaque(piezaSelecc->getColor(), x, y)) {
							// Mover al rey para salir del jaque
							if (!comprobar_camino(x,y,piezaSelecc->getX(), piezaSelecc->getY())) {
								comer = 0;
								coronacion(x, y);
								piezaSelecc->mover(x, y, comer);
								ETSIDI::play("sonidos/mueve.mp3");
								if (piezaSelecc->getColor() == true) {
									turno = false;
								}
								else {
									turno = true;
								}
								piezaSelecc = nullptr;
							}
						}
					}
				}

			}

		}

		else {
			// Intentar mover la pieza a la nueva posición
			if (casillaOcupada(x, y)) {//Mover comiendo
				if (piezaDestino != nullptr && (!comprobar_color(piezaDestino->getColor()))) { // La casilla seleccionada contiene una pieza del equipo contrario
					comer = 1;
					alpaso = 0;
					if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario
						if (!comprobar_camino(x, y, piezaSelecc->getX(), piezaSelecc->getY()))
						{
							coronacion(x, y);//implementación
							listapiezas.eliminar(piezaDestino);
							piezaSelecc->mover(x, y, comer);
							ETSIDI::play("sonidos/comida.mp3");
							cambio_turno();
							enroque_c = 0;
							enroque_l = 0;
							piezaSelecc = nullptr;
						}

					}
				}

			}
			else if (casillaOcupada(x, y) == false) { //Solo mover
				if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
					if (!comprobar_camino(x,y,piezaSelecc->getX(), piezaSelecc->getY())) {
						comer_al_paso(piezaSelecc->getX(), piezaSelecc->getY(), x, y, turno);
						comer = 0;
						coronacion(x, y);
						piezaSelecc->mover(x, y, comer);
						ETSIDI::play("sonidos/mueve.mp3");
						cambio_turno();
						enroque_c = 0;
						enroque_l = 0;
						piezaSelecc = nullptr;
					}

				}
				else if ((comprobar_enroque_corto(turno)) || (comprobar_enroque_largo(turno))) {
					if (enroque_c == 1) {
						comer = 4;
						Pieza* piezaDestino2 = listapiezas.getPieza(x + 1, y);
						if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
							piezaSelecc->mover(x, y, comer);
							piezaDestino2->mover(x - 1, y, comer);
							ETSIDI::play("sonidos/mueve.mp3");
							cambio_turno();
							enroque_c = 0;
							piezaSelecc = nullptr;
						}
					}
					else if (enroque_l == 1) {
						comer = 5;
						Pieza* piezaDestino2 = listapiezas.getPieza(x - 2, y);
						if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
							piezaSelecc->mover(x, y, comer);
							piezaDestino2->mover(x + 1, y, comer);
							ETSIDI::play("sonidos/mueve.mp3");
							cambio_turno();
							enroque_l = 0;
							piezaSelecc = nullptr;
						}
					}
				}
			}
			if (casillaOcupada(x, y - 1)) { //comer al paso para las blancas
				Pieza* piezaDestino2 = listapiezas.getPieza(x, y - 1);
				if ((alpaso == 1) || (alpaso == 2)) {
					if (alpaso == 1) comer = 3;
					else comer = 2;
					if (piezaDestino2 != nullptr && (!comprobar_color(piezaDestino2->getColor()))) {
						if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
							listapiezas.eliminar(piezaDestino2);
							piezaSelecc->mover(x, y, comer);
							ETSIDI::play("sonidos/comida.mp3");
							cambio_turno();
							alpaso = 0;
							piezaSelecc = nullptr;
						}
					}
				}
			}
			if (casillaOcupada(x, y + 1)) { //comer al paso para las negras
				Pieza* piezaDestino2 = listapiezas.getPieza(x, y + 1);
				if ((alpaso == 3) || (alpaso == 4)) {
					if (alpaso == 3) comer = 3;
					else comer = 2;
					if (piezaDestino2 != nullptr && (!comprobar_color(piezaDestino2->getColor()))) {
						if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
							listapiezas.eliminar(piezaDestino2);
							piezaSelecc->mover(x, y, comer);
							ETSIDI::play("sonidos/comida.mp3");
							cambio_turno();
							alpaso = 0;
							piezaSelecc = nullptr;
						}
					}
				}
			}

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


bool Tablero::comprobar_jaqueRey(bool color) {
	Pieza* Rey = nullptr;
	Pieza* pieza;
	tipo = REY;
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		if (listapiezas.getPiezas(i)->getClass() == tipo && listapiezas.getPiezas(i)->getColor() == color) {//identifica si la pieza es un rey 
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


Pieza * Tablero::coronacion(int x, int y) {
	Pieza* Peon= nullptr;
	Pieza* pieza;
	tipo = PEON;
	if (piezaSelecc != nullptr && piezaSelecc->getClass() == tipo) {
		if ((piezaSelecc->getColor() == true && y == 7) || (piezaSelecc->getColor() == false && y == 0)) {
			// Seleccionar la pieza a la que se desea coronar
			int opcion;
			std::cout << "Seleccione la pieza a la que desea coronar: " << std::endl;
			std::cout << "1. Dama" << std::endl;
			std::cout << "2. Torre" << std::endl;
			std::cout << "3. Alfil" << std::endl;
			std::cout << "4. Caballo" << std::endl;
			std::cout << "Ingrese el numero correspondiente a la opcion: ";
			std::cin >> opcion;

			switch (opcion) {
			case 1: {
				Dama* nuevaDama = new Dama(x, y, piezaSelecc->getColor());
				listapiezas.reemplazar(piezaSelecc, nuevaDama);
				piezaSelecc = nuevaDama;
				coronar = true;
				return piezaSelecc;
				break;
			}
			case 2: {
				Torre* nuevaTorre = new Torre(x, y, piezaSelecc->getColor());
				listapiezas.reemplazar(piezaSelecc, nuevaTorre);
				piezaSelecc = nuevaTorre;
				coronar = true;
				return piezaSelecc;
				break;
			}
			case 3: {
				Alfil* nuevoAlfil = new Alfil(x, y, piezaSelecc->getColor());
				listapiezas.reemplazar(piezaSelecc, nuevoAlfil);
				piezaSelecc = nuevoAlfil;
				coronar = true;
				return piezaSelecc;
				break;
			}
			case 4: {
				Caballo* nuevoCaballo = new Caballo(x, y, piezaSelecc->getColor());
				listapiezas.reemplazar(piezaSelecc, nuevoCaballo);
				piezaSelecc = nuevoCaballo;
				coronar = true;
				return piezaSelecc;
				break;
			}
			default:
				std::cout << "Opción inválida." << std::endl;
				return nullptr;
				break;
			}
		}
	}
	return nullptr;
}


void Tablero::comer_al_paso(int origen_x, int origen_y, int destino_x, int destino_y, bool color) {
	//si un peon se mueve 2 posiciones y se coloca al lado de otro peon
	//el otro peon puede en el siguiente movimiento comerse al peon que tiene a su lado moviendose en diagonal
	Pieza* Peon = nullptr;
	tipo = PEON;
	alpaso = 0;
	if (piezaSelecc->getClass() == tipo && (abs(destino_y - origen_y) == 2)) {
		for (int i = 0; i < listapiezas.getNumero(); i++) {
			if (listapiezas.getPiezas(i)->getClass() == tipo) {
				Peon = listapiezas.getPiezas(i);
				if ((Peon != nullptr)&&(Peon->getColor() != color) && (Peon->getY() == destino_y)) {
					if (Peon->getColor() == true) {
						if (Peon->getX() == destino_x + 1) {
							alpaso = 1; // La blanca puede comer al paso hacia la izquierda
						}
						if (Peon->getX() == destino_x - 1) {
							alpaso = 2; // La blanca puede comer al paso hacia la derecha
						}
					}
					else {
						if (Peon->getX() == destino_x + 1) {
							alpaso = 3; // La negra puede comer al paso hacia la izquierda
						}
						if (Peon->getX() == destino_x - 1) {
							alpaso = 4; // La negra puede comer al paso hacia la derecha
						}
					}
				}
			}
		}
	}
}

bool Tablero::casillaEnJaque(bool colorRey, int x, int y) {
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		Pieza* pieza = listapiezas.getPiezas(i);
		if (pieza->getColor() != colorRey) {
			if (pieza->esmovimientoValido(x, y, 1) == 1) {
				return true;
			}
		}
	}
	return false;
}


bool Tablero::comprobar_enroque_corto(bool color) {
	//si selecciono al rey y: el rey nunca se ha movido, la torre nunca se ha movido, el rey no está en jaque, no hay nada en medio de las piezas
	//se pueden intercambiar la torre y el rey en medio
	Pieza* Tor = nullptr;
	enroque_c = 0;
	if ((piezaSelecc != nullptr)&&(piezaSelecc->getClass() == REY) && piezaSelecc->getColor() == color) { // Si es rey
		for (int i = 0; i < listapiezas.getNumero(); i++) {
			if ((listapiezas.getPiezas(i)->getClass() == TORRE) && (listapiezas.getPiezas(i)->getX() == 7) && (listapiezas.getPiezas(i)->getColor() == color)) { // Si es torre derecha
				Tor = listapiezas.getPiezas(i);
				if ((Tor != nullptr) &&(piezaSelecc->getMov() == 0) && (Tor->getMov() == 0)) { // Si nunca se han movido
					if (comprobar_jaqueRey(color) == false) { // Si el rey no está en jaque
						if (comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), Tor->getX(), Tor->getY())==false) {
							enroque_c = 1;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool Tablero::comprobar_enroque_largo(bool color) {
	//si selecciono al rey y: el rey nunca se ha movido, la torre nunca se ha movido, el rey no está en jaque, no hay nada en medio de las piezas
	//se pueden intercambiar la torre y el rey en medio
	Pieza* Tor = nullptr;
	enroque_l = 0;
	if ((piezaSelecc != nullptr) && (piezaSelecc->getClass() == REY) && piezaSelecc->getColor() == color) { // Si es rey
		for (int i = 0; i < listapiezas.getNumero(); i++) {
			if ((listapiezas.getPiezas(i)->getClass() == TORRE) && (listapiezas.getPiezas(i)->getX() == 0) && (listapiezas.getPiezas(i)->getColor() == color)) { // Si es torre derecha
				Tor = listapiezas.getPiezas(i);
				if ((Tor != nullptr) && (piezaSelecc->getMov() == 0) && (Tor->getMov() == 0)) { // Si nunca se han movido
					if (comprobar_jaqueRey(color) == false) { // Si el rey no está en jaque
						if (comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), Tor->getX(), Tor->getY()) == false) {
							enroque_l = 1;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


Pieza* Tablero::PiezaAmenazaRey() {
	// Obtener la posición del rey blanco
	int xRey = 0;
	int yRey = 0;
	Pieza* rey = nullptr;

	for (int i = 0; i < listapiezas.getNumero(); i++) {
		Pieza* pieza = listapiezas.getPiezas(i);
		if (pieza->getClass() == REY) {
			rey = pieza;
			xRey = pieza->getX();
			yRey = pieza->getY();
			break;
		}
	}

	if (rey == nullptr) {
		// No se encontró el rey blanco en el tablero
		return nullptr;
	}

	// Verificar si alguna pieza del oponente amenaza al rey blanco
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		Pieza* piezaOponente = listapiezas.getPiezas(i);
		if (piezaOponente->getColor() != rey->getColor()) {
			if (piezaOponente->esmovimientoValido(xRey, yRey, 1)) {
				return piezaOponente;
			}
		}
	}

	return nullptr;
}
int Tablero::getNumeroReyes() {
	int count = 0;
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		if (listapiezas.getPiezas(i)->getClass() == REY) {
			count++;
		}
	}
	return count;
}

