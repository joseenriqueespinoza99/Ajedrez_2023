#pragma once
#include "Tablero.h"
#include "caballo.h"
#include "Tablero.h"
#include "Pieza.h"
#include "ListaPiezas.h"

class caballo
{
public:
	bool Color;
	int fila;
	int columna;
	int posAct[2];
	int posSig[2];
public:
	//parametros para saber donde esta el caballo
	caballo(int fila, int columna, bool Color);
	virtual ~caballo();
	char movV;
	char movH[2];
	void mueveCab(char p[2], char z);
	bool comprobacion(int x, int y);
	void dibujaCab();
};

