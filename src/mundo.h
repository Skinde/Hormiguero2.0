#include"comida.h"
class mundo(){
	private:
		valor x;
		valor y;
		std::vector<comida*> comidas;
		std::vector<std::vector<valor>> terreno;
	public:
		mundo(valor aaa, valor aa){
			x = aaa;
			y = aa;
			terreno = generar_matriz(x, y);
			terreno = 
		}
		void add_comida(pos xw, pos ye){
			comidas.push_back(new comida(xw, ye));
		}
		~mundo(){}
};
