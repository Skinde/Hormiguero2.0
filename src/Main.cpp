#include "head.h"
#include "algoritmos.h"





int main()
{
    //Creacion de objetos y ventana
    int pantalla_y, pantalla_x, cantidad_de_hormigas;
    std::string accion; 
    std::cin >> pantalla_x;
    std::cin >> pantalla_y;
    std::cin >> cantidad_de_hormigas;
    cosas_de_perlin  cdp(pantalla_x, pantalla_y);
    Funciones_De_Miguel fm;
    float** mapa_hormonal = new float*[pantalla_y];
    for (int y=0; y<pantalla_y;y++)
    {
        mapa_hormonal[y]=new float[pantalla_x];
    }
    int gg;
    RenderWindow Ventana(VideoMode(pantalla_x,pantalla_y), "My window");
    float** mapi = new float*[pantalla_y];
	for(int i=0;i<pantalla_y;i++){
		mapi[i]=new float[pantalla_x];

	}

    mapi = cdp.perlin(pantalla_y,pantalla_x);

    for (int y = 0;y<pantalla_y;y+=10)
        {
            for (int x =0; x<pantalla_x; x+=10)
            {

                    gg = fm.rectangulo(x,y,10,10);
                    if (((mapi[y][x]+1)*30) > 10)
                    {
                        fm.cambiar_color(gg,((mapi[y][x]+1)*30),((mapi[y][x]+1)*50),((mapi[y][x]+1)*30));
                    }
                    else
                    {
                        fm.cambiar_color(gg,((mapi[y][x]+1)*30),((mapi[y][x]+1)*30),((mapi[y][x]+1)*50));
                    }
                    
                    

            }
        }
        Ventana.setFramerateLimit(60);
    
    
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