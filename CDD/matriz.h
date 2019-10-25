#ifndef MATRIZ_H_
#define MATRIZ_H_
#include<random>
#include<vector>
#include<iomanip>
typedef float valor;
typedef double num;
num randint(num first, num last);
std::vector<std::vector<valor>> generar_matriz(valor filas, valor columnas);
void perlin_generator(std::vector<std::vector<valor>> & matriz);
void imprimir_matriz(std::vector<std::vector<valor>> matriz);
void mostrar_hormiga(std::vector<std::vector<valor>> matriz, int posx,int posy, char x);






#endif
