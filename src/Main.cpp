#include "head.h"
#include "algoritmos.h"
#include "Main.hpp"




int main()
{
    //Creacion de objetos y ventana
    Funciones_De_Miguel fm;
    cosas_de_perlin  cdp;
    RenderWindow Ventana(VideoMode(800,600), "My window");
    double** mapi = new double*[600];
	for(int i=0;i<600;i++){
		mapi[i]=new double[800];
	}

    mapi = cdp.perlin(600,800);

    for (int y = 0;y<600;y++)
        {
            for (int x =0; x<800; x++)
            {
                if (mapi[y][x])
                {
                    fm.rectangulo(x,y,1,1);
                }
            }
        }

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