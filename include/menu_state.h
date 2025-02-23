#pragma once

#include "game_state.h"
#include <vector>

// State that contains menu
class MenuState : public GameState {
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return s_menuID; }
    private:
        static const std::string s_menuID;
        std::vector<class GameObject *> m_gameObjects;

        // call back functions for menu items
        static void s_menuToPlay();
        static void s_exitFromMenu();
};