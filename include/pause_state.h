#pragma once

#include <string>
#include <vector>
#include "menu_state.h"

class GameObject;

// Class representing the pause state of the game
class PauseState : public MenuState {
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return s_pauseID; }
        virtual void setCallbacks(const std::vector<Callback> &callbacks);
    private:
        // Callback functions for pause menu items
        static void s_pauseToMain();
        static void s_resumePlay();

        static const std::string s_pauseID; // State ID

        std::vector<GameObject *> m_gameObjects; // List of game objects in this state
};