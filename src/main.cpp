#include "Game.hpp"

Game *game = nullptr;

extern "C" int main(int argc, char* argv[]) {

    const int frame_rate = 60;
    const int frame_delay = 1000 / frame_rate;

    Uint32 frame_start;
    int frame_time;


    game = new Game();

    game->init("Game Window", 100, 100, 800, 600, false);

    while (game->running()) {

        frame_start = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;

        if(frame_time < frame_delay) {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    game->clean();
    delete game;

    return 0;
    
}
