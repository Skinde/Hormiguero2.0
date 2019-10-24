#include<iostream>
#include"objetos.h"

int main(){
	mundo matriz;
	float x, y;
	std::cin>>y >> x;
	
	matriz.set_nfilcol(y, x);
	matriz.set_mundo();

	return 0;
}
