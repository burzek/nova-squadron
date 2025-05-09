#ifndef EF7424CC_8432_4970_918C_7F6378481C74
#define EF7424CC_8432_4970_918C_7F6378481C74

#include <string>
#include "appWindow.hpp"
#include "sprite.hpp"

class SpriteSheet {
    private:
        std::string spriteSheetId;
        int currentSpriteIndex;
        int spriteCount;
        SDL_Surface* spritesheet;
        bool lazyLoaded;
    public:
        SpriteSheet(const std::string spriteSheetId, const std::string assetPath, int spriteCount, std::vector<int> spriteDiv);
        virtual ~SpriteSheet();
        virtual void destroy();
        void initialize(const std::string assetPath, const std::vector<int> spriteDiv);
        // const Sprite* getCurrentSprite();
        int setCurrentSpriteIndex(int spriteIndex);
        int getCurrentSpriteIndex();
        int next();
        int prev();
};

#endif /* EF7424CC_8432_4970_918C_7F6378481C74 */
