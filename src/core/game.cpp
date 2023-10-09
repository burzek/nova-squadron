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
}