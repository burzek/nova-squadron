#ifndef FDA59980_650B_4513_BEEE_E3429FA8328B
#define FDA59980_650B_4513_BEEE_E3429FA8328B

#include <string>
#include <SDL2/SDL.h>
#include "spdlog/spdlog.h"
struct SDLContext {
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;
	std::unique_ptr<SDL_Window , void(*)(SDL_Window*)> window;
	SDLContext(
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer, 
		std::unique_ptr<SDL_Window , void(*)(SDL_Window*)> window)
	: renderer(std::move(renderer)), window(std::move(window)) {}
};

struct Position {
	int x, y;
};

namespace constants {
	constexpr int WINDOW_X  = (int) 0;
	constexpr int WINDOW_Y = (int) 0;
	constexpr int WINDOW_WIDTH = (int) 800;
	constexpr int WINDOW_HEIGHT = (int) 600;
	const std::string WINDOW_NAME = "novaSquadron";
};

namespace constants_hp {
	constexpr int PLAYER_INITIAL_HP = 100;
};

#endif /* FDA59980_650B_4513_BEEE_E3429FA8328B */
