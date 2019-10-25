#ifndef OBJETOS_H_
#define OBJETOS_H_
#include"algoritmos.h"
#include"matriz.h"
#include<vector>
using coordenadas=int;
using longitud=double;

class punto_t{
	private:
	coordenadas pos_x;
	coordenadas pos_y;
	
	public:
	punto_t();
	punto_t(int x, int y);
	coordenadas get_x();
    coordenadas get_y();
    longitud get_distancia(punto_t otro_punto);
};

typedef float medi;
class hormiga{
	protected:
		int color[3];
		int vida;
		int gen;
		int posx;
		int posy;
		std::vector<std::vector<int>> tam;
	public:
		hormiga(){}
		~hormiga(){}
};
class insecto{
	private:
		int color[3];
		int vida = 50;
		int posx;
		int posy;
		std::vector<std::vector<int>> tam;
	public:
		insecto(){}
		~insecto(){}
		void movimiento();
};
class mundo{
	private:
		medi ncol;
		medi nfil;
		std::vector<std::vector<medi>> espacio;
		std::vector<std::vector<medi>> humedad;
	public:
		mundo(){}
		void set_nfilcol(medi y, medi x);
		void set_mundo();
		~mundo(){}
};
#endif
