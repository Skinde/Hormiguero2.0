#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_
#include"objetos.h"
#endif
class cosas_de_perlin
{   
    public:
    double dot_product(std::vector<double> A,std::vector<double> B);
    std::vector <double> distance_vector(double x, double y,std::vector<double> B);
    double distance(std::vector <double> A, std::vector<double> B);
    double polarizacion(double A, double B);
    double**  perlin(int nfilas, int ncol);
};













