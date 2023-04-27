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
	
public:
	//parametros para saber donde esta el caballo
	virtual ~caballo();
	void mueveCab(char p[2], char z);
	void setx(int xi) { fila = xi; }
	void sety(int yi) { columna = yi; }
	bool comprobacion(int x, int y);
	void dibujaCab();
};

