#pragma once
#include "Tablero.h"
#include <iostream>
#include "freeglut.h"
#include "ListaPiezas.h"

class Pieza
{
protected:
	int x;
	int y;
	bool  color;//para diferenciar de que tipo de piezas se trata
	enum enum_piezas { TORRE = 1, CABALLO = 2, ALFIL = 3, DAMA = 4, REY = 5, PEON = 6 };
public:
	void setpos(int i, int j);
	//void mueve();
	virtual void dibuja();
};

