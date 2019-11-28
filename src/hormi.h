#ifndef HORMI_H_
#define HORMI_H_

#include"libs.h"
#include"comida.h"
#include"insecto.h"

class hormiga{
	protected:
		tamano w;
		tamano h;
		pos x;
		pos y;
		pos lx;
		pos ly;
		color rgb[3];
		nivel vida;
		nivel dano;
	public:
		hormiga(tamano e, tamano o, pos eq, pos ye, nivel live, nivel ouch);
		virtual void movimiento(std::vector<std::vector<nivel>> matriz)=0;
		void recibir_dano();
		template <typename T>
		void ataque(T& objeto){
	        	objeto.recibir_dano(dano);
		}
		virtual void vivir(std::vector<std::vector<nivel>> matriz)=0;
		void morir(){}
		virtual ~hormiga(){}

};

class reina: public hormiga{
	private:
		tipo gen;
		nivel humedad;
		nivel variacion;
		nivel comida;
		std::vector<hormiga*> hormigas;
	public:
		reina(pos equis , pos ye);
		reina( pos w, pos u, nivel var);
		void movimiento(std::vector<std::vector<nivel>> matriz);
		void poner_obrera();
		void poner_soldado();
		void poner_reina(std::vector<reina*> reinas);
		void vivir(std::vector<std::vector<nivel>> matriz);
		virtual ~reina(){}
};

class soldado: public hormiga{
	public:
		soldado( pos w, pos u);
		void movimiento(std::vector<std::vector<nivel>> matriz);
		void vivir(std::vector<std::vector<nivel>> matriz);
		virtual ~soldado(){}
};

class obrera: public hormiga{
	private:
		bool comida;
		nivel carga;
	public:
		obrera(pos w, pos u);
		void movimiento(std::vector<std::vector<nivel>> matriz);
		void vivir(std::vector<std::vector<nivel>> matriz);
		void recolectar_comida();
		virtual ~obrera(){}
};

#endif
