#ifndef F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D
#define F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D

#include <vector>
#include <algorithm>
#include "../core/renderable.hpp"
#include "../core/stateful.hpp"
#include "../core/appWindow.hpp"
#include "../utils/random.hpp"


class Background : public Entity {
    const int MAX_STARS = 50;
    const int PLANES_COUNT = 3;
    struct Star {
        SDL_Point star_position;
        int plane;
    };

    private:
        std::vector<Star> stars;
    public:
        Background();
        ~Background();
        void render(const SDLContext& sdlContext);
        void updateState();
        int getInitialHealthPoints() {return 0;};
        bool isRenderable() {return false;};
        bool isDestroyable() {return false;};
        EntityType getType() {return EntityType::BACKGROUND;};

};

#endif /* F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D */
