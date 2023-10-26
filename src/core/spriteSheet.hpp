#ifndef EF7424CC_8432_4970_918C_7F6378481C74
#define EF7424CC_8432_4970_918C_7F6378481C74

#include <string>
#include "appWindow.hpp"
#include "sprite.hpp"

class SpriteSheet {
    private:
        int currentSpriteIndex;
        int spriteCount;
        SDL_Surface* spritesheet;
    public:
        SpriteSheet(const std::string assetPath);
        virtual ~SpriteSheet();
        const Sprite* getCurrentSprite();
        int setCurrentSpriteIndex(int spriteIndex);
        int getCurrentSpriteIndex();
        int next();
        int prev();
};

#endif /* EF7424CC_8432_4970_918C_7F6378481C74 */
