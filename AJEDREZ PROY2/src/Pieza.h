#pragma once

	class Pieza{
    protected:
        bool color;
        int posx;
        int posy;
	public:
       
        virtual ~Pieza() {}
        virtual void dibuja() const = 0;
        virtual void mover() = 0;
        bool getColor() const {  return color;}
        int getX() const { return posx; }
        int getY() const { return posy; }
        void setX(int x) {this->posx = x; }
        void setY(int y) {   this->posy = y; }
       
	};

