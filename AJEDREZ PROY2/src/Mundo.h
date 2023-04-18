#pragma once
#include "freeglut.h"
#include "Tablero.h"
class Mundo
{
public:
	Tablero t;
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};

