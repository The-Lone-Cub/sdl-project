#include "include/game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.f / FPS;

int main(int argc, char* argv[]) {
    Uint32 frameStart, frameTime;

    if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false)) {
        while(TheGame::Instance()->running()) {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if(frameTime < DELAY_TIME)
                SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    } else {
        std::cerr << "game init failure -- " << SDL_GetError() << std::endl;
        return -1;
    }

    TheGame::Instance()->clean();

    return 0;
}