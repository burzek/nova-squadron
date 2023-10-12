#ifndef F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D
#define F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D

#include "../core/renderable.hpp"
#include "../core/appWindow.hpp"

class Background : public Renderable {
    public:
        Background();
        ~Background();
        void render(const AppWindow *appWindow);
        // void render(const AppWindow* appWindow);
};

#endif /* F5296AD1_0CC6_40D7_84B7_011D4C4ACF7D */
