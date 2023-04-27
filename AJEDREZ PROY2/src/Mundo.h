#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include "Torre.h"
#include "Caballo.h"

class Mundo
{
private:
	//ListaPiezas fichas;
public:
	Tablero t;
	Torre tor;
	Caballo cb;
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};


