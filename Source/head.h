#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

class Funciones_De_Miguel
{
    public:
    RectangleShape rectangulo(int x,int y,int tamano_x,int tamano_y)
    {
        RectangleShape rectangle(Vector2f(x,y));
        rectangle.setSize(Vector2f(tamano_x,tamano_y));
        return rectangle;
    }
};