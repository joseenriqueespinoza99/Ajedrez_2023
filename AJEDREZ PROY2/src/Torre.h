#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Torre:public Pieza {
public:
	Torre() {} //Constructor predeterminado
	Torre(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar las torres
	void mueve(unsigned char key) override {}
	bool esmovimientoValido(int x_Destino, int y_Destino, int comer) override; // Para determinar los movimientos válidos de la torre
	void mover(int x, int y, int comer) override; // Para mover a la torre de donde estaba a la nueva posición
	TipoPieza getClass() const override { return TipoPieza::TORRE; } // Para determinar que la torre es una TORRE en la enumeracion
};