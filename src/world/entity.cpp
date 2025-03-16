#include "entity.hpp"

Entity::Entity() : position(SDL_Point{0, 0}), hp(getInitialHealthPoints()), width(0), height(0) {  
}

Entity::Entity(SDL_Point position) : position(SDL_Point{0, 0}) {
}

Entity::~Entity() {
};

