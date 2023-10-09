#include "game.hpp"


Game::Game() {

}

Game::~Game() {
}

void Game::initialize() {
    spdlog::info("Initializing the game");
    this->appWindow = new AppWindow();
    this->appWindow->initialize();
}

void Game::shutdown() {
     spdlog::info("Shutting down the game");
     if (this->appWindow != nullptr) {
        this->appWindow->shutdown();
        delete this->appWindow;
     }

}

void Game::run() {
    spdlog::info("Running main game loop");
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            quit = shouldQuit(event);
        }

        handleEvents(event);
        updateWorld();
        renderWorld();
        delayForFPS();
    }
}


bool Game::shouldQuit(SDL_Event event) {
    return event.type == SDL_QUIT || 
        (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE);
}

void Game::handleEvents(SDL_Event event) {

}

void Game::updateWorld() {

}

void Game::renderWorld() {
    this->appWindow->render();
}

void Game::delayForFPS() {

}