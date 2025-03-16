#include "game.hpp"


Game::Game() {
}

Game::~Game() {
}

void Game::initialize() {
    spdlog::info("Initializing the game");
    this->appWindow = std::make_unique<AppWindow>();
    this->appWindow->initialize();
    this->world = std::make_unique<World>();
    // this->world->initialize();
};

void Game::shutdown() {
     spdlog::info("Shutting down the game");
};

void Game::run() {
    spdlog::info("Running main game loop");
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            quit = shouldQuit(event);
        }

        handleEvents(event);
        // world->update();
        appWindow->renderWorld(world);
        delayForFPS();
    }
}


bool Game::shouldQuit(SDL_Event event) {
    return event.type == SDL_QUIT || 
        (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE);
}

void Game::delayForFPS() {
    SDL_Delay(10);  //@todo
}

void Game::handleEvents(SDL_Event event) {

}