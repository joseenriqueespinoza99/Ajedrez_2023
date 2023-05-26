#pragma once
#include "string.h"
#include <iostream>
#include "Coordenadas.h"
#include "ETSIDI.h"

class Pieza {
private:
    int movimientos = 0; // Para saber si una pieza se ha movido o sigue en su posicion original
protected:
    bool color; // Para diferenciar el color de las piezas
    Coordenadas coordenadas; // Posiciones
    bool modo = false; // Para los distintos tipos de piezas (clasicas o tematicas)

public:
    enum TipoPieza { ALFIL, TORRE, CABALLO, REINA, REY, PEON };
    void setColor(bool c) {color = c;}
    bool getColor() { return color; }

    void setMov() { movimientos++; }
    int getMov() { return movimientos; }

    void setX(int x) { this->coordenadas.x = x; }
    void setY(int y) { this->coordenadas.y = y; }
    int getX() { return coordenadas.x; }
    int getY() { return coordenadas.y; }

    void setModo(bool m) { modo = m; }
    bool getModo() { return modo; }

    
    void dibujar(const char foto[], int x1, int y2); // Para dibujar las piezas en el tablero
    void pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1, int y2); // Para diferenciar entre las piezas en casillas blancas y negras
    
    // Herencia y polimorfismo - a continuación se declaran las funciones abstractas
    virtual void mueve(unsigned char key) = 0;
    virtual void dibuja() = 0;
    virtual bool esmovimientoValido(int x_Destino, int y_Destino, int comer) = 0;
    virtual void mover(int x, int y, int comer) = 0;
    virtual TipoPieza getClass() const = 0;
};


