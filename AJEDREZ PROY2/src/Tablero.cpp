#include "freeglut.h"
#include "Tablero.h"
#include "Alfil.h"
#include "Pieza.h"
int numero_reyes=2;
int numero_damas=2;
int numero_torres = 2;
int numero_caballos = 2;
int numero_alfiles = 2;
int numero_peones = 8;

Pieza reyes[2];
Pieza damas[2];
Pieza torres[2];
Pieza caballos[2];
Pieza alfiles[2];
Pieza Peones[8];
void Tablero::dibuja() {
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	Peones->setColor(true);//variable imprime blancas cuando es true y negras cuando es false
	for (int i = 0; i < numero_reyes; i++)
	{
		if (Peones->getColor() == true)
		reyes[i].pintar("imagenes/reynblanco.png", "imagenes/reyblanco.png", "imagenes/reynnegro.png", "imagenes/reynegro.png", 4, 1);
		else
		reyes[i].pintar("imagenes/reynblanco.png", "imagenes/reyblanco.png", "imagenes/reynnegro.png", "imagenes/reynegro.png", 4, 8);
	}
	for (int i = 0; i < numero_damas; i++)
	{
		if (Peones->getColor() == true)
			damas[i].pintar("imagenes/damanblanca.png", "imagenes/damablanca.png", "imagenes/damannegra.png", "imagenes/damanegra.png", 3, 1);
		else
			damas[i].pintar("imagenes/damanblanca.png", "imagenes/damablanca.png", "imagenes/damannegra.png", "imagenes/damanegra.png", 3, 8);
	}
	for (int i = 0; i < numero_torres; i++)
	{
		if (Peones->getColor() == true)
		torres[i].pintar("imagenes/torrenblanca.png", "imagenes/torreblanca.png", "imagenes/torrennegra.png", "imagenes/torrenegra.png", 0+l , 1);
		else
		torres[i].pintar("imagenes/torrenblanca.png", "imagenes/torreblanca.png", "imagenes/torrennegra.png", "imagenes/torrenegra.png", 0 + l, 8);
		l = 7;
	}
	for (int i = 0; i < numero_caballos; i++)
	{
		if (Peones->getColor() == true)
		caballos[i].pintar("imagenes/caballonblanco.png", "imagenes/caballoblanco.png", "imagenes/caballonnegro.png", "imagenes/caballonegro.png",1+k,1);
		else
		caballos[i].pintar("imagenes/caballonblanco.png", "imagenes/caballoblanco.png", "imagenes/caballonnegro.png", "imagenes/caballonegro.png",1+k, 8);
		k = 5;
	}
	for (int i = 0; i < numero_alfiles; i++)
	{
		
		if (Peones->getColor() == true)
		alfiles[i].pintar("imagenes/alfilnblanco.png", "imagenes/alfilblanco.png", "imagenes/alfilnnegro.png", "imagenes/alfilnegro.png", 2+m, 1);
		else
		alfiles[i].pintar("imagenes/alfilnblanco.png", "imagenes/alfilblanco.png", "imagenes/alfilnnegro.png", "imagenes/alfilnegro.png", 2+m, 8);
		m = 3;
	}
	for (int i = 0; i < numero_peones; i++)
	{
		if (Peones->getColor() == true)
		Peones[i].pintar("imagenes/peonblanco.png", "imagenes/peonnblanco.png", "imagenes/peonnegro.png", "imagenes/peonnnegro.png", 0 + j, 2);
		else
		Peones[i].pintar("imagenes/peonblanco.png", "imagenes/peonnblanco.png", "imagenes/peonnegro.png", "imagenes/peonnnegro.png", 0 + j, 7);
		j++;
	}
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
