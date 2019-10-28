#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_
#include<iostream>
#include<random>
#include<cmath>
//#include"algoritmos.cpp"
class cosas_de_perlin
{
    public:
    float randintok(float first, float last);
    float dot_product(std::vector<float> A,std::vector<float> B);
    std::vector <float> distance_vector(float x, float y,std::vector<float> B);
    float distance(int x, std::vector<float> B);
    float polarizacion(float A, float B,float x);
    float**  perlin(int nfilas, int ncol);
    float distance(std::vector<float> A);
    float** filtro_bordes(float** mapa);
    float smooth (float  x);
};
#endif












