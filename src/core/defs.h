#ifndef FDA59980_650B_4513_BEEE_E3429FA8328B
#define FDA59980_650B_4513_BEEE_E3429FA8328B

#include <string>
#include <SDL2/SDL.h>
#include "spdlog/spdlog.h"
typedef struct {
	SDL_Renderer* renderer;
	SDL_Window* window;
} SDLContext;


namespace constants {
	constexpr int WINDOW_X  = (int) 0;
	constexpr int WINDOW_Y = (int) 0;
	constexpr int WINDOW_WIDTH = (int) 800;
	constexpr int WINDOW_HEIGHT = (int) 600;
	const std::string WINDOW_NAME = "novaSquadron";
};

#endif /* FDA59980_650B_4513_BEEE_E3429FA8328B */
