#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"
class Torre:public Pieza
{
private:

public:
	bool casilla_torre;
	Torre();
	//virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja() override;
	void mueve(unsigned char key) override;

	Torre(int x, int y, bool color);
	//nt getValor() { return valor; };
};

