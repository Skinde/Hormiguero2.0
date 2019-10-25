#include "head.h"
#include "algorit"




int main()
{
    //Creacion de objetos y ventana
    int rectangulo1;
    Funciones_De_Miguel fm;
    RenderWindow Ventana(VideoMode(800, 600), "My window");
    rectangulo1 = fm.rectangulo(10,10,200,200);


    while (Ventana.isOpen())
    {   
        // Manejador de eventos
        Event event;
        if (Ventana.pollEvent(event))
        {
            if (event.type == Event::Closed)
                Ventana.close();
        }
        // Codigo


        
        //Renderizador
        Ventana.clear(Color::Black);
        if (fm.retornar_figuras().size() > 0)
        {
            for (auto figurin: fm.retornar_figuras())
            {
                Ventana.draw(figurin);
            }
        }
        Ventana.display();
        
    }
    return 0;
}