#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"
class Torre:public Pieza
{
public:
	//bool casilla_torre;
	//virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja() override;
	void mueve(unsigned char key);

	Torre(int x, int y, bool color);
	//nt getValor() { return valor; };
	
	void movimientos();
};
