#include "include/game.h"
#include "include/texture_manager.h"
#include "include/player.h"
#include "include/input_handler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(!SDL_Init(SDL_INIT_EVERYTHING)) {
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow) {     // window init success
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer) {       // renderer init success
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

                if(!TheTextureManager::Instance()->load("assets/animate.png", "animate", m_pRenderer)) {
                    return false;
                }

                m_GameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
                m_GameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
            } else {                  // renderer init fail
                return false;
            }
        } else {                      // window init fail
            return false;
        }
    } else {                           // sdl init fail
        return false;
    }
    
    // init success
    TheInputHandler::Instance()->InitialiseJoysticks();
    m_bRunning = true;
    return true;
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();
}

void Game::update() {
    for(SDLGameObject* i : m_GameObjects) {
        i->update();
    }
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);   // clear renderer to the draw color

    for(SDLGameObject* i : m_GameObjects) {
        i->draw();
    }

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean() {
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
    TheInputHandler::Instance()->clean();
}