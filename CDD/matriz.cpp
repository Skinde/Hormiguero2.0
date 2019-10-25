#include "matriz.h"
#include"algoritmos.h"
#include<iostream>
#include<random>
#include<cmath>
typedef float valor;
typedef double scl;
typedef std::random_device device;
typedef std::uniform_real_distribution<scl> distribution;
device dev; 

scl randint(scl first, scl last){
	std::mt19937 gen(dev());
        distribution dis(first, last);
        return dis(gen);
}
std::vector<std::vector<valor>> generar_matriz(valor filas, valor columnas){
        return std::vector<std::vector<valor>> (filas,std::vector<valor>(columnas));
}

void perlin_generator(std::vector<std::vector<valor>> & matriz){
        for( float i = 0.0; i< matriz.size(); i++){
		for( float j = 0.0; j < matriz[i].size(); j++){
			matriz[i][j] = randint(0.0, 1.0);
		}
	}

	
}

void imprimir_matriz(std::vector<std::vector<valor>> matriz){
        for( auto rows = begin(matriz); rows != end(matriz); rows++){
                for(auto iter = begin(*rows);iter != end(*rows);iter++){
			
			if(*iter < 0.3 )
				std::cout<< '~';
			else if(*iter < 0.7)
				std::cout<<'=';
			else if(*iter < 1)
				std::cout<<'A';


                }
                std::cout<<std::endl;
        }                                  
}
void mostrar_hormiga(std::vector<std::vector<valor>> matriz,int posx,int posy, char x){
	for(int i = 0; i< matriz.size(); i++){
		for(int j = 0; j< matriz[i].size(); j++){
                        if(i == posy && j == posx)
				std::cout<<std::setw(4)<<x;
			else
				std::cout<<std::setw(4)<< matriz[i][j];
                }
                std::cout<<std::endl;
        }

}


