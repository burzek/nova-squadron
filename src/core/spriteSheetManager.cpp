#include "spriteSheetManager.hpp"

#include <fstream>
#include "GameException.hpp"

SpriteSheetManager::SpriteSheetManager() {
    loadSpriteSheets("assets/sprites.dat");
}

SpriteSheetManager::~SpriteSheetManager() {
    if (this->spriteSheetCache) {
        auto &mapRef = *(this->spriteSheetCache);
        for (const auto &keyVal : mapRef) {
            if (keyVal.second) {
                keyVal.second->destroy();
            }
        }
    }
}



const std::unique_ptr<SpriteSheet> SpriteSheetManager::getSpriteSheet(const std::string spriteSheetId){
    return nullptr;
}

void SpriteSheetManager::loadSpriteSheets(const std::string assetPath) {
    //load info file
    std::fstream fs;
    fs.open("assets/sprites.dat");
    if (!fs.is_open()) {
        spdlog::error("Cannot open sprites.dat file");
        throw GameException("Cannot open sprites.dat file");
    }
}

