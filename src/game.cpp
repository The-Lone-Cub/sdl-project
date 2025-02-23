#include "include/game.h"
#include "include/player.h"
#include "include/menu_state.h"
#include "include/play_state.h"
#include "include/input_handler.h"
#include "include/texture_manager.h"

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
    m_pGameStateMachine->changeState(new MenuState());
    m_bRunning = true;
    return true;
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update() {
    m_pGameStateMachine->update();
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);   // clear renderer to the draw color

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean() {
    m_bRunning = false;
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
    TheInputHandler::Instance()->clean();
}