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

void Background::render(const SDLContext& sdlContext) const {
    SDL_RenderClear(sdlContext.renderer.get());
    SDL_SetRenderDrawColor(sdlContext.renderer.get(), 96, 128, 255, 255);
    for (auto& star : stars) {
       auto color = 100 + ((star.plane + 1) * 50);
       SDL_SetRenderDrawColor(sdlContext.renderer.get(),
           color, color, color, star.plane);
       SDL_RenderDrawPoint(sdlContext.renderer.get(), 
           star.star_position.x, star.star_position.y);
    }
    
};

void Background::updateState() {
    for (auto& star : stars) {
        star.star_position.x -= (star.plane + 1) * 2;
        star.star_position.x  = star.star_position.x < 0 ? constants::WINDOW_WIDTH : star.star_position.x;
    }
}
