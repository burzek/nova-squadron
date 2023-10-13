#ifndef F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D
#define F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D

#include <vector>
#include <algorithm>
#include "../core/renderable.hpp"
#include "../core/appWindow.hpp"
#include "../utils/random.hpp"


class Background : public Renderable {
    const int MAX_STARS = 100;
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
        void render(const AppWindow *appWindow);
};

#endif /* F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D */
