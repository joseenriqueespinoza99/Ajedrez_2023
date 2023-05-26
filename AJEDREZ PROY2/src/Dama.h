#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Dama:public Pieza{
public:
	Dama() {} //Constructor predeterminado
	Dama(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar las damas
	void mueve(unsigned char key)override{}
	bool esmovimientoValido(int x_destino, int y_destino, int comer) override; // Para determinar los movimientos válidos de la dama
	void mover(int x, int y, int comer)override; // Para mover a la dama de donde estaba a la nueva posición
	TipoPieza getClass() const override { return TipoPieza::REINA; } // Para determinar que la dama es una REINA en la enumeracion
};

