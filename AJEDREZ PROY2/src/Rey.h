#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"

class Rey:public Pieza{
public:
	Rey(int x, int y, bool color);
	Rey() {};
	void dibuja() override;
	bool esmovimientoValido(int x_destino, int y_destino) override;
	void mover(int x, int y)override;
	virtual TipoPieza getClass() const override { return TipoPieza::REY; }
};
