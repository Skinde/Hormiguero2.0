#include "game.h"


int main(int argc, const char * argv[]){
	Game *game = nullptr;
	game = new Game();

	while(game->running()){
		game->Game::handleEvents();
		game->Game::update();
		game->Game::render();
	}
	game->Game::clean();








	return 0;

}
