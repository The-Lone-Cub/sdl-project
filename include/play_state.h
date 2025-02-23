#pragma once

#include "game_state.h"
#include <vector>

class PlayState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID; }
    
    bool checkCollision(class SDLGameObject *p1, class SDLGameObject *p2);
private:
    static const std::string s_playID;
    std::vector<class GameObject *> m_gameObjects;
};