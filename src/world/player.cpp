#include "player.hpp"

Player::Player() : Entity(SDL_Point{500, 0}) {
    setInitialHealthPoints(constants_hp::PLAYER_INITIAL_HP);
}

Player::~Player() {
}

void Player::render(const SDLContext& sdlContext) {

}

void Player::updateState() {

}
