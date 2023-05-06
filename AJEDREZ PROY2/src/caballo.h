#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"


class Caballo:public Pieza
{
public:

	Caballo(int x, int y, bool color);
	Caballo() {};
	void dibuja() override;
	void mover(int x, int y) override;
	void mueve(unsigned char key) override;
	bool esmovimientoValido(int x_Destino, int y_Destino);
	void movaje(char p[2], char z);
	virtual TipoPieza getClass() const override { return TipoPieza::CABALLO; }
	bool casilla_cab;

};



