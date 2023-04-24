#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"
class Torre
{
private:
	int x;
	int y;
	char color;
public:
	bool casilla_torre;
	Pieza torre;
	//virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja();
	void mueve(unsigned char key);
	
	void setx(int xi) { 
		x = xi;}
	void sety(int yi) { 
		y = yi; }
	int getx() { return x; }
	int gety() { return y; }

	//nt getValor() { return valor; };
};

