#include"objetos.h"
#include<iostream>
//clase punto
punto_t::punto_t(): pos_x(0), pos_y(0) {}
punto_t::punto_t(int x, int y):pos_x(x), pos_y(y) {}
coordenadas punto_t::get_x() {
    return pos_x;
}
coordenadas punto_t::get_y() {
    return pos_y;
}
longitud punto_t::get_distancia(punto_t otro_punto) {
    auto dif_x = (pos_x - otro_punto.pos_x);
    auto dif_y = (pos_y - otro_punto.pos_y);
    return sqrt(dif_x*dif_x + dif_y*dif_y);
}

//clase mundo
void mundo::set_nfilcol(medi x, medi y){
	ncol = x;
	nfil = y;
}
void mundo::set_mundo(){
	espacio = generar_matriz(nfil, ncol);
	perlin_generator(espacio);
	imprimir_matriz(espacio);
}



