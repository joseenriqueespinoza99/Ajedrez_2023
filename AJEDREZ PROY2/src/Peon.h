#pragma once
#include "Pieza.h"
#include "freeglut.h"

class Peon :public Pieza {
public:
	Peon() {} //Constructor predeterminado
	Peon(int x, int y, bool color); // Constructor
	void dibuja() override; // Para dibujar los peones
	void mueve(unsigned char key) override{}
	bool esmovimientoValido(int x_destino, int y_destino, int comer) override; // Para determinar los movimientos v�lidos del peon
	void mover(int x, int y, int comer) override; // Para mover al peon de donde estaba a la nueva posici�n
	TipoPieza getClass() const override { return TipoPieza::PEON; } // Para determinar que el peon es un PEON en la enumeracion
};

