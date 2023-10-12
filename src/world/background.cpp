#include "background.hpp"

Background::Background() {
};

Background::~Background() {
};

void Background::render(const AppWindow* appWindow) {
    SDL_SetRenderDrawColor(appWindow->getContext()->renderer, 96, 128, 255, 255);
    SDL_RenderClear(appWindow->getContext()->renderer);
};


