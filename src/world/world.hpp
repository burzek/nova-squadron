#ifndef D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F
#define D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F

#include <vector>
#include <map>
#include "spdlog/spdlog.h"
#include "player.hpp"
#include "background.hpp"
#include "enemy.hpp"


class World {
        private:
                std::map<EntityType, std::unique_ptr<Entity>> entities;
        public:
                World();
                ~World();
                void updateWorld();
                const std::vector<EntityType>& getRenderableEntities() const;
                const Player& getPlayer() const;
        

};

#endif /* D76DE4BD_5A88_4ADF_B64B_B5D3E8AA705F */
