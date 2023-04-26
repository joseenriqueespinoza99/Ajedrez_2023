#pragma once
#include "Tablero.h"

class caballo
{
public:
	//parametros para saber donde esta el caballo
	int fila;
	int columna;
	int posAct[2];
	int posSig[2];
	char movV;
	char movH[2];
	void mueveCab();
	bool comprobacion(int x, int y);
};

