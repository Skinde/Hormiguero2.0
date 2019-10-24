#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

class Funciones_De_Miguel
{
    private:
    std::vector<sf::RectangleShape> array_de_rectangulos;
    public:
    void rectangulo(int x,int y,int tamano_x,int tamano_y)
    {
        RectangleShape rectangle(Vector2f(x,y));
        rectangle.setSize(Vector2f(tamano_x,tamano_y));
        array_de_rectangulos.push_back(rectangle);
    }
    std::vector<RectangleShape> retornar_figuras()
    {
        return array_de_rectangulos;
    }
    void eliminar_rectangulo (RectangleShape& figurita)
    {
        for (int iterador = 0; iterador<array_de_rectangulos.size();iterador++)
        {
            if (array_de_rectangulos[iterador] == figurita)
            {
                array_de_rectangulos.erase(array_de_rectangulos.begin()+iterador);
            }
        }
    }
    
    
    

};