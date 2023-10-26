#include "spriteSheet.hpp"


SpriteSheet::SpriteSheet(const std::string assetPath) {

}

SpriteSheet::~SpriteSheet() {

}

const Sprite *SpriteSheet::getCurrentSprite() {
    return nullptr;
}

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
