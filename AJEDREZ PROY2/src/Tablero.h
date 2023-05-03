#pragma once
#include "ListaPiezas.h"
#include "freeglut.h"
#include "Posicion.h"
#include "Pieza.h"
#include "ETSIDI.h"
struct posicion{
	int posx;
	int posy;
};
class Tablero
{
private:
	posicion origen;//sirve para determinar la posición origen
	posicion destino;//sirve para determinar la posicion de destino
	
	public:
		Tablero();
		void setX_origen(int x) { origen.posx = x; }
		void setY_origen(int y) { origen.posy = y; }
		void setX_destino(int x) { destino.posx = x; }
		void setY_destino(int y) { destino.posy = y; }
		void getX_origen(int x) { origen.posx = x; }
		void getY_origen(int y) { origen.posy = y; }
		void getX_destino(int x) { destino.posx = x; }
		void getY_destino(int y) { destino.posy = y; }
		void dibuja();
		void inicializa();
		void mueve(unsigned char key);
		void seleccionar_pieza(int x, int y);
		void mover(int x, int y);
		bool casillaOcupada(int x, int y);
	
//Definición del destructor
	};
