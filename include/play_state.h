#pragma once

#include "menu_state.h"
#include <vector>

// Class representing the play state of the game
class PlayState : public MenuState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID; }
    
    // Check for collision between two game objects
    bool checkCollision(class SDLGameObject *p1, class SDLGameObject *p2);
    
    virtual void setCallbacks(const std::vector<Callback> &callbacks);
private:
    static const std::string s_playID; // State ID
    std::vector<class GameObject *> m_gameObjects; // List of game objects in this state
};