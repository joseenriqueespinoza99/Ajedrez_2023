#include <iostream>
#include "caballo.h"
#include "Tablero.h"
#pragma once 

caballo caballo1;
using namespace std;

void caballo::mueveCab() {
	caballo posAct[2]{ fila, columna };
	//caballo se mueve en L, avanza 2 y luego 1
	//incrementos de posicion
	switch (k) {
	case 1:
		//si va hacia la derecha y solo cambia 1 fila y 2 columnas
		if (movH == "rd") {
			if (movV = 'a') caballo posSig[2]{ posAct[fila + 1, columna + 2] };	
			else if(movV = 'd') caballo posSig[2]{ posAct[fila - 1, columna + 2] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
		break;

	case 2:
		//si va hacia la izquierda  y solo cambia 1 fila y 2 columnas
		if (movH == "ri") {
			if (movV = 'a') caballo posSig[2]{ posAct[fila - 1, columna - 2] };		
			else if (movV = 'd') caballo posSig[2]{ posAct[fila + 1, columna - 2] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
		break;
	case 3:
		//derecha y solo cambia 2 filas 1 columna
		if (movH == "nd") {
			if (movV = 'a') caballo posSig[2]{ posAct[fila - 2, columna + 1] };
			else if (movV = 'd') caballo posSig[2]{ posAct[fila + 2, columna + 1] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
		break;
	case 4:
		//izquierda, solo cambia 2 filas y 1 columna
		if (movH == "ni") {
			if (movV = 'a') caballo posSig[2]{ posAct[fila + 2, columna - 1] };
			else if (movV = 'd') caballo posSig[2]{ posAct[fila - 2, columna - 1] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
	}
	


	}

bool caballo::comprobacion(int x, int y) {
	//si hay 2 casillas de diferencia entre columna inicial y final y 1 entre filas sera correcto
	//x =  posSig[0];
	//y = posSig[1];

	caballo posSig[2]{ x,y };

	if ((x - fila) == 1 && ((y - columna) == 2)) {
		return true;
	}
	//si hay 2 casillas de diferencia entre fila inicial y final y 1 entre las columnas sera correcto
	else if ((x - fila) == 2 && ((y - columna) == 1)) {
		return true;
	}
	else return false;
}

	


