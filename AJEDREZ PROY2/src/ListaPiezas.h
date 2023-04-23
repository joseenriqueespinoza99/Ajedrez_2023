#pragma once
#include "Pieza.h"
#define MAX_PIEZAS 32

class ListaPiezas
{
	private:
		int numero;
		Pieza* piezas[MAX_PIEZAS];
	public:
		ListaPiezas();
		bool agregar(Pieza* p);
		void eliminar(Pieza* p);
		void dibuja();//permite recorrer la lista de piezas y decirle a cada una de ellas que ejecute su porpio método de dibujar
		//void mueve(float f);//permite recorrer la lista de piezas y decir a cada una de ellas que ejecuten su metodo de moverse
		 //void setpos(int x, int y);
		void destruirContenido();

};

