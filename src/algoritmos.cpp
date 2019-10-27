#include"algoritmos.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<cmath>
typedef std::random_device device;
typedef std::uniform_real_distribution<float> distribution;
device dev;

float cosas_de_perlin::randintok(float first, float last){
	std::mt19937 gen(dev());
        distribution dis(first, last);
        return dis(gen);
}


double cosas_de_perlin::dot_product(std::vector<double> A,std::vector<double> B){
	//probando que se suba con mi usuario 2
	double x,y;
	x=A[0]*B[0];
	y=A[1]*B[1];
	return x+y;
}
std::vector <double> cosas_de_perlin::distance_vector(double x, double y,std::vector<double> B){
	std::vector <double> distance;
	distance.push_back((x-B[0])/800);
	distance.push_back((y-B[1])/600);
	return distance;
}
double cosas_de_perlin::distance(std::vector<double> A){
	return sqrt(A[0]*A[0]+A[1]*A[1]);
}

double cosas_de_perlin::polarizacion(double  x,double  y,std::vector<double> A,std::vector<double> B,std::vector<double> C,std::vector<double> D){
	//Q12/Q22
	//Q11/Q22
	//assumed that we know the value of f at the four points Q11 = (x1, y1), Q12 = (x1, y2), Q21 = (x2, y1), and Q22 = (x2, y2)
	//interpolation in x
	double f1=(C[0]-x)/(C[0]-A[0]) * distance(distance_vector(x,y,A))+(x-A[0])/(C[0]-A[0])*distance(distance_vector(x,y,C));
	double f2=(C[0]-x)/(C[0]-A[0])*distance(distance_vector(x,y,B))+(x-A[0])/(C[0]-A[0]) *distance(distance_vector(x,y,D));
	//interpolation in y
	double f=(B[1]-y)/(B[1]-A[1])*f1+(y-A[1])/(B[1]-A[1])*f2;
	return f2;
}

//perling:
double**  cosas_de_perlin::perlin(int nfilas, int ncol){
	//arry para contener las coordenadas valores en las coodenadas x e ydel mapa
	double** mapa = new double*[nfilas+1];
	for(int i=0;i<nfilas+1;i++){
		mapa[i]=new double[ncol+1];
	}
	//vector para almacenar los resultados del perling
	std::vector <std::vector<double>> gradiente (9,std::vector<double>(2));
	for(int i=0;i<9;i++){
		for(int j=0;j<2;j++){
			gradiente[i][j]=randintok(-1.0,1.0);
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
				mapa[y][x] = polarizacion(x,y,gradiente[0],gradiente[1],gradiente[3],gradiente[4]);
 			}
			if (y>0 && y<nfilas/2 && x>ncol/2 && x<ncol)
			{
				//Sector 2
				mapa[y][x] = polarizacion(x,y,gradiente[1],gradiente[2],gradiente[4],gradiente[5]);


			}
			if (y>nfilas/2 && y<nfilas && x>0 && x<ncol/2)
			{
				//Sector 3
				mapa[y][x] = polarizacion(x,y,gradiente[4],gradiente[5],gradiente[7],gradiente[8]);


			}
			if (y>nfilas/2 && y<nfilas && x>ncol/2 && x<ncol)
			{
				//Sector 4
				mapa[y][x] = polarizacion(x,y,gradiente[0],gradiente[1],gradiente[3],gradiente[4]);


			}

		}
	}
	return mapa;
}
