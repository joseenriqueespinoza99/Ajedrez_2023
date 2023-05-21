#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Alfil :public Pieza {
public:
	Alfil() {};
	Alfil(int x, int y, bool color);
	void dibuja() override;
	void mueve(unsigned char key)override{}
	bool esmovimientoValido(int x_destino, int y_destino, bool comer) override;
	void mover(int x, int y, bool comer)override;
	TipoPieza getClass() const override { return TipoPieza::ALFIL; }

};

