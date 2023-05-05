#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"
#include "Coordenadas.h"

class Torre:public Pieza {

public:
	bool casilla_torre;
	
	//virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja() override;
	void mueve(unsigned char key) override;
	void mover(int x, int y) override;
	Torre(int x, int y, bool color);
	//nt getValor() { return valor; };
	virtual TipoPieza getClass() const override { return TipoPieza::TORRE; }

	bool esmovimientoValido(int x_Destino, int y_Destino);
};
