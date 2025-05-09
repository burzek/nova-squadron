#include "world.hpp"

World::World() {
    this->entities = std::map<EntityType, std::unique_ptr<Entity>>();
    this->entities[EntityType::PLAYER] = std::make_unique<Player>();
    this->entities[EntityType::BACKGROUND] = std::make_unique<Background>();
    //this->entities[EntityType::ENEMY] = std::make_unique<Enemy>();
};

World::~World() {
}

void World::initialize() {
    spdlog::info("Initializing the world");
    this->spriteSheetManager = std::make_unique<SpriteSheetManager>();
    this->spriteSheetManager->initialize();
    
};

void World::updateWorld(){
    for (auto& entity : this->entities) {
        entity.second->updateState();
    }
};


std::vector<std::reference_wrapper<const Entity>> World::getRenderableEntities() const {
    return std::vector<std::reference_wrapper<const Entity>>{
        *this->entities.at(EntityType::BACKGROUND),
        *this->entities.at(EntityType::PLAYER)
    };
}

const Player& World::getPlayer() const {
    return *dynamic_cast<Player*>(this->entities.at(EntityType::PLAYER).get());
}


