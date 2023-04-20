#pragma once
#include "tablero.h"

class caballo
{
public:
	//parametros para saber donde esta el caballo
	unsigned int fila;
	unsigned int columna;
	int posAct[2];
	int posSig[2];
	char movV;
	char movH;
	void mueveCab();
	
};

