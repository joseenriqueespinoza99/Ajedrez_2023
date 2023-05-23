#include "Coordinador.h"

Coordinador::Coordinador(){
	estado = INICIO;
}

void Coordinador::dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Bienvenidos al ajedrez del grupo Termas de Logrono:", -19, 31);
		ETSIDI::printxy("Esperemos que disfruten de este juego", -17, 25);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Pulse 'a' para jugar", -12, 29);
		ETSIDI::printxy("Pulse 'i' para ver las instrucciones del ajedrez", -12, 28);
		ETSIDI::setTextColor(0, 255, 255);
		
	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 10, 30, 
			0.0, 10, 0.0, 
			0.0, 1.0, 0.0); 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Jugar al ajedrez es muy sencillo:", -13, 31);	
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("En nuestro ajedrez se juega un jugador contra otro moviendo una serie de piezas", -12, 29);
		ETSIDI::printxy("Cada pieza tiene sus movimientos caracteristicos", -12, 28);
		ETSIDI::printxy("Cuando una pieza de un color se pone sobra otra de distinto color diremos que se la come", -12, 27);
		ETSIDI::printxy("El objetivo es comer el rey del otro color", -12, 26);
		ETSIDI::printxy("Simpre empezaran jugando las blancas", -12, 25);
		ETSIDI::printxy("No se pueden atravesar piezas ni poner una sobre otra en la misma casilla", -12, 24);
		ETSIDI::setTextColor(0, 0, 204);
		ETSIDI::printxy("Las piezas del ajedrez son:", -12, 23);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::printxy("Peon: mueve hacia delante de 1 en 1", -12, 22);
		ETSIDI::printxy("Caballo: salta en L", -12, 21);
		ETSIDI::printxy("Torre: se mueve en horizontal y vertical ", -12, 20);
		ETSIDI::printxy("Alfil: se mueve en diagonal", -12, 19);
		ETSIDI::printxy("Dama: se  mueve en horizontal, vertical y diagonal", -12, 18);
		ETSIDI::printxy("Rey: 1 casilla en cualquier direccion", -12, 17);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulse 'a' para jugar y 'z' para volver a la pantalla de inicio", -12, 16);
	}
}

void Coordinador::eleccion(unsigned char elec) {
	if(estado==INICIO){
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
			case 'G':
			case 'g':
				estado=GUARDADA;
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
		tablerinyo.inicializa();
	}
}

