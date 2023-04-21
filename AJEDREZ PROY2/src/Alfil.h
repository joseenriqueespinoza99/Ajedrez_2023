#pragma once
#include "Pieza.h"
class Alfil : public Pieza {
private:

public:
	Alfil(int x, int y, bool color);
	bool movimientoValido(int filaDestino, int columnaDestino) const;
	void move(int i, int j);
};