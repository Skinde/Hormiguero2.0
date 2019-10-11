#include "head.h"
#include "Actualizar.cpp"
#include "Renderizar.cpp"



int main()
{
    Funciones_De_Miguel fm;
    RenderWindow Ventana(VideoMode(800, 600), "My window");
    while (Ventana.isOpen())
    {
        Event event;
        while (Ventana.pollEvent(event))
        {
            if (event.type == Event::Closed)
                Ventana.close();
        }
        Ventana.clear(Color::Black);
        Actualizar();
        Renderizar();
        Ventana.draw(fm.rectangulo(1,1,100,100));
        Ventana.display();
    }
    return 0;
}