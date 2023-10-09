#ifndef CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5
#define CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5


#include "SDL2/SDL.h"
#include "defs.h"

class AppWindow  {
    private:
        SDLContext* sdlContext;
    public:
        AppWindow();
        virtual ~AppWindow();
        void shutdown();
        void initialize();
        constexpr SDLContext* getContext();
};

#endif /* CE5F263B_E90A_4F7A_8DC6_FA6C581CE7E5 */
