#pragma once

struct posicion{
	int posx;
	int posy;
};
class Tablero
{
private:
	bool casilla_destino;
	bool casilla_origen;
	posicion origen;
	posicion destino;
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


