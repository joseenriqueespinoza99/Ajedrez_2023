#pragma once
#include "tablero.h"

class caballo
{
	//parametros para saber donde esta el caballo
	int fila[8];
	int columna[8];
	int posAct[2];
	int posSig[2];
public:
	int mueveCab(char casilla);
	void comePieza();
};

