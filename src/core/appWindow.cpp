#include "appWindow.hpp"


AppWindow::AppWindow() {

}

AppWindow::~AppWindow(){

}

void AppWindow::shutdown() {
    SDL_Quit();
}

void AppWindow::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        spdlog::error("Error initializing SDL subsystem");
        exit(1);
    }

    this->sdlContext->window = SDL_CreateWindow(
        constants::WINDOW_NAME.c_str(), 
        constants::WINDOW_X, constants::WINDOW_Y, 
        constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT,
        SDL_RENDERER_ACCELERATED);
    if (this->sdlContext->window == nullptr) {
        spdlog::error("Error creating window, error description: {}", SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    this->sdlContext->renderer = SDL_CreateRenderer(this->sdlContext->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->sdlContext->renderer == nullptr) {
        spdlog::error("Error creating renderer, error description: {}", SDL_GetError());
        exit(1);
    }
}

void AppWindow::presentScene() {
    SDL_RenderPresent(this->sdlContext->renderer);
}

const SDLContext* AppWindow::getContext() const {
    return this->sdlContext;
}

// SDLContext* AppWindow::getContext() const {
//     return const_cast<SDLContext*>(this->sdlContext);
// }
