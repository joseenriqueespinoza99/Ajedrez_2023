#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Torre:public Pieza {
public:
	Torre() {};
	Torre(int x, int y, bool color);
	void dibuja() override;
	void mueve(unsigned char key) override {}
	bool esmovimientoValido(int x_Destino, int y_Destino, int comer);
	void mover(int x, int y, int comer) override;
	TipoPieza getClass() const override { return TipoPieza::TORRE; }
};
