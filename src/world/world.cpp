#include "world.hpp"

World::World() {
    this->entities = std::map<EntityType, std::unique_ptr<Entity>>();
    this->entities[EntityType::PLAYER] = std::make_unique<Player>();
    //this->entities[EntityType::ENEMY] = std::make_unique<Enemy>();
};

World::~World() {
}

void World::updateWorld(){
    for (auto& entity : this->entities) {
        entity.second->updateState();
    }
};


const std::vector<EntityType>& World::getRenderableEntities() const {
    static std::vector<EntityType> renderableEntities;
    renderableEntities.clear();
    for (const auto& entity : this->entities) {
        if (entity.second->isRenderable()) {
            renderableEntities.push_back(entity.first);
        }
    }
    return renderableEntities;
}

const Player& World::getPlayer() const {
    return *dynamic_cast<Player*>(this->entities.at(EntityType::PLAYER).get());
}


