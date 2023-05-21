#include "freeglut.h"
#include "Tablero.h"
#include <string>
int casillasDisponibles = 0;
void Tablero::inicializa() {
	x_ojo = 4.0;
	y_ojo = 4.0;
	z_ojo = 14.0;

	//ALFILES
	p[0] = new Alfil(2, 0, true);
	p[1] = new Alfil(5, 0, true);
	p[2] = new Alfil(5, 7, false);
	p[3] = new Alfil(2, 7, false);

	//TORRES	
	p[4] = new Torre(0, 0, true);
	p[5] = new Torre(7, 0, true);
	p[6] = new Torre(0, 7, false);
	p[7] = new Torre(7, 7, false);

	//CABALLOS
	p[8] = new Caballo(1,0 ,true);
	p[9] = new Caballo(6, 0, true);
	p[10] = new Caballo(1, 7, false);
	p[11] = new Caballo(6, 7, false);

	//REYES
	p[12] = new Rey(4, 0, true);
	p[13] = new Rey(4, 7, false);

	//DAMAS
	p[14] = new Dama(3, 0, true);
	p[15] = new Dama(3, 7, false);

	//PEONES
	for (int i = 0; i < 8; i++) {
		p[16 + i] = new Peon(i, 1, true);
		p[24 + i] = new Peon(i, 6, false);
	}
	for (int i = 0; i < 32; i++)
		listapiezas.agregar(p[i]);	
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
	if (piezaSelecc != nullptr) {
		for (int i = 0; i <=7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (piezaSelecc->esmovimientoValido(i, j, 0) == 1) {
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), i, j))
					{
						glPushMatrix();
						glTranslatef(i, j, 0.0); // Posici�n de la casilla disponible
						glBegin(GL_QUADS);
						glColor3f(0.9, 0.9, 0.4); // Color del cuadrado
						glVertex2f(0.05, 0.05);
						glVertex2f(0.95, 0.05);
						glVertex2f(0.95, 0.95);
						glVertex2f(0.05, 0.95);
						glEnd();
						glPopMatrix();
					}
				}
			}
		}
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
void Tablero::seleccionar_pieza(int x, int y) {
	Pieza* nueva_Pieza_Seleccionada = listapiezas.getPieza(x, y);
	if (nueva_Pieza_Seleccionada != nullptr) {
		// mueva a una nueva casilla estando seleccioanda la pieza
		if (piezaSelecc != nullptr) {
			if (listapiezas.getPieza(x, y) != nullptr) {
				// Si la casilla seleccionada est� ocupada, mueve la pieza seleccionada encima de la pieza all� 
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

void Tablero::tecla(unsigned char key)
{
	for (int i = 0; i < listapiezas.getNumero(); i++) {
		listapiezas.getPiezas(i)->mueve(key);
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

bool Tablero::casillaOcupada(int x, int y) {
	Pieza* piezaEnCasilla = listapiezas.getPieza(x, y);
	if (piezaEnCasilla == nullptr) {
		return false; // Casilla vac�a
	}
	else {
		//std::cout << "Esta ocupada";
		return true; // Casilla ocupada
	
	}
}

void Tablero::mover(int x, int y, bool comer) {
	Pieza* piezaDestino = listapiezas.getPieza(x, y);
	if (piezaSelecc != nullptr) {
		// Intentar mover la pieza a la nueva posici�n
		if (casillaOcupada(x, y)) {
			if (piezaDestino != nullptr && (piezaSelecc->getColor() != piezaDestino->getColor())) { // La casilla seleccionada contiene una pieza del equipo contrario
				comer = true;
				if (piezaSelecc->esmovimientoValido(x, y, comer) == 1) { // Mover la pieza seleccionada a esa casilla y eliminar la pieza del equipo contrario
					if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), x, y))
					{
						listapiezas.eliminar(piezaDestino);
						std::cout << "Se est� eliminando la pieza" << std::endl;
						piezaSelecc->mover(x, y, comer);
						
						ETSIDI::play("sonidos/comer.wav");
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
					else
						std::cout << "Hay piezas en el camino. No se puede mover la pieza" << std::endl;
				}
				else {
					std::cout << "Movimiento no v�lido para la pieza" << std::endl;
				}
			}
		}
		else {
			if ((piezaSelecc->esmovimientoValido(x, y, comer) == 1) && (su_turno() == true)) {
				if (!comprobar_camino(piezaSelecc->getX(), piezaSelecc->getY(), x, y))
				{
					comer = false;
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
				else
					std::cout << "Hay piezas en el camino. No se puede mover la pieza" << std::endl;
			}

			else {
				std::cout << "Movimiento no v�lido para la pieza" << std::endl;
			}
		}

		glutPostRedisplay();
	}
}

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


bool Tablero::comprobar_camino(int origen_x, int origen_y, int destino_x, int destino_y) {
	// Verificar si el movimiento es horizontal, vertical o diagonal
	if (origen_x == destino_x || origen_y == destino_y || std::abs(destino_x - origen_x) == std::abs(destino_y - origen_y)) {
		int xmov, ymov;

		if (destino_x > origen_x) {
			xmov = 1;
		}
		else if (destino_x < origen_x) {
			xmov = -1;
		}
		else {
			xmov = 0;
		}

		if (destino_y > origen_y) {
			ymov = 1;
		}
		else if (destino_y < origen_y) {
			ymov = -1;
		}
		else {
			ymov = 0;
		}
		int x = origen_x + xmov;
		int y = origen_y + ymov;

		// Verificar las casillas intermedias en el camino
		while (x != destino_x || y != destino_y) {
			if (casillaOcupada(x, y)) {
				return true; // Hay una pieza en el camino
			}
			x += xmov;
			y += ymov;
		}
	}

	return false; // No hay piezas en el camino
}
