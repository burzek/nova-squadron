#include "entity.hpp"

Entity::Entity() : position(SDL_Point{0, 0}), width(0), height(0), hp(0) {  
}

Entity::Entity(SDL_Point position) : position(position), width(0), height(0), hp(0) {
}

Entity::~Entity() {
};

