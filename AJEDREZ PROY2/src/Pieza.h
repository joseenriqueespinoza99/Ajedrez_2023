#pragma once
#include "string.h"
#include <iostream>
#include "Coordenadas.h"
#include "ETSIDI.h"

class Pieza {
private:
      int movimientos = 0; //para saber si una pieza se ha movido o sigue en su posicion original
protected:
    bool color;
    Coordenadas coordenadas;

public:
    //virtual ~Pieza() {} 
    enum TipoPieza { ALFIL, TORRE, CABALLO, REINA, REY, PEON };
    void setColor(bool c) {color = c;}
    bool getColor() { return color; }

    void setMov() { movimientos++; }
    int getMov() { return movimientos; }

    void setX(int x) { this->coordenadas.x = x; }
    void setY(int y) { this->coordenadas.y = y; }
    int getX() { return coordenadas.x; }
    int getY() { return coordenadas.y; }

    //para diferenciar entre las piezas en casillas blancas y negras
    void dibujar(const char foto[], int x1, int y2);
    void pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1, int y2);
    

    virtual void mueve(unsigned char key) = 0;
    virtual void dibuja() = 0;
    virtual bool esmovimientoValido(int x_Destino, int y_Destino, int comer) = 0;
    virtual void mover(int x, int y, int comer) = 0;
    virtual TipoPieza getClass() const = 0;
        
    


    
    //friend class ListaPiezas;//las hacemos amigas para que puedan acceder a los atributo privados de la otra clase
};


