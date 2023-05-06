#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "freeglut.h"

class Alfil :public Pieza {
private:

public:
	Alfil(int x, int y, bool color);
	
	//bool esmovimientoValido(int x_origen, int y_origen,int x_destino,int y_destino) const override;
	void mueve(unsigned char key)override;
	void dibuja() override;
	bool esmovimientoValido(int x_destino, int y_destino, bool comer) override;
	//void mover(int x_destino, int y_destino);
	void mover(int x, int y, bool comer)override;
	virtual TipoPieza getClass() const override { return TipoPieza::ALFIL; }
};

