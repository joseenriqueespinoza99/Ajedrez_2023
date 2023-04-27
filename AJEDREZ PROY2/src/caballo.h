#pragma once
#include "Tablero.h"
#include "caballo.h"
#include "Tablero.h"
#include "Pieza.h"
#include "ListaPiezas.h"

class Caballo:public Pieza
{
	
	private:
		bool Color;
		int fila;
		int columna;

	public:

		Pieza caballo;
		Caballo(int xc, int yc, bool color);
		virtual ~Caballo();
		void mueveCab(char p[2], char z);
		void setx(int xi) { fila = xi; }
		void sety(int yi) { columna = yi; }
		int Getx() { return fila; }
		int Gety() { return columna; }
		bool comprobacion(int x, int y);
		bool casilla_cab;
		void dibujaCab();
	};


