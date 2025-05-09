#ifndef C4DA406E_30F3_482A_9FE3_4E15D08D1ABE
#define C4DA406E_30F3_482A_9FE3_4E15D08D1ABE
#include <string>
#include "defs.h"

enum EntityType {
    PLAYER,
    ENEMY,
    BACKGROUND
};

class Entity {
    private:
        int hp;
        SDL_Point position;
        int width, height;

    public:
        Entity();
        Entity(SDL_Point position);
        virtual ~Entity();
        virtual EntityType getType() = 0;
        virtual void render(const SDLContext& sdlContext) const = 0;
        virtual void updateState() = 0;
        virtual bool isRenderable() = 0;
        virtual bool isDestroyable() = 0;

        void setInitialHealthPoints(int hp) {this->hp = hp;}
        int getHealthPoints() const {return hp;}
        SDL_Point getPosition() const {return position;}
        void setPosition(SDL_Point position) {this->position = position;}
        
        
};

#endif /* C4DA406E_30F3_482A_9FE3_4E15D08D1ABE */
