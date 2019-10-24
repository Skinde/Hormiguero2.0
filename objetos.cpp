#include"objetos.h"
#include<iostream>
void mundo::set_nfilcol(medi x, medi y){
	ncol = x;
	nfil = y;
}
void mundo::set_mundo(){
	espacio = generar_matriz(nfil, ncol);
	perlin_generator(espacio);
	imprimir_matriz(espacio);
}



