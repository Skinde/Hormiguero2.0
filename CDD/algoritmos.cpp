#include"algoritmos.h"
#include "matriz.h"
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
std::vector <double> distance_vector(std::vector<int> A,std::vector<int> B){
	std::vector <double> distance;
	distance[0]=B[0]-A[0];
	distance[1]=B[1]-A[1];
	return distance;
}

double distance(std::vector <int> A, std::vector<int> B){
	std::vector <double> temp=distance_vector(A,B);
	return sqrt( temp[0]*temp[0]+ temp[1]*temp[1]);
}
double polarizacion(double A, double B){
	return (A+B)/2;
}

//perling: 
void perlin(int nfilas, int ncol){
	//arry para contener las coordenadas valores en las coodenadas x e ydel mapa
	double mapa [nfilas] [ncol];
	//vector para almacenar los resultados del perling		
	std::vector <std::vector<double>> gradiente (9,std::vector<double>(2));
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			gradiente[i][j]=randint(-1,1);
		}
	}
	//modificando el mapa de z
	for(int y=0; y<nfilas; y++)
	{	
		//sector 1//sector 2
		//sector 3/sector 4
		for(int x=0; x<ncol; x+
		{
			if (y>0 && y<nfilas/2 && x>0 && x<ncol/2)
			{
				//Sector 1
				mapa[x][y]=polarizacion(polarizacion(dot_product(gradiente[0],distance_vector(Vector2f(x,y),)Vector2f(0,0)),dot_product(gradiente[0],distance_vector(Vector2f(x,y),)Vector2f(ncol/2,0))),dot_product(gradiente[0],distance_vector(Vector2f(x,y),)Vector2f(0,nfilas/2)),dot_product(gradiente[0],distance_vector(Vector2f(x,y),)Vector2f(ncol/2,nfilas/2))));
			}
			if (y>0 && y<nfilas/2 && x>ncol/2 && x<ncol)
			{
				//Sector 2
			}
			if (y>nfilas/2 && y<nfilas && x>0 && x<ncol/2)
			{
				//Sector 3
			}
			if (y>nfilas/2 && y<nfilas && x>ncol/2 && x<ncol)
			{
				//Sector 4
			}

		}
	}


}
