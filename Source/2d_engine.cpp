#include "game.cpp"



int Empezar_Engine(){
	Game game;

	while(game.running()){
		game.handleEvents();
		game.update();
		game.render();
	}
	game.clean();








	return 0;

}
