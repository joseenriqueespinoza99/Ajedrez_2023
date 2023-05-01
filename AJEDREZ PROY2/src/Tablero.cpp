#include "freeglut.h"
#include "Tablero.h"
#include "Alfil.h"
#include "Torre.h"
#include "Pieza.h"
#include "ListaPiezas.h"
Pieza* p[32];
ListaPiezas listapiezas;
void Tablero::inicializa() {

	Pieza* alfil1(new Alfil(3, 0, true));
	listapiezas.agregar(alfil1);
	Pieza* alfil2(new Alfil(6, 0, true));
	listapiezas.agregar(alfil2);
	Pieza* alfil3(new Alfil(6, 7, false));
	listapiezas.agregar(alfil3);
	Pieza* alfil4(new Alfil(3, 7, false));
	listapiezas.agregar(alfil4);
	
	//ALFILES
	p[0] = new Alfil(3, 0, true);
	p[1] = new Alfil(6, 0, true);
	p[2] = new Alfil(6, 7, false);
	p[3] = new Alfil(3, 7, false);

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
	p[4]->mover(x, y);
}
