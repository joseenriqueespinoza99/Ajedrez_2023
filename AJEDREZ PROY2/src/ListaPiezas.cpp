#include "ListaPiezas.h"

ListaPiezas::ListaPiezas(){ //constructor
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		piezas[i] = 0;
}

bool ListaPiezas::agregar(Pieza* p) { //para añadir nuevas piezas
	bool iguales = false;
	// comprobamos que la pieza a introducir no ha sido ya introducida
	for (int i = 0; i < numero; i++) {
		if (piezas[i] == p)
			iguales = true;
	}
	// si no ha sido ya introducida y el vector no está lleno
	if ((numero < MAX_PIEZAS) && (iguales == false))
		piezas[numero++] = p; // último puesto sin rellenar 
	else
		return false; // capacidad máxima alcanzada 
	return true;
}

void ListaPiezas::destruirContenido() {
	for (int i = 0; i < numero; i++) // destrucción de las piezas contenidas 
		delete piezas[i];
	numero = 0; // inicializa piezas (reseteo el contador)
} //la llamo cuando se destruya el tablero

void ListaPiezas::eliminar(int index) { //asi al borrar no se quedan huecos en medio, y se actualiza el numero de piezas
	if ((index < 0) || (index >= numero)) //indice erroneo
		return;
	delete piezas[index]; //borro la piezas a la que apuntaba (pero sigue apuntando a ese espacio vacio)
	numero--; //disminuye el numero total de piezas
	for (int i = index; i < numero; i++) //copia lo que apunta el indice en el indice anterior (recoloca las direcciones a las que apunta cada indice)
		piezas[i] = piezas[i + 1];
}

void ListaPiezas::eliminar(Pieza* p) { // eliminación de las piezas
	for (int i = 0; i < numero; i++)
		if (piezas[i] == p) {
			eliminar(i);
			//std::cout << numero << std::endl; //comprobacion de que se eliminan bien las piezas
			return;
		}
}

 Pieza* ListaPiezas::getPieza(int fila, int columna) { // Busca si en unas coordenadas hay una pieza o no y que pieza es
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getX() == fila && piezas[i]->getY() == columna) { // Si las coordenadas de la pieza actual coinciden con las proporcionadas
			return piezas[i];
		}
	}
	return nullptr;
}

void ListaPiezas::reemplazar(Pieza* piezaExistente, Pieza* nuevaPieza) { //Necesario para la coronación
	 for (int i = 0; i < numero; i++) {
		 if (piezas[i] == piezaExistente) {
			 delete piezas[i];  // Liberar memoria de la pieza existente
			 piezas[i] = nuevaPieza;  // Asignar la nueva pieza en su lugar
			 return;
		 }
	 }
 }


 
 
