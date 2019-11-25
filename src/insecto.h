#ifndef INSECTO_H_
#define INSECTO_H_

#include"libs.h"

class insecto{
	private:
		color rgb[3];
		pos x;
		pos y;
		nivel vida;
		nivel dano;
	public:
		insecto(){
			vida = 50.0;
			dano = 30.0;
		}
		void posicionamiento();
		void movimiento();
		void ataque();
		void ataque();
		void ataque();
		void ataque();
		~insecto(){}
};
#endif
