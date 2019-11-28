#ifndef COMIDA_H_
#define COMIDA_H_

#include"libs.h"

class food{
	private:
		nivel comida;
		color rgb[3];
		pos x;
		pos y;
	public:
		food(pos equis, pos ye){
			x = equis;
			y = ye;
		}
		void perder_comida();
		virtual ~food(){}

};
#endif
