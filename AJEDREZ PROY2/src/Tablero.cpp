#include "freeglut.h"
#include "Tablero.h"
#include "Alfil.h"
#include "Torre.h"
#include "Pieza.h"
#include "ListaPiezas.h"
#include "Mundo.h"
Pieza* p[32];
ListaPiezas listapiezas;
Pieza* piezaSeleccionada = nullptr;

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

	for (int i = 0; i < 8; i++)
		listapiezas.agregar(p[i]);
	
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

	Pieza* alfil1 = listapiezas.getPiezas(0);
	alfil1->mueve(key);
	Pieza* alfil2 = listapiezas.getPiezas(1);
	alfil2->mueve(key);
	Pieza* alfil3 = listapiezas.getPiezas(2);
	alfil3->mueve(key);
	Pieza* alfil4 = listapiezas.getPiezas(3);
	alfil4->mueve(key);
	

}
void Tablero::mover(int x, int y)
{
	
	for (int i = 0; i < listapiezas.size(); i++) {
		listapiezas.getPiezas(i)->mover(x,y);
	}
}

Tablero:: Tablero() {
	inicializa();
}

void Tablero:: seleccionar_pieza(int x, int y) {

	Pieza* nueva_Pieza_Seleccionada = listapiezas.getPieza(x, y);
	if (piezaSeleccionada != nueva_Pieza_Seleccionada) {
		piezaSeleccionada = nueva_Pieza_Seleccionada;
	}
}
