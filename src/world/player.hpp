#ifndef EDB281CE_DB3C_4A62_80B9_144F19DFA7C2
#define EDB281CE_DB3C_4A62_80B9_144F19DFA7C2

#include "entity.hpp"
#include "defs.h"


class Player : public Entity {
    private:
    public:
        Player();
        virtual ~Player();
        
        void render(const SDLContext& sdlContext);
        void updateState();
        EntityType getType() {return EntityType::PLAYER;};
        bool isRenderable() {return true;};
        bool isDestroyable() {return true;};
        int getInitialHealthPoints() {return constants_hp::PLAYER_INITIAL_HP;};

        
        
};

#endif /* EDB281CE_DB3C_4A62_80B9_144F19DFA7C2 */
