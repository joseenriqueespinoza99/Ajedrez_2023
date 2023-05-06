#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"

class Peon :public Pieza {
public:
	Peon(int x, int y, bool color);
	Peon() {};
	void dibuja() override;
	void mueve(unsigned char key) override;
	bool esmovimientoValido(int x_destino, int y_destino) override;
	void mover(int x, int y) override;
	virtual TipoPieza getClass() const override { return TipoPieza::PEON; }
};

