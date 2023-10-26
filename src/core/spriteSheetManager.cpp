#include "spriteSheetManager.hpp"

#include <fstream>
#include "GameException.hpp"

SpriteSheetManager::SpriteSheetManager() {
    loadSpriteSheets("assets/sprites.dat");
}

SpriteSheetManager::~SpriteSheetManager() {
    if (this->spriteSheetCache != nullptr) {
        for (const auto &keyVal : this->spriteSheetCache) {
            keyVal.second->destroy();
            delete keyVal.second;
        }
    }
}



const SpriteSheet *SpriteSheetManager::getSpriteSheet(const std::string spriteSheetId){
    return nullptr;
}

void SpriteSheetManager::loadSpriteSheets(const std::string assetPath) {
    //load info file
    fstream fs;
    fs.open("assets/sprites.dat");
    if (!fs.open()) {
        spdlog::error("Cannot open sprites.dat file");
        throw GameException("Cannot open sprites.dat file");
    }
}

