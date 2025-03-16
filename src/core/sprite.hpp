#ifndef A3350234_D481_4C60_BD80_A8774A12BEE1
#define A3350234_D481_4C60_BD80_A8774A12BEE1

#include <SDL2/SDL_surface.h>
#include "renderable.hpp"

class Sprite {
    private:
        SDL_Surface* sprite;
        int width;
        int height;
    public:
        Sprite();
        virtual ~Sprite();
        void renderSpriteAt(const AppWindow* appWindow, int posX, int posY);

};

#endif /* A3350234_D481_4C60_BD80_A8774A12BEE1 */
