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

void soldado::movimiento(){
	srand(time(NULL));
	double sm = 0;
	for(int i = 0; i < 100; i++){
		int R = log2(rand()%256);
		sm += arr[R];
	}

}
void obrera::movimiento(){

}
void reina::movimiento(){

}

