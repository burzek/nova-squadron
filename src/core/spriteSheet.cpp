#include "spriteSheet.hpp"



SpriteSheet::SpriteSheet(const std::string spriteSheetId, const std::string assetPath, int spriteCount, std::vector<int> spriteDiv) {
    this->spriteSheetId = spriteSheetId;
    this->spriteCount = spriteCount;
    this->currentSpriteIndex = 0;
    this->initialize(assetPath, spriteDiv);
}

SpriteSheet::~SpriteSheet() {
}

void SpriteSheet::initialize(const std::string assetPath, const std::vector<int> spriteDiv) {
    //load sprite file
    std::fstream fs;
    fs.open("assets/" + assetPath, std::ios::in);
    if (!fs.is_open()) {
        spdlog::error("Cannot open sprite file {}", assetPath);
        std::exit(EXIT_FAILURE);
    }

    SDL_Surface* spriteSheet = IMG_Load(("assets/" + assetPath).c_str());
    
}


void SpriteSheet::destroy() {
    spdlog::debug("SpriteSheet destroy called");
}

// const Sprite *SpriteSheet::getCurrentSprite() {
//     return nullptr;
// }

int SpriteSheet::setCurrentSpriteIndex(int spriteIndex) {
    if (spriteIndex > 0 && spriteIndex < this->spriteCount) {
        this->currentSpriteIndex = spriteIndex;
    }
    return this->currentSpriteIndex;
}

int SpriteSheet::getCurrentSpriteIndex() {
    return this->currentSpriteIndex;
}


int SpriteSheet::next() {
    if (this->currentSpriteIndex < this->spriteCount) {
        this->currentSpriteIndex++;
    }
    return this->currentSpriteIndex;
}

int SpriteSheet::prev() {
    if (this->currentSpriteIndex > 0) {
        this->currentSpriteIndex--;
    }
    return this->currentSpriteIndex;
}
