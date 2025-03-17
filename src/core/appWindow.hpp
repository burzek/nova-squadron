#ifndef CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5
#define CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5


#include "SDL2/SDL.h"
#include "defs.h"
#include "world.hpp"

class World; // Forward declaration of World class


class AppWindow  {
    private:
        std::unique_ptr<SDLContext> sdlContext;
    public:
        AppWindow();
        virtual ~AppWindow();
        void shutdown();
        void initialize();
        void renderWorld(const World& world);
    private:
        void prepareScene();
        void presentScene();
        const SDLContext* getContext() const;
};

#endif /* CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5 */
