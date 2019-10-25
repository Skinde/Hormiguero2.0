#include"algoritmos.h"
#include "matriz.h"
#include <iostream>
#include <vector> 
#include<cmath>

//perling: 
void perlin(int nfilas, int ncol){
	//vector para contener las coordenadas x e y del mapa
	int mapa [nfilas] [ncol];
	//vector para almacenar los resultados del perling		
	std::vector <std::vector<double>> gradiente (9,std::vector<double>(2));
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			gradiente[i][j]=randint(-1,1);
		}
	}
	// vector para los puntos aleatorios
	int array;
	int posx;
	int posy;
	for (int i=0;i<480000;i++)
	{
		posy = i-1/800;
		posx = i;
		while (posx > 800)
		{
			posx -= 800;
			std::cout << posx << " ";
			std::cout <<  posy;
			std::cout << std::endl;
		}
	}

}
