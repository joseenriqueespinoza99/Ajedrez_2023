#include <iostream>
#include "caballo.h"
#include "Tablero.h"

caballo caballo1;
using namespace std;

void caballo::mueveCab() {
	caballo posAct[2]{ fila, columna };
	//caballo se mueve en L, avanza 2 y luego 1, nunca nada vertical
	int k; //incrementos de posicion
	
	switch (k) {
	case 1:
		if (movH = 'd') {
			if (movV = 'r') {
				caballo posSig[2]{ posAct[fila + 1, columna + 2] };
			}
		else if(movV = 'a') caballo posSig[2]{ posAct[fila + 2, columna + 1] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
		break;

	case 2:
		if (movH = 'i') {
			if (movV = 'r') {
				caballo posSig[2]{ posAct[fila + 2, columna - 1] };
			}
			else if (movV = 'a') caballo posSig[2]{ posAct[fila + 1, columna - 2] };
			else cout << "Movimiento erroneo";
		}
		else cout << "Movimiento erroneo";
		break;
	}


	}


	


