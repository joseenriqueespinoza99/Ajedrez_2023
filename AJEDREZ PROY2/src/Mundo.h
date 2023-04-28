#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Pieza.h"

class Mundo
{
private:
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


