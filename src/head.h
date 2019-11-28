#pragma once
#include <SFML/Graphics.hpp>
#include "hormi.h"
#include <iostream>


using namespace sf;

class Funciones_De_Miguel
{
    private:
    std::vector<sf::RectangleShape> array_de_rectangulos;
    std::vector<reina*> hormigas;
    public:
    int rectangulo(int x,int y,int tamano_x,int tamano_y)
    {
        RectangleShape rectangle;
        rectangle.setSize(Vector2f(tamano_x,tamano_y));
        rectangle.setPosition(x,y);
        array_de_rectangulos.push_back(rectangle);
        return array_de_rectangulos.size()-1;
    }
    int rectangulo_hormigas(int x,int y,int tamano_x,int tamano_y)
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

    void mover(int x, int y, int pos)
    {
    array_de_rectangulos[pos].setPosition(Vector2f(x,y));
    }
    int crear_hormiga_reina(pos x_t,pos y_t){
        reina* temp=new reina(x_t,y_t);
        hormigas.push_back(temp);

        RectangleShape hormiga_rectangulo;
        hormiga_rectangulo.setSize(Vector2f(2,3));
        hormiga_rectangulo.setPosition(x_t,y_t);

        array_de_rectangulos.push_back(hormiga_rectangulo);
        temp->set_posicion_en_el_vector(array_de_rectangulos.size());

        return hormigas.size()-1;
    }

};