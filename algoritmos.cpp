#include"algoritmos.h"
#include<cmath>
float perlin(float x){

	if(x <= 0.0)
		x = 0.0;
	else if(x<1.0)
		x = 6*pow(x,5)-15*pow(x,4)+10*pow(x,3);
	else if(x == 1.0)
		x = 1.0;
	return x;

}
