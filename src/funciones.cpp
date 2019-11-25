#include"funciones.h"

int randint(numero x){
	srand(time(0));
	return rand()%x +1;
}

float randreal(numero x){
	srand(time(0));
	return rand()%x + 1.0;
}
