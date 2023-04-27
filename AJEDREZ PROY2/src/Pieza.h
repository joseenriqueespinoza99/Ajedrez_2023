#pragma once

	class Pieza{
    protected:
        bool color;
        int posx;
        int posy;
	public:
        virtual ~Pieza() {}
        void dibujar(const char foto[], int x1, int y2);
        void pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1, int y2);
      //  virtual void mover() = 0;
        //virtual void dibujar() = 0;
        void setColor(bool c);
        bool getColor(){  return color;}
        int getX()  { return posx; }
        int getY()  { return posy; }
        int setX(int x) { this->posx = x; return x; }
        int setY(int y) { this->posy = y; return y; }
       
	};

