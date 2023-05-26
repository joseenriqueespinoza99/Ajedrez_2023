#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Alfil :public Pieza {
public:
	Alfil() {} //Constructor predeterminado
	Alfil(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar los alfiles
	void mueve(unsigned char key)override{}
	bool esmovimientoValido(int x_destino, int y_destino, int comer) override; // Para determinar los movimientos válidos del alfil
	void mover(int x, int y, int comer)override; // Para mover al alfil de donde estaba a la nueva posición
	TipoPieza getClass() const override { return TipoPieza::ALFIL; } // Para determinar que el alfil es un ALFIL en la enumeracion
};


