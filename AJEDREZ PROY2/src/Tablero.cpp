#include "freeglut.h"
#include "Tablero.h"

void Tablero::inicializa() {
	x_ojo = 4.0;
	y_ojo = 4.0;
	z_ojo = 14.0;

	//blancas
	pB[0] = new Alfil(2, 0, true);
	pB[1] = new Alfil(5, 0, true);
	pB[2] = new Torre(0, 0, true);
	pB[3] = new Torre(7, 0, true);
	pB[4] = new Caballo(1, 0, true);
	pB[5] = new Caballo(6, 0, true);
	pB[6] = new Rey(4, 0, true);
	pB[7] = new Dama(3, 0, true);

	//negras
	pN[0] = new Alfil(5, 7, false);
	pN[1] = new Alfil(2, 7, false);
	pN[2] = new Torre(0, 7, false);
	pN[3] = new Torre(7, 7, false);
	pN[4] = new Caballo(1, 7, false);
	pN[5] = new Caballo(6, 7, false);
	pN[6] = new Rey(4, 7, false);
	pN[7] = new Dama(3, 7, false);

	//PEONES
	for (int i = 0; i < 8; i++) {
		pB[8 + i] = new Peon(i, 1, true);
		pN[8 + i] = new Peon(i, 6, false);
	}
	for (int i = 0; i < 16; i++) {
		listapiezas.agregar(pN[i]);
		listapiezas.agregar(pB[i]);
	}
}


void Tablero::dibuja() {
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	//aqui es donde hay que poner el codigo de dibujo
	if (piezaSelecc != nullptr) {//dibujar 
		glLineWidth(4.0);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(piezaSelecc->getX(), piezaSelecc->getY());
		glVertex2f(piezaSelecc->getX() + 1, piezaSelecc->getY());
		glVertex2f(piezaSelecc->getX() + 1, piezaSelecc->getY() + 1);
		glVertex2f(piezaSelecc->getX(), piezaSelecc->getY() + 1);
		glEnd();
	}
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		listapiezas.getPiezas(i)->dibuja();
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Coordenadas p{ i + 1, j + 1 };
			int indices = i + j;
			if ((indices % 2) == 0) {
				glBegin(GL_POLYGON);
				glColor3f(0, 0.5, 0.5);
				glVertex2i(i + 1, j + 1);
				glVertex2i(i + 1, j);
				glVertex2i(i, j);
				glVertex2i(i, j + 1);
				glEnd();
			}
			if ((indices % 2) != 0) {
				glBegin(GL_POLYGON);
				glColor3f(255, 255, 255);
				glVertex2i(i + 1, j + 1);
				glVertex2i(i + 1, j);
				glVertex2i(i, j);
				glVertex2i(i, j + 1);
				glEnd();
			}
		}
	}

}
void Tablero::mueve() {

}

void Tablero::tecla(unsigned char key)
{
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		listapiezas.getPiezas(i)->mueve(key);
	}
}

void Tablero::seleccionar_pieza(int x, int y) {
	Pieza* nueva_Pieza_Seleccionada = listapiezas.getPieza(x, y);
	if (nueva_Pieza_Seleccionada != nullptr) {
		// mueva a una nueva casilla estando seleccioanda la pieza
		if (piezaSelecc != nullptr) {
			if (listapiezas.getPieza(x, y) != nullptr) {
				// Si la casilla seleccionada está ocupada, mueve la pieza seleccionada encima de la pieza allí 
				//dentro de la funcion mover se elimina la esa pieza que esta debajo de la lista
				mover( x, y, 0);
				piezaSelecc = nullptr;
			}
			else {
				// mueve la pieza si la casilla seleccionada esta vacia
				mover( x, y, 0);
				piezaSelecc = nullptr;
			}
		}
		else {
			// No hay ninguna pieza seleccionada, selecciona la pieza en la nueva casilla
			piezaSelecc = nueva_Pieza_Seleccionada;
		}
		
		glutPostRedisplay();

	}

	}
bool Tablero::casillaOcupada(int x, int y) {
	Pieza* piezaEnCasilla = listapiezas.getPieza(x, y);
	if (piezaEnCasilla == nullptr) {
		return false; // Casilla vacía
	}
	else {
		std::cout << "Esta ocupada";
		return true; // Casilla ocupada
	
	}
}

bool Tablero::su_turno() {
	if (piezaSelecc != nullptr) {
		if (piezaSelecc->getColor() == turno) {
			std::cout << "turno = color" << std::endl;
			return true;
		}
		else {
			std::cout << "No le toca a ese color" << std::endl;
			return false;
		}
	}
}

void Tablero::mover(int x, int y, bool comer) {
	Pieza* piezaDestino = listapiezas.getPieza(x, y);
	if (piezaSelecc != nullptr) { 
			// Intentar mover la pieza a la nueva posición
			if (casillaOcupada(x, y)) {
				if (piezaDestino != nullptr && (piezaSelecc->getColor() != piezaDestino->getColor()) && su_turno() == true) { // La casilla seleccionada contiene una pieza del equipo contrario
					comer = 1;
					if (piezaSelecc->esmovimientoValido(x, y, comer) == 1) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario
						listapiezas.eliminar(piezaDestino);
						std::cout << "Se esta eliminando la pieza";
						piezaSelecc->mover(x, y, comer);
						ETSIDI::play("sonidos/comer.wav");
						if (piezaSelecc->getColor() == true) {
							std::cout << "Turno blancas" << std::endl;
							turno = false;
						}
						else{
							std::cout << "Turno negras" << std::endl;
							turno = true;
						}
						piezaSelecc = nullptr;
					}
					else {
						std::cout << "Movimiento no valido para la pieza" << std::endl;
					}
				}
			}
			else {
				if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && su_turno() == true) {
					comer = 0;
					piezaSelecc->mover(x, y, comer);
					ETSIDI::play("sonidos/mover.wav");
					if (piezaSelecc->getColor() == true) {
						std::cout << "Turno blancas" << std::endl;
						turno = false;
					}
					else {
						std::cout << "Turno negras" << std::endl;
						turno = true;
					}
					piezaSelecc = nullptr;
				}
				else {
					std::cout << "Movimiento no valido para la pieza" << std::endl;
				}
			}
		}
	glutPostRedisplay();
}



	




//bool Tablero::comprobar_trayectoria(int or_x, int or_y, int dest_x, int dest_y, bool trayectoria) {
//	for (int i = 0; i < 16; i++) {
//		//alfil (2,3) -> alfil' (3,4) 
//		pN[i]->setX(or_x); //2
//		pN[i]->setY(or_y);//3
//		pB[i]->setX(or_x);
//		pB[i]->setY(or_y);
//		for(int j=0; j<32; j++){
//			dest_x = pN[j]-> setX(coor.x); //3
//			dest_y = pN[j]->setY(coor.y); //4 
//			if (((dest_x - dest_y) == (or_x - or_y))) { // 3-2 = 1, 4-3= 1 -> diagonal
//				trayectoria = true;
//				std::cout << "trayectoria en diagonal" << std::endl;
//				return trayectoria;
//				}
//				//torre, solo en horizontal o vertical 
//				else if ( ((or_x - dest_x == 0 && or_y - dest_y != 0)) ) {
//					trayectoria = true;
//					std::cout << "trayectoria en vertical" << std::endl;
//					return trayectoria;
//
//				}
//				//dama, una mezcla de ambas
//				else if (  ((or_x - dest_x != 0) && (or_y - dest_y == 0))) {
//					trayectoria = true;
//					std::cout << "trayectoria en horizontal" << std::endl;
//					return trayectoria;
//				}
//				//ninguna otra pieza es necesaria
//				else {
//					trayectoria = false;
//					return trayectoria;
//				}
//		}
//
//	}
//}


void Tablero::coord_a_celda(int x, int y)
{
	celda.x = (((x - 163) / 59.5) + 1); // Posicion en x del raton, la separacion a la izquierda desde que empieza la ventana hasta que empieza el tablero (163) y 59.5 el ancho de celda aproximado
	celda.y = (9 - ((y - 61) / 59.5)); // Pos en y del raton, la separacion por arriba desde que empieza la ventana hasta que empieza el tablero (61) y 59.5 el ancho de celda aproximado


	if ((x < 163 || x > 637 || y < 61 || y > 535)) {
		celda = { 0, 0 }; // si se selecciona fuera del tablero
	}
	seleccionar_pieza(celda.x - 1, celda.y - 1);
	destino.x = x;
	destino.y = y;
	mover(celda.x - 1, celda.y - 1, 0);


	//Comprobacion auxiliar (borrar)
//	std::cout << "(" << x << "," << y << ")" << std::endl;
//	std::cout << "(" << celda.x << "," << celda.y << ")" << std::endl; //test para comprobar visualmente que la celda seleccionada es la correcta

}

//Tablero::~Tablero() {
//	//esferas.destruirContenido(); //TODO
//}


