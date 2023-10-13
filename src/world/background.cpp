#include "background.hpp"

Background::Background() {
    //initialize stars
    for (auto plane = 0; plane < PLANES_COUNT; plane++) {
        for (auto star = 0; star < MAX_STARS; star++) {
            stars.push_back(Star {
                SDL_Point{
                    utils::Random::randomi(0, constants::WINDOW_WIDTH - 1), utils::Random::randomi(0, constants::WINDOW_HEIGHT - 1)
                }, 
                plane
                });
        }
    }

};

Background::~Background() {
};

void Background::render(const AppWindow* appWindow) {
    SDL_RenderClear(appWindow->getContext()->renderer);
    SDL_SetRenderDrawColor(appWindow->getContext()->renderer, 96, 128, 255, 255);
    for (auto star : stars) {
        auto color = 255 - ((star.plane + 1) * 50);
        SDL_SetRenderDrawColor(appWindow->getContext()->renderer,
            star.plane, color, color, color);
        SDL_RenderDrawPoint(appWindow->getContext()->renderer, 
            star.star_position.x, star.star_position.y);
    }
    
};


