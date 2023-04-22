#include "freeglut.h"
#include "Tablero.h"
#include "Alfil.h"
#include "dibuja.h"
dibuja pieza;
void Tablero::dibuja() {
	pieza.pintarblancas();
	pieza.pintarnegras();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			posicion p { i + 1, j + 1 };
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
