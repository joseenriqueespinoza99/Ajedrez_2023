#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
class Mundo
{
private:
	//ListaPiezas fichas;
public:
	Tablero t;
	Alfil* alfiles = new Alfil(3, 0, true);
	Torre* torres = new Torre(0, 0, false);
	Caballo* caballos = new Caballo(4, 0, false);
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};


