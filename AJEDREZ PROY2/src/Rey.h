#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Rey :public Pieza {
public:
	Rey() {} //Constructor predeterminado
	Rey(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar los reyes
	void mueve(unsigned char key) override{}
	bool esmovimientoValido(int x_destino, int y_destino, int comer) override; // Para determinar los movimientos válidos del rey
	void mover(int x, int y, int comer)override; // Para mover al rey de donde estaba a la nueva posición
	TipoPieza getClass() const override { return TipoPieza::REY; } // Para determinar que el rey es un REY en la enumeracion
};