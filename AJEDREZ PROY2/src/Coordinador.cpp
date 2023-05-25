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
		ETSIDI::setFont("bin/fuentes/Gameplay.ttf", 14);
		ETSIDI::printxy("Bienvenidos al ajedrez del grupo Termas de Logrono:", -1.5, 8);
		ETSIDI::printxy("Esperemos que disfruten de este juego", -0.5, 6);
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Pulse la letra 'A' para jugar", -0.5, 4);
		ETSIDI::printxy("Pulse la letra 'I' para ver las instrucciones del ajedrez", -0.5, 2);
		//ETSIDI::setTextColor(0, 255, 255);

	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(4, 4, 14,
			4.0, 4.0, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("Jugar al ajedrez es muy sencillo:", -0.55, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("En nuestro ajedrez se juega un jugador contra otro moviendo una serie de piezas", -0.5, 7.0);
		ETSIDI::printxy("Cada pieza tiene sus movimientos caracteristicos", -0.5, 6.0);
		ETSIDI::printxy("Cuando una pieza de un color se pone sobre otra de distinto color diremos que se la come", -0.5, 5.0);
		ETSIDI::printxy("El objetivo es comer el rey del otro color", -0.5, 4.0);
		ETSIDI::printxy("Siempre empezaran jugando las blancas", -0.5, 3.5);
		ETSIDI::printxy("No se pueden atravesar piezas ni poner una sobre otra en la misma casilla", -0.5, 2.5);
		ETSIDI::printxy("Pulse 'A' para jugar, pulse 'Z' para volver al inicio:", -0.5, 1.5);
		/*ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Las piezas del ajedrez son:", -0.5, 2.25);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Peon: mueve hacia delante de 1 en 1", -0.5, 4.0);
		ETSIDI::printxy("Caballo: salta en L", -0.5, 1.5);
		ETSIDI::printxy("Torre: se mueve en horizontal y vertical ", -0.5, 0.75);
		ETSIDI::printxy("Alfil: se mueve en diagonal", -0.5, 2.5);
		ETSIDI::printxy("Dama: se  mueve en horizontal, vertical y diagonal", -0.5, 2.0);
		ETSIDI::printxy("Rey: 1 casilla en cualquier direccion", -0.5, 1.5);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulse 'a' para jugar y 'z' para volver a la pantalla de inicio", -0.5, 1.0);*/
	}
	else if (estado = JUEGO) {
		tablerinyo.inicializa();
		tablerinyo.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Gameplay.ttf", 18);
		ETSIDI::printxy("Electronica vs. Electrica", 0.8, 8.5);

		if (tablerinyo.getPaso() != 0) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("Puedes", -2, 3);
			ETSIDI::printxy("comer", -2, 2);
			ETSIDI::printxy("al paso", -2, 1);
		}

	}
	else if (estado = PAUSA) {
		gluLookAt(4, 4, 14,
			4.0, 4.0, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/Gameplay.ttf", 18);
		ETSIDI::printxy("Has parado el juego", -0.5, 5.0);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Pulse 'A' para volver a reiniciar el juego", -0.5, 4.0);
	}
	else if (estado = FIN) {
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/Gameplay.ttf", 20);
		ETSIDI::printxy("DERROTA HUMILLANTE", -0.5, 5.0);
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
			/*
			case 'G': //fichero solomiya
			case 'g':
				estado=GUARDADA;
				break;
			*/
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
		case 'P':
		case 'p':
			estado = PAUSA;
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
