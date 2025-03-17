#include "appWindow.hpp"


AppWindow::AppWindow() {
    this->sdlContext = std::make_unique<SDLContext>(
        std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>(nullptr, SDL_DestroyRenderer),
        std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(nullptr, SDL_DestroyWindow)
    );
    spdlog::debug("AppWindow constructor is called");
}

AppWindow::~AppWindow(){
    spdlog::debug("AppWindow destructor is called");
}

void AppWindow::shutdown() {
    SDL_Quit();
}

void AppWindow::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        spdlog::error("Error initializing SDL subsystem");
        exit(1);
    }

    SDL_Window* sdlWindow = 
        SDL_CreateWindow(
            constants::WINDOW_NAME.c_str(), 
            constants::WINDOW_X, constants::WINDOW_Y, 
            constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT, 
            SDL_WINDOW_SHOWN
    );
    if (!sdlWindow) {
        spdlog::error("Error creating window, error description: {}", SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlRenderer) {
        spdlog::error("Error creating renderer, error description: {}", SDL_GetError());
        exit(1);
    }

    this->sdlContext->renderer = std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>(sdlRenderer, SDL_DestroyRenderer);
    this->sdlContext->window = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(sdlWindow, SDL_DestroyWindow);

}

void AppWindow::renderWorld(const World& world) {
    this->prepareScene();

    // for (auto entity : world.getRenderableEntities()) {
    //     entity->render(this->getContext());
    // }
    this->presentScene();
}

void AppWindow::prepareScene() {
    SDL_SetRenderDrawColor(this->sdlContext->renderer.get(), 0, 0, 0, 0);
    SDL_RenderClear(this->sdlContext->renderer.get());
}


void AppWindow::presentScene() {
    SDL_RenderPresent(this->sdlContext->renderer.get());
}

const SDLContext* AppWindow::getContext() const {
    return this->sdlContext.get();
}

