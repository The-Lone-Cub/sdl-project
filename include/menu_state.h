#pragma once

#include "game_state.h"
#include <vector>

// Base class for menu states
class MenuState : public GameState {
    protected:
        typedef void (*Callback)();
        virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;
        std::vector<Callback> m_callbacks; // List of callback functions
};

// Class representing the main menu state
class MainMenuState : public MenuState
{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_menuID; }

private:
    virtual void setCallbacks(const std::vector<Callback> &callbacks);
    static const std::string s_menuID; // State ID
    std::vector<class GameObject *> m_gameObjects; // List of game objects in this state

    // Callback functions for menu items
    static void s_menuToPlay();
    static void s_exitFromMenu();
};