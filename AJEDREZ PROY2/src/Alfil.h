#pragma once
#include "Pieza.h"
class Alfil :public Pieza {
private:
	bool color;
	int posx ;
	int posy ;
public:
	Pieza alf;
	Alfil(int posx, int posy, bool color);
	Alfil() {

	};
	int getX() { return posx; }
	int getY() { return posy; }
	void setX(int x) { posx = x; }
	void setY(int y) { posy = y; }
	bool movimientoValido(int filaDestino, int columnaDestino) const;
	void mueve(unsigned char key);
	void dibuja();

};