#include "world.hpp"

World::World(AppWindow* appWindow) : player(new Player()), background(new Background()) {
    this->appWindow = appWindow;
};

World::~World() {
}

void World::updateWorld(){
    //background->updateState();
    // player->updateState();
}

void World::renderWorld() {
    appWindow->prepareScene();
    background->render(appWindow);
    // player->render();
    appWindow->presentScene();


}
