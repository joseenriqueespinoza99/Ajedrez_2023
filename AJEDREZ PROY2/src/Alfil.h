#pragma once
#include "Pieza.h"
class Alfil :public Pieza {
private:
public:
	Alfil(int posx, int posy, bool color);
	bool movimientoValido(int filaDestino, int columnaDestino) const;
	void move(int i, int j);
};