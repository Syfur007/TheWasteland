#include "Game.hpp"

Game *game = nullptr;

extern "C" int main(int argc, char* argv[]) {

    game = new Game();

    game->init("Game Window", 100, 100, 800, 600, true);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    delete game;

    return 0;
    
}
