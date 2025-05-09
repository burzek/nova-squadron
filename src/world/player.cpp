#include "player.hpp"

Player::Player() : Entity(SDL_Point{500, 0}) {
    setInitialHealthPoints(constants_hp::PLAYER_INITIAL_HP);
}

Player::~Player() {
}

void Player::render(const SDLContext& sdlContext) const {
    SDL_Rect playerRect = {getPosition().x, getPosition().y, 50, 50};
    SDL_SetRenderDrawColor(sdlContext.renderer.get(), 255, 0, 0, 255);
    SDL_RenderFillRect(sdlContext.renderer.get(), &playerRect);
}

void Player::updateState() {
    setPosition(SDL_Point{getPosition().x, getPosition().y + 1});
}
