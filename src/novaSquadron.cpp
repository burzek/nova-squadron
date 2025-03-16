#include "core/game.hpp"

int main() {
    
    spdlog::set_level(spdlog::level::debug);
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->initialize();
    game->run();
    game->shutdown();
    
}