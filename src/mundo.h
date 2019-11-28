#include"comida.h"
class mundo{
	private:
		valor x;
		valor y;
		std::vector<food*> comidas;
		std::vector<std::vector<valor>> terreno;
	public:
		mundo(valor aaa, valor aa){
			x = aaa;
			y = aa;
			terreno = generar_matriz(x, y);
			perlin_generator(terreno);
			imprimir_matriz(terreno);
		}
		void add_comida(pos xw, pos ye){
			comidas.push_back(new food(xw, ye));
		}
		~mundo(){}
};
