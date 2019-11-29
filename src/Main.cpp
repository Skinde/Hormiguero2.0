#include "head.h"
#include "algoritmos.h"
#include <fstream>
#include <sstream>
#include <cassert>

#include"hormi.h"
#include"mundo.h"
#include"insecto.h"
#include"comida.h"




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
    RenderWindow Ventana(VideoMode(pantalla_x,pantalla_y), "My window");
    //etiqueta de inicio
    inicio:

    mundo karmaland(45, 45);
    for (int y=0; y<pantalla_y;y++)
    {
        mapa_hormonal[y]=new float[pantalla_x];
    }
    int gg;
    float** mapi = new float*[pantalla_y];
	for(int i=0;i<pantalla_y;i++){
		mapi[i]=new float[pantalla_x];

	}
    

    mapi = cdp.perlin(pantalla_y,pantalla_x);
    std::vector<std::vector<float>> mapa2(pantalla_y);
    std::vector<std::vector<int>> hormonas(pantalla_y);
    for (int y=0;y<pantalla_y;y++)
    {
        for (int x;x<pantalla_x;x++)
        {
            hormonas[y].push_back(1);
        }
    }
     for (int y = 0;y<pantalla_y;y++)
                {
                    for (int x =0; x<pantalla_x; x++)
                    {
                        mapa2[y].push_back(mapi[y][x]);
                    }
                }
    //etiqueta de renderizado
    fuckthisshitiamback:
    for(int i=0;i<cantidad_de_hormigas;i++){
            fm.crear_hormiga_reina((pantalla_x/2)+10,(pantalla_y/2)+i);
    }
    for (int y = 0;y<pantalla_y;y+=10)
        {
            for (int x =0; x<pantalla_x; x+=10)
            {

                    gg = fm.rectangulo(x,y,10,10);
                    if (((mapi[y][x]+1)*30) > 25)
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
        if ((event.type == sf::Event::KeyPressed))
        {
            if (event.key.code == sf::Keyboard::J)
            {
                goto inicio;
            }
            if (event.key.code == sf::Keyboard::A)
            {
                std::ofstream archivo ("PERLIN.txt");
                archivo << pantalla_y << "/" << pantalla_x << std::endl;
                for (int y = 0;y<pantalla_y;y++)
                {
                    for (int x =0; x<pantalla_x; x++)
                    {
                        archivo << mapi[y][x] << "/";
                    }
                    archivo << std::endl;
                }

            }
            if(event.key.code == sf::Keyboard::O)
            {
                std::ifstream archivo ("PERLIN.txt");
                std::string line;
                std::string sy,sx;
                int contador_de_linea = 0,  contador_de_columna = 0;
                int y,x;

                std::getline(archivo,line);
                std::stringstream ss(line);
                std::getline(ss,sy, '/');
                std::getline(ss,sx,'/');
                std::vector<std::vector<float>> mapa2(pantalla_y);

                while (getline(archivo,line))
                {
                    std::string scolor;
                    std::stringstream ss(line);
                    while (getline(ss, scolor, '/')){
                        mapa2[contador_de_linea].push_back(stof(scolor));
                        contador_de_columna++;
                    }

                    contador_de_linea++;
                }

                for (int y=0;y<pantalla_y;y++)
                {
                    for(int x=0;x<pantalla_x;x++)
                    {
                       mapi[y][x] = mapa2[y][x];
                    }
                }
                goto fuckthisshitiamback;



            }
        }
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
        if (fm.retornar_real_hormiga().size() > 0)
        {
            for (auto hormiga: fm.retornar_real_hormiga())
            {
            
                hormiga->vivir(mapa2);
                fm.mover_hormiga(hormiga);
            }
        }
        if (fm.retornar_hormigas().size() > 0)
        {
            for (auto figurata: fm.retornar_hormigas())
            {
                Ventana.draw(figurata);
            }
        }
        Ventana.display();

    }
    return 0;
}