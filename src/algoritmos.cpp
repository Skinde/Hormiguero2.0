#include"algoritmos.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<cmath>
typedef std::random_device device;
typedef std::uniform_real_distribution<float> distribution;
device dev;
float cosas_de_perlin::smooth (float x){
	if(x <= 0.0)
		x = 0.0;
	else if(x<1.0)
		x = 6*pow(x,5)-15*pow(x,4)+10*pow(x,3);
	else if(x == 1.0)
		x = 1.0;
	return x;
}

cosas_de_perlin::cosas_de_perlin(int x,int y)
{
	pantalla_x = x;
	pantalla_y = y;
}

float** cosas_de_perlin::filtro_bordes(float** mapa){
	//vertices
	//|x|=pantalla_x//|y|=pantalla_y
	//vertice superior izquierdo
	for(int y=0;y<pantalla_y;y++){
		for(int x;x<pantalla_x;x++){
			if (x==0 && y==0)
				mapa[y][x]=mapa[y+1][x+1];
			//vertice inferior izquierdo
			else if(x==0 && y==pantalla_y)
				mapa[y][x]=mapa[y-1][x+1];
			//vertice superior derecho
			else if(x==0 && y==pantalla_y)
				mapa[y][x]=mapa[y+1][x-1];
			//vertice inferior derecho
			else if(x==pantalla_x && y==pantalla_y)
				mapa[y][x]=mapa[x-1][y-1];
			//fila superior
			else if (y==0 && x>0 && x<pantalla_x)
				mapa[y][x]=(mapa[y+1][x-1]+mapa[y+1][x]+mapa[y+1][x+1])/3;
			//fila del medio
			else if(y==300 && x>0 && x<pantalla_x)
				mapa[y][x]=(mapa[y-1][x-1]+mapa[y-1][x]+mapa[y-1][x+1]+mapa[y+1][x-1]+mapa[y+1][x]+mapa[y+1][x+1])/6;
			//file inferior
			else if(y==pantalla_y && x>0 && x<pantalla_x)
				mapa[y][x]==(mapa[y-1][x-1]+mapa[y-1][x]+mapa[y-1][x+1])/3;
		}
	}
	return mapa;
	}

float cosas_de_perlin::distance(int x, std::vector<float> B)
{
	return (B[0]-x)/400;
}

float cosas_de_perlin::randintok(float first, float last){
	std::mt19937 gen(dev());
        distribution dis(first, last);
        return dis(gen);
}


float cosas_de_perlin::dot_product(std::vector<float> A,std::vector<float> B){
	//probando que se suba con mi usuario 2
	float x,y;
	x=A[0]*B[0];
	y=A[1]*B[1];
	return x+y;
}
std::vector <float> cosas_de_perlin::distance_vector(float x, float y,std::vector<float> B){
	std::vector <float> distance;
	distance.push_back((x-B[0])/pantalla_x);
	distance.push_back((y-B[1])/pantalla_y);
	return distance;
}


float cosas_de_perlin::polarizacion(float A, float B, float x){
	if (x<0)
	{
		x=x*(-1);
	}
	return (x*A)+((1-x)*B);
}

//perling:
float**  cosas_de_perlin::perlin(int nfilas, int ncol){
	//arry para contener las coordenadas valores en las coodenadas x e ydel mapa
	float** mapa = new float*[nfilas+1];
	for(int i=0;i<nfilas+1;i++){
		mapa[i]=new float[ncol+1];
	}
	//vector para almacenar los resultados del perling
	std::vector <std::vector<float>> gradiente (9,std::vector<float>(2));
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			gradiente[i][j]=randintok(-1.0,1.0);
		}
	}
	std::vector<std::vector<float>> posiciones (9,std::vector<float>(2));
	posiciones = {{0,0},{400,0},{(float)pantalla_x,0},{0,300},{400,300},{(float)pantalla_x,300},{0,(float)pantalla_y},{400,(float)pantalla_y},{(float)pantalla_x,(float)pantalla_y}};
	//modificando el mapa de z
	for(int y=0; y<nfilas; y++)
	{
		//sector 1//sector 2
		//sector 3/sector 4
		for(int x=0; x<ncol; x++)
		{
			
				//Sector 1
				float polarizacion1 = polarizacion(dot_product(distance_vector(x,y,posiciones[0]),gradiente[0]),dot_product(distance_vector(x,y,posiciones[2]),gradiente[2]),distance(x,posiciones[0]));
				float polarizacion2 = polarizacion(dot_product(distance_vector(x,y,posiciones[6]),gradiente[6]),dot_product(distance_vector(x,y,posiciones[8]),gradiente[8]),distance(x,posiciones[6]));
				mapa[y][x] = polarizacion(polarizacion1, polarizacion2,(posiciones[4][1]-y))/pantalla_y;
			

		}
	}
	mapa=filtro_bordes(mapa);

	return mapa;

}



