#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

class Funciones_De_Miguel
{
    private:
    std::vector<sf::RectangleShape> array_de_rectangulos;
    public:
    int rectangulo(int x,int y,int tamano_x,int tamano_y)
    {
        RectangleShape rectangle(Vector2f(x,y));
        rectangle.setSize(Vector2f(tamano_x,tamano_y));
        array_de_rectangulos.push_back(rectangle);
        return array_de_rectangulos.size();
    }
    std::vector<RectangleShape> retornar_figuras()
    {
        return array_de_rectangulos;
    }
    void eliminar_rectangulo(int figurita)
    {
        array_de_rectangulos.erase(array_de_rectangulos.begin() + figurita);
    }
    
    
    

};