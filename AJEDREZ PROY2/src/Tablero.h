#pragma once
#include "ListaPiezas.h"
#include "freeglut.h"
struct posicion{
	int posx;
	int posy;
};
class Tablero
{
private:
	bool casilla_destino;
	bool casilla_origen;
	posicion origen;//sirve para determinar la posición origen
	posicion destino;//sirve para determinar la posicion de destino
	public:
		//definición de constructor
		unsigned char rojo;
		unsigned char verde;
		unsigned char azul;
		void setX_origen(int x) { origen.posx = x; }
		void setY_origen(int y) { origen.posy = y; }
		void setX_destino(int x) { destino.posx = x; }
		void setY_destino(int y) { destino.posy = y; }
		bool getCasilla_origen() { return casilla_origen; }
		bool getCasilla_destino() { return casilla_destino; }
		void dibuja();
		
//Definición del destructor

	};


