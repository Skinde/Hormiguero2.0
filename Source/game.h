#ifndef GAME_H_
#define GAME_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

class Game{
	private:
		bool isrunning;
		SDL_Window *window;
		SDL_Renderer *renderer;


	public:

		Game();
		~Game();
		void init(const char* tile, int xpos, int ypos, int width, int height, bool fullscrean);
		void update();
		void render();
		void clean();
		bool running(){return isrunning;};
		void handleEvents();
};



#endif

