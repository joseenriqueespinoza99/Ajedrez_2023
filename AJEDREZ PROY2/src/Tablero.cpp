#include "freeglut.h"
#include "Tablero.h"
#include "Alfil.h"
#include "Torre.h"
#include "caballo.h"
#include "Pieza.h"
#include "ListaPiezas.h"

Tablero::Tablero()
{
	if (turno)
		final = false;
	turno = true;
}
Pieza* p[32];
ListaPiezas listapiezas;
void Tablero::inicializa() {
	

	p[0] = new Torre(0, 7, false);
	p[1] = new Torre(7, 7, false);
	p[2] = new Torre(0, 0, true);
	p[3] = new Torre(7, 0, true);

	p[4] = new Alfil(5, 0,true);
	p[5]= new Alfil(2, 0, true);
	p[6]= new Alfil(5, 7, false);
	p[7]= new Alfil(2, 7, false);

	p[8] = new Caballo(1, 0, true);
	p[9] = new Caballo(6, 0, true);
	p[10] = new Caballo(1, 7, false);
	p[11] = new Caballo(6, 7, false);


	for(int j=0;j<12;j++)
	listapiezas.agregar(p[j]);
}
void Tablero::dibuja() {
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

	p[0]->mueve(key);
	p[1]->mueve(key);
	p[2]->mueve(key);
	p[3]->mueve(key);


}

bool Tablero::EspacioBlancas(Pieza* c) {
	for (int i = 0; i < 16; i++) {
		
		if (casillaOcupaBlanca[i]->getX() == c->getX() && casillaOcupaBlanca[i]->getY() == c->getY())
			return true;     
	}
	return false;		
}

bool Tablero::EspacioNegras(Pieza* c) {
	for (int i = 0; i < 16; i++) {
		
		if (casillaOcupaNegra[i]->getX() == c->getX() && casillaOcupaNegra[i]->getY() == c->getY())
			return true;     
	}
	return false;		
}

bool Tablero::EspacioCasilla(Pieza* p) {
	if (EspacioBlancas(p) || EspacioNegras(p)) {
		return true;
	}
	else
		return false;
}

void Tablero::cambiarTurno() {
	if (turno)
		turno = false;
	else
		turno = true;
}
