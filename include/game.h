#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "game_object.h"

class Game {
    public:
        static Game* Instance() {
            if(!s_pInstance) {
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }

        // simply set the running variable to true
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void render();
        void update();
        void handleEvents();
        void clean();
        SDL_Renderer* getRenderer() { return m_pRenderer; }

        // a function to access the private running variable
        bool running() { return m_bRunning; }
    private:
        Game() : m_pWindow(nullptr), m_pRenderer(nullptr) {}
        ~Game() {}

        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        std::vector<SDLGameObject*> m_GameObjects;

        int m_currentFrame;
        bool m_bRunning;

        static Game* s_pInstance;
};

using TheGame = Game;