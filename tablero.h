#pragma once
#include "freeglut.h"

class Tablero {
public:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float x;
	float y;
	void pintarTablero();
	void setpos(float ix, float iy);
};
