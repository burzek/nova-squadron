#ifndef BCDE5629_51A3_4252_AE08_8416B9F6875C
#define BCDE5629_51A3_4252_AE08_8416B9F6875C

#include <spdlog/spdlog.h>
#include "appWindow.hpp"
#include "../world/world.hpp"


class Game {
    private:
        AppWindow* appWindow;
        World* world;
        bool shouldQuit(SDL_Event event);
        void delayForFPS();
        void handleEvents(SDL_Event event);
       
    public:
        Game();
        ~Game();
        void initialize();
        void shutdown();
        void run();

        
        
};

#endif /* BCDE5629_51A3_4252_AE08_8416B9F6875C */
