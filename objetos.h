#ifndef OBJETOS_H_
#define OBJETOS_H_
#include"algoritmos.h"
#include"matriz.h"
#include<vector>
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
		virtual ~hormiga(){}

		int get_vida();
		int get_gen();
		int get_x();
		int get_y();
		int input();
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
class obrera: public hormiga{
	public:
		obrera(){}
		void movimiento();
	 	~obrera(){}
};
class soldado: public hormiga{
	public:
		soldado(){}
		void movimiento();
		~soldado(){}
};
class reina: public hormiga{
	public:
		reina(){}
		void movimiento();
		~reina(){}
};
#endif
