#ifndef BCDE5629_51A3_4252_AE08_8416B9F6875C
#define BCDE5629_51A3_4252_AE08_8416B9F6875C

#include <spdlog/spdlog.h>

#include "appWindows.hpp"


class Game {
    private:
        AppWindow* appWindow;
    public:
        Game();
        ~Game();
        void initialize();
        void shutdown();
        void run();
};

#endif /* BCDE5629_51A3_4252_AE08_8416B9F6875C */
