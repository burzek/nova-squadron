#include "core/game.hpp"

int main() {
    
    
    Game* game = new Game();
    game->initialize();
    game->run();
    game->shutdown();
    delete game;
    
}