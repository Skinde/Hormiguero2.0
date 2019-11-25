#ifndef HORMI_H_
#define HORMI_H_

#include"libs.h"
#include"hormiguero.h"
#include"comida.h"
#include"insecto.h"

class hormiga{
	protected:
		pos x;
		pos y;
		pos lx;
		pos ly;
		color rgb[3];
		nivel humedad;
		nivel vida;
		nivel dano;
	public:
		virtual hormiga(){}
		virtual void posicionamiento() = 0;
		virtual void movimiento()=0;
		void recibir_dano();
		template <typename T>
		void ataque(T& objeto){
			objeto.recibir_dano(dano);
		}
		virtual void vivir()=0;
		void morir(){
			comida
		}
		virtual ~hormiga(){}

};

class reina: public hormiga{
	private:
		nivel comida;
		std::vector<hormiga*> hormigas;
	public:
		reina();
		void posicionamiento(pos equis, pos ye) override;
		void movimiento(std::vector<std::vector<nivel>> matriz) override;
		void poner_obrera();
		void poner_soldado();
		void poner_reina();
		void crear_hormiguero();
		void vivir() override;
		virtual ~reina(){}
};

class soldado: public hormiga{
	public:
		soldado();
		void posicionamiento(pos equis, pos ye) override;
		void movimiento(std::vector<std::vector<nivel>> matriz) override;
		void vivir() override;
		virtual ~soldado(){}
};

class obrera: public hormiga{
	private:
		bool comida;
		nivel carga;
	public:
		obrera();
		void posicionamiento(pos equis, pos ye) override;
		void movimiento(std::vector<std::vector<nivel>> matriz) override;
		void vivir() override;
		void recolectar_comida();
		virtual ~obrera(){}
};

#endif
