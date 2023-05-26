#include "Coordinador.h"

Coordinador::Coordinador() {
	estado = INICIO;
	ETSIDI::playMusica("sonidos/ambiente.mp3", true);
}

void Coordinador::dibuja() {
	if (estado == INICIO) {
		gluLookAt(4, 4, 14,
			4.0, 4.0, 0.0,
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 14);
		ETSIDI::printxy("Bienvenidos al ajedrez del grupo Termas de Logrono:", -2, 8);
		ETSIDI::printxy("Esperemos que disfruten de este juego", -2, 6);
		ETSIDI::setTextColor(1, 0.6, 0.5);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 14);
		ETSIDI::printxy("Pulse la letra 'A' para jugar", -2, 4);
		ETSIDI::printxy("Pulse la letra 'I' para ver las instrucciones del ajedrez", -2, 2);
	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(4, 4, 14,
			4.0, 4.0, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 15);
		ETSIDI::printxy("Jugar al ajedrez es muy sencillo:", -0.55, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Gameplay.ttf", 9);
		ETSIDI::printxy("En nuestro ajedrez se juega un jugador contra otro moviendo una serie de piezas", -2.3, 7.0);
		ETSIDI::printxy("Cada pieza tiene sus movimientos caracteristicos", -2.3, 6.0);
		ETSIDI::printxy("Cuando una pieza de un color se pone sobre otra de distinto color diremos que se la come", -2.3, 5.0);
		ETSIDI::printxy("El objetivo es comer el rey del otro color", -2.3, 4.0);
		ETSIDI::printxy("Siempre empezaran jugando las blancas", -2.3, 3.5);
		ETSIDI::printxy("No se pueden atravesar piezas ni poner una sobre otra en la misma casilla", -2.3, 2.5);
		ETSIDI::printxy("Para enrocar: pulsar sobre el rey a mover y luego la celda donde se quiere mover este", -2.3, 1.5);
		ETSIDI::printxy("Pulse 'A' para jugar, pulse 'Z' para volver al inicio:", -2.3, 0.5);

	}
	
	else if (estado = JUEGO) {
		tablerinyo.inicializa();
		tablerinyo.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		if (tablerinyo.getModoT() == false) {
			ETSIDI::setFont("fuentes/Gameplay.ttf", 18);
			ETSIDI::printxy("Electronica vs. Electrica", 0.8, 8.5);
		}
		else if (tablerinyo.getModoT() == true) {
			ETSIDI::setFont("fuentes/Gameplay.ttf", 18);
			ETSIDI::printxy("Electronica vs. Electrica", 0.8, 8.5);
		}
		ETSIDI::setFont("fuentes/Gameplay.ttf", 10);
		ETSIDI::printxy("'T'Piezas tematicas", 8, 8);
		ETSIDI::printxy("'C'Piezas clasicas", 8, 7);
		if (tablerinyo.getJaqueMate())
		{
			ETSIDI::setTextColor(1, 0, 0);
			ETSIDI::setFont("fuentes/Gameplay.ttf", 20);
			ETSIDI::printxy("DERROTA HUMILLANTE", 0, 5.0);

		}
		if (tablerinyo.getPaso() != 0) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("Puedes", -2, 3);
			ETSIDI::printxy("comer", -2, 2);
			ETSIDI::printxy("al paso", -2, 1);
		}
		if (tablerinyo.getEnroqueC() == 1) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("Puedes", -2, 4);
			ETSIDI::printxy("hacer", -2, 3);
			ETSIDI::printxy("enroque", -2, 2);
			ETSIDI::printxy("corto", -2, 1);
		}
		if (tablerinyo.getEnroqueL() == 1) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("Puedes", -2, 4);
			ETSIDI::printxy("hacer", -2, 3);
			ETSIDI::printxy("enroque", -2, 2);
			ETSIDI::printxy("largo", -2, 1);
		}
		if (tablerinyo.getCoronar() != 0) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("Peon", -2, 3);
			ETSIDI::printxy("Coronado", -2, 2);
		}
		
	}
	
}

void Coordinador::eleccion(unsigned char elec) {
	if (estado == INICIO) {
		switch (elec) {
		case 'a':
		case 'A':
			estado = JUEGO;
			break;
		case 'i':
		case 'I':
			estado = INSTRUCCIONES;
			break;
		}
	}
	else if (estado == INSTRUCCIONES) {
		switch (elec) {
		case 'z':
		case 'Z':
			estado = INICIO;
			break;
		case 'a':
		case 'A':
			estado = JUEGO;
			break;
		}
	}
	else if (estado == JUEGO) {
		switch (elec) {
		case 'T':
		case 't':
			tablerinyo.setModoT(false);
			break;
		case 'C':
		case 'c':
			tablerinyo.setModoT(true);
			break;
		}
	}
	else if (estado == FIN) {
		tablerinyo.dibuja();

	}
}

void Coordinador::mueve() {
	tablerinyo.mueve();
}

void Coordinador::coord_a_celda(int x, int y) {
	tablerinyo.coord_a_celda(x, y);
}
