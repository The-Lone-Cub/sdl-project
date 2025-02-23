#pragma once
#include "game_state_machine.h"
#include <vector>
#include <SDL2/SDL.h>

/** Follows singleton pattern meaning there can only be
 *  one instance of the class.
 *  
 *  It is the the game itself.
 */
class Game {
    public:
        static Game* Instance() {
            if(!s_pInstance) {
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }

        /** Initialises game with specified title, position and size.
         *  Note that if fullscreen is set to true, xpos, ypos, width
         *  and height parameters don't matter.
         */
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();    // checks for any inputs
        void update();          // updates game
        void render();          // renders game on screen
        void clean();           // clears game resources freeing up any memory
        
        // getters
        SDL_Renderer* getRenderer() { return m_pRenderer; }
        GameStateMachine *getStateMachine() { return m_pGameStateMachine; }

        bool running() { return m_bRunning; }   // check whether game is still running
    private:
        // constructor / destructor
        Game() : m_pWindow(nullptr), m_pRenderer(nullptr), m_pGameStateMachine(new GameStateMachine()) {}
        ~Game() {}

        // game window and renderer
        SDL_Window *m_pWindow;
        SDL_Renderer *m_pRenderer;

        // FSM for managing states. Goto game_state_machine for more info.
        GameStateMachine *m_pGameStateMachine;

        bool m_bRunning;    // stores whether game is still running or not

        static Game *s_pInstance;   // Game instance. There can only be one.
};

using TheGame = Game;   // You can either use TheGame or Game.