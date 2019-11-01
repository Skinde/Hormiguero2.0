#ifndef OBJETOS_H_
#define OBJETOS_H_
#include"algoritmos.h"
#include"matriz.h"
#include<vector>
typedef float medi;
class hormiga{
	protected:
		int color[3];
		medi vida;
		int gen;
		int posx;
		int posy;
		int lposy;
		int lposx;
		medi ataque;
		std::vector<std::vector<int>> tam;
	public:
		hormiga(){}
		virtual ~hormiga(){}
};

class food{
	private:
	public:
		food(){}
		virtual ~food(){}


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
		virtual ~insecto(){}
		void movimiento();
};

class mundo{
	private:
		medi ncol;
		medi nfil;
		std::vector<std::vector<medi>> espacio;
		std::vector<std::vector<medi>> humedad;
		std::vector<std::vector<medi>> feromonas;
	public:
		mundo(){}
		void set_nfilcol(medi y, medi x);
		void set_mundo();
		void set_feromonas();
		virtual ~mundo(){}
};

class obrera: public hormiga{
	private:
		bool comida = false;
	public:
		obrera(){ 
			vida = 30.0;
			ataque = 2.0;
		}
		void movimiento(std:vector<std::vector<float>> matriz);
	 	virtual ~obrera(){}
};

class soldado: public hormiga{
	public:
		soldado(){
			vida = 100.0;
			ataque = 50.0;
		}
		void movimiento(std::vector<std::vector<float>> matriz);
		virtual ~soldado(){}
};

class reina: public hormiga{
	private:
		std::vector<obrera> obreras;
		std::vector<soldado> soldados;
	public:
		reina(){
			vida = 200.0;
			ataque = 0.0;
		}
		void posicionamiento();
		void crear_obrera();
		void crear_soldado();
		void crear_reina();
		void movimiento(std::vector<std::vector<float>> matriz);
		virtual ~reina(){}
};
#endif
