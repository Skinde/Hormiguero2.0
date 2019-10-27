#include"objetos.h"
#include<iostream>
#include <fstream>

int hormiga::get_vida(){
	return vida;
}

int hormiga::get_gen(){
	return gen;
}

int hormiga::get_x(){
	return posx;
}

int hormiga::get_y(){
	return posy;
}

int hormiga::input(){
	//creating file
	std::ofstream myfile;
	//opening the file
	myfile.open("save.txt", std::ios::app);
	//creating a object
	hormiga obj;
	//assigning the atributes to the created object
	obj.color= color;
	obj.vida=vida;
	obj.gen=gen;
	obj.posx=posx;
	obj.posy= posy;
	//saving the object in the file
	myfile.write((char*)&obj, sizeof(obj));
	obj.~hormiga();
	return 0;
}

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

