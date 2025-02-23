#pragma once

#include "menu_state.h"
#include <vector>

class GameObject;

// State for when the game ends.
class GameOverState : public MenuState {
    public:
        // constructor / destructor
        GameOverState() : MenuState() {}
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

        virtual void setCallbacks(const std::vector<Callback>& callbacks); // sets the callback functions for buttons

        virtual std::string getStateID() const { return s_gameOverID; } // gets the state ID
    private:

        /** Callback functions for handling button behaviour */
        static void s_gameOverToMain(); // callback for transitioning to main menu
        static void s_restartPlay();    // callback for restarting the game

        static const std::string s_gameOverID;      // State's ID. Used to distinguish it from any other state
        std::vector<GameObject *> m_gameObjects;    // Container for handling GameObjects associated with this state
};