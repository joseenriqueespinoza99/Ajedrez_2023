#pragma once
#include "Pieza.h"
#include "freeglut.h"
#include "Tablero.h"

class Peon :public Pieza {
public:
	Peon() {};
	Peon(int x, int y, bool color);
	void dibuja() override;
	void mueve(unsigned char key) override{}
	bool esmovimientoValido(int x_destino, int y_destino, int comer) override;
	void mover(int x, int y, int comer) override;
	TipoPieza getClass() const override { return TipoPieza::PEON; }
};

