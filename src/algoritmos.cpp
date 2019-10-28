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

float** cosas_de_perlin::filtro_bordes(float** mapa){
	//vertices
	//|x|=800//|y|=600
	//vertice superior izquierdo
	for(int y=0;y<600;y++){
		for(int x;x<800;x++){
			if (x==0 && y==0)
				mapa[y][x]=mapa[y+1][x+1];
			//vertice inferior izquierdo
			else if(x==0 && y==600)
				mapa[y][x]=mapa[y-1][x+1];
			//vertice superior derecho
			else if(x==0 && y==600)
				mapa[y][x]=mapa[y+1][x-1];
			//vertice inferior derecho
			else if(x==800 && y==600)
				mapa[y][x]=mapa[x-1][y-1];
			//fila superior
			else if (y==0 && x>0 && x<800)
				mapa[y][x]=(mapa[y+1][x-1]+mapa[y+1][x]+mapa[y+1][x+1])/3;
			//fila del medio
			else if(y==300 && x>0 && x<800)
				mapa[y][x]=(mapa[y-1][x-1]+mapa[y-1][x]+mapa[y-1][x+1]+mapa[y+1][x-1]+mapa[y+1][x]+mapa[y+1][x+1])/6;
			//file inferior
			else if(y==600 && x>0 && x<800)
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
	distance.push_back((x-B[0])/400);
	distance.push_back((y-B[1])/300);
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
	posiciones = {{0,0},{400,0},{800,0},{0,300},{400,300},{800,300},{0,600},{400,600},{800,600}};
	//modificando el mapa de z
	for(int y=0; y<nfilas; y++)
	{
		//sector 1//sector 2
		//sector 3/sector 4
		for(int x=0; x<ncol; x++)
		{
			if (y>0 && y<nfilas/2 && x>0 && x<ncol/2)
			{
				//Sector 1
				float polarizacion1 = polarizacion(dot_product(distance_vector(x,y,posiciones[0]),gradiente[0]),dot_product(distance_vector(x,y,posiciones[1]),gradiente[1]),distance(x,posiciones[0]));
				float polarizacion2 = polarizacion(dot_product(distance_vector(x,y,posiciones[3]),gradiente[3]),dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),distance(x,posiciones[3]));
				mapa[y][x] = polarizacion(polarizacion1, polarizacion2,(posiciones[4][1]-y)/300);
			}
			if (y>0 && y<nfilas/2 && x>ncol/2 && x<ncol)
			{
				//Sector 2
				float polarizacion3 = polarizacion(dot_product(distance_vector(x,y,posiciones[1]),gradiente[1]),dot_product(distance_vector(x,y,posiciones[2]),gradiente[2]),distance(x,posiciones[1]));
				float polarizacion4 = polarizacion(dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),dot_product(distance_vector(x,y,posiciones[5]),gradiente[5]),distance(x,posiciones[4]));
				mapa[y][x] = polarizacion(polarizacion3, polarizacion4,(posiciones[5][1]-y)/300);

			}
			if (y>nfilas/2 && y<nfilas && x>0 && x<ncol/2)
			{
				//Sector 3
				float polarizacion5 = polarizacion(dot_product(distance_vector(x,y,posiciones[3]),gradiente[3]),dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),distance(x,posiciones[3]));
				float polarizacion6 = polarizacion(dot_product(distance_vector(x,y,posiciones[6]),gradiente[6]),dot_product(distance_vector(x,y,posiciones[7]),gradiente[7]),distance(x,posiciones[6]));
				mapa[y][x] = polarizacion(polarizacion5, polarizacion6,(posiciones[7][1]-y)/300);

			}
			if (y>nfilas/2 && y<nfilas && x>ncol/2 && x<ncol)
			{
				//Sector 4
				float polarizacion7 = polarizacion(dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),dot_product(distance_vector(x,y,posiciones[5]),gradiente[5]),distance(x,posiciones[4]));
				float polarizacion8 = polarizacion(dot_product(distance_vector(x,y,posiciones[7]),gradiente[7]),dot_product(distance_vector(x,y,posiciones[8]),gradiente[8]),distance(x,posiciones[7]));
				mapa[y][x] = polarizacion(polarizacion7, polarizacion8,(posiciones[8][1]-y)/300);


			}

		}
	}
	mapa=filtro_bordes(mapa);

	return mapa;

}