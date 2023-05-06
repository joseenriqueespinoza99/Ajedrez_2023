#include "freeglut.h"
#include "Tablero.h"
#include "Pieza.h"
#include "ListaPiezas.h"
#include "Mundo.h"


Pieza* p[32];
ListaPiezas listapiezas;
Pieza* piezaSelecc=nullptr;

void Tablero::inicializa() {


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
Tablero::Tablero() {
	inicializa();
}


void Tablero::dibuja() {
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
	for (int i = 0; i < listapiezas.size(); i++) {
		listapiezas.getPiezas(i)->dibuja();
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			posicion p{ i + 1, j + 1 };
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
void Tablero::mueve(unsigned char key) {
	for (int i = 0; i < listapiezas.size(); i++) {
		listapiezas.getPiezas(i)->mueve(key);
	}
}

void Tablero::seleccionar_pieza(int x, int y) {
	Pieza* nueva_Pieza_Seleccionada = listapiezas.getPieza(x, y);
	if (nueva_Pieza_Seleccionada != nullptr) {
		// mueva a una nueva casilla estando seleccioanda la pieza
		if (piezaSelecc != nullptr) {
			if (listapiezas.getPieza(x, y) != nullptr) {
				// Si la casilla seleccionada est� ocupada, mueve la pieza seleccionada encima de la pieza all� 
				//dentro de la funcion mover se elimina la esa pieza que esta debajo de la lista
				mover( x, y, 0);
				piezaSelecc = nullptr;
			}
			else {
				// mueve la pieza si la casilla seleccionada esta vacia
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
bool Tablero::casillaOcupada(int x, int y) {
	Pieza* piezaEnCasilla = listapiezas.getPieza(x, y);
	if (piezaEnCasilla == nullptr) {
		return false; // Casilla vac�a
	}
	else {
		std::cout << "Esta ocupada";
		return true; // Casilla ocupada
	
	}
}

void Tablero::mover(int x, int y, bool comer) {
	Pieza* piezaDestino = listapiezas.getPieza(x, y);
	if (piezaSelecc != nullptr) {
		// Intentar mover la pieza a la nueva posici�n
		if (casillaOcupada(x, y)) {
			if (piezaDestino != nullptr && (piezaSelecc->getColor() != piezaDestino->getColor())) { // La casilla seleccionada contiene una pieza del equipo contrario
				comer = 1;
				if (piezaSelecc->esmovimientoValido(x, y, comer) == 1) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario
					listapiezas.eliminar(piezaDestino);
					std::cout << "Se esta eliminando la pieza";
					piezaSelecc->mover(x, y, comer);
					piezaSelecc = nullptr;
					ETSIDI::play("sonidos/comer.wav");
				}
				else {
					std::cout << "Movimiento no valido para la pieza" << std::endl;
				}
			}
		}
		else {	
			if (piezaSelecc->esmovimientoValido(x, y, comer) == 1) {
				comer = 0;
				piezaSelecc->mover(x, y, comer);
				piezaSelecc = nullptr;
				ETSIDI::play("sonidos/mover.wav");
			}
			else{
				std::cout << "Movimiento no valido para la pieza" << std::endl;
			}
		}

		}
		glutPostRedisplay();
	}




