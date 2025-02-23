#pragma once

#include "game_state.h"
#include <vector>

class GameObject;

// State for when the game ends.
class GameOverState : public GameState {
    public:
        // constructor / destructor
        GameOverState() : GameState() {}
        virtual ~GameOverState() {}
        
        /** Update and render functions ensure that
         *  only things that need to be updated in
         *  that particular state are updated and rendered
         */
        virtual void update();
        virtual void render();

        /** Handle what happens when transitioning
         *  to or out of this state
         */
        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return s_gameOverID; }
    private:

        /** Callback functions for handling button behaviour */
        static void s_gameOverToMain();
        static void s_restartPlay();

        static const std::string s_gameOverID;      // State's ID. Used to distinguish it from any other state
        std::vector<GameObject *> m_gameObjects;    // Container for handling GameObjects associated with this state
};