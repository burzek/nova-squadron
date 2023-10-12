#ifndef D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F
#define D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F

#include <vector>
#include "player.hpp"
#include "background.hpp"

class World {
        private:
            AppWindow* appWindow;
            Player* player;
            // vector<Enemy> enemies;
            Background* background;
            
    public:
        World(AppWindow* appWindow);
        ~World();
        void updateWorld();
        void renderWorld();

};

#endif /* D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F */
