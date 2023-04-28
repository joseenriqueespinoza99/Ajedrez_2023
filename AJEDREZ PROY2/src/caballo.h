#pragma once
#include "Tablero.h"

#include "Pieza.h"


class Caballo:public Pieza
{
	
	private:
	

	public:

		Caballo(int xc, int yc, bool color);
		virtual ~Caballo();
		void mover(char p[2], char z) ;
		bool comprobacion(int x, int y);
		bool casilla_cab;
		void dibuja()override;
	};


