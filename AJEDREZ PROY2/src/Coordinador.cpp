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

	
}