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
        RectangleShape rectangle;
        rectangle.setSize(Vector2f(tamano_x,tamano_y));
        rectangle.setPosition(x,y);
        array_de_rectangulos.push_back(rectangle);
        return array_de_rectangulos.size()-1;
    }
    std::vector<RectangleShape> retornar_figuras()
    {
        return array_de_rectangulos;
    }
    void eliminar_rectangulo(int figurita)
    {
        array_de_rectangulos.erase(array_de_rectangulos.begin() + figurita);
    }
    void cambiar_color(int p, float r, float g, float b)
    {
        array_de_rectangulos[p].setFillColor(Color(r,g,b));
    }




};