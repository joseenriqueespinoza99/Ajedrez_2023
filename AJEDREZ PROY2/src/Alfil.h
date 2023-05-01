#pragma once
#include "Pieza.h"
class Alfil :public Pieza {
private:

public:
	Alfil(int x, int y, bool color);
	Alfil() {

	};
	//bool esmovimientoValido(int x_origen, int y_origen,int x_destino,int y_destino) const override;
	void mueve(unsigned char key)override;
	void dibuja() override;
	bool esmovimientoValido(int x_Destino, int y_Destino) const;
	//void mover(int x_destino, int y_destino);
	void mover(int x, int y)override;
};
