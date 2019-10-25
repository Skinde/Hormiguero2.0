#include"algoritmos.h"
#include "matriz.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 
#include<cmath>
double dot_product(std::vector<double> A,std::vector<double> B){
	//probando que se suba con mi usuario 2
	double x,y;
	x=A[0]*B[0];
	y=A[1]*B[1];
	return x+y;
}
std::vector <double> distance_vector(double x, double y,std::vector<double> B){
	std::vector <double> distance;
	distance[0]=(x-B[0])/800;
	distance[1]=(y-B[1])/600;
	return distance;
}

double distance(std::vector <double> A, std::vector<double> B){
	std::vector <double> temp=distance_vector(A,B);
	return sqrt( temp[0]*temp[0]+ temp[1]*temp[1]);
}
double polarizacion(double A, double B){
	return (A+B)/2;
}

//perling: 
void perlin(int nfilas, int ncol){
	//arry para contener las coordenadas valores en las coodenadas x e ydel mapa
	double mapa [ncol] [nfilas];
	//vector para almacenar los resultados del perling		
	std::vector <std::vector<double>> gradiente (9,std::vector<double>(2));
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			gradiente[i][j]=randint(-1,1);
		}
	}
	std::vector<std::vector<double>> posiciones (9,std::vector<double>(2));
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
				double polarizacion1 = polarizacion(dot_product(distance_vector(x,y,posiciones[0]),gradiente[0]),dot_product(distance_vector(x,y,posiciones[1]),gradiente[1]));
				double polarizacion2 = polarizacion(dot_product(distance_vector(x,y,posiciones[3]),gradiente[3]),dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]));
				mapa[x][y] = polarizacion(polarizacion1, polarizacion2);
			}
			if (y>0 && y<nfilas/2 && x>ncol/2 && x<ncol)
			{
				//Sector 2
				double polarizacion3 = polarizacion(dot_product(distance_vector(x,y,posiciones[1]),gradiente[1]),dot_product(distance_vector(x,y,posiciones[2]),gradiente[2]));
				double polarizacion4 = polarizacion(dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),dot_product(distance_vector(x,y,posiciones[5]),gradiente[5]));
				mapa[x][y] = polarizacion(polarizacion3, polarizacion4);
				
			}
			if (y>nfilas/2 && y<nfilas && x>0 && x<ncol/2)
			{
				//Sector 3
				double polarizacion5 = polarizacion(dot_product(distance_vector(x,y,posiciones[3]),gradiente[3]),dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]));
				double polarizacion6 = polarizacion(dot_product(distance_vector(x,y,posiciones[6]),gradiente[6]),dot_product(distance_vector(x,y,posiciones[7]),gradiente[7]));
				mapa[x][y] = polarizacion(polarizacion5, polarizacion6);
				
			}
			if (y>nfilas/2 && y<nfilas && x>ncol/2 && x<ncol)
			{
				//Sector 4
				double polarizacion5 = polarizacion(dot_product(distance_vector(x,y,posiciones[4]),gradiente[4]),dot_product(distance_vector(x,y,posiciones[5]),gradiente[5]));
				double polarizacion6 = polarizacion(dot_product(distance_vector(x,y,posiciones[7]),gradiente[7]),dot_product(distance_vector(x,y,posiciones[8]),gradiente[8]));

			}

		}
	}


}
