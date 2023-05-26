#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Caballo:public Pieza {
public:
	Caballo() {} //Constructor predeterminado
	Caballo(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar los caballos
	void mueve(unsigned char key) override{}
	bool esmovimientoValido(int x_Destino, int y_Destino, int comer) override; // Para determinar los movimientos válidos del caballo
	void mover(int x, int y, int comer) override; // Para mover al caballo de donde estaba a la nueva posición
	TipoPieza getClass() const override { return TipoPieza::CABALLO; } // Para determinar que el caballo es un CABALLO en la enumeracion
};

