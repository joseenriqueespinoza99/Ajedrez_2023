#pragma once
#include "Tablero.h"
#include "Coordenadas.h"
#include "Pieza.h"


class Caballo:public Pieza
{
	
	public:

		Caballo(int x, int y, bool color);
		virtual ~Caballo();
		void dibuja() override;
		void mover(int x, int y) override;
		void mueve(unsigned char key) override;
		void movaje(char p[2], char z) ;
		bool comprobacion(int x, int y);
		bool casilla_cab;
		void dibuja()override;
	};


