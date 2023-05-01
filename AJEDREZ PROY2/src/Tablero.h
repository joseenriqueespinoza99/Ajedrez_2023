#pragma once
#define MAX_PIEZAS 32
#include "ListaPiezas.h"
#include "freeglut.h"
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
	bool turno;
	bool final;
	ListaPiezas listapiezas;
	public:
	Tablero();
	Pieza* casillaOcupaBlanca[MAX_PIEZAS / 2];
	Pieza* casillaOcupaNegra[MAX_PIEZAS / 2];
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
		bool EspacioBlancas(Pieza* c);
		bool EspacioNegras(Pieza* c);
		bool EspacioCasilla(Pieza* p);
		void cambiarTurno();
//Definición del destructor
	};
