#include <iostream>
#include "include/game.h"
#include "include/player.h"
#include "include/play_state.h"
#include "include/pause_state.h"
#include "include/menu_button.h"
#include "include/state_parser.h"
#include "include/game_object.h"
#include "include/input_handler.h"
#include "include/gameover_state.h"
#include "include/texture_manager.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    for (auto i : m_gameObjects)
        i->update();
    
    if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState);
    }
}

void PlayState::render() {
    for(auto i : m_gameObjects)
        i->draw();
}

bool PlayState::onEnter() {
    // Parse the state
    StateParser stateParser;
    stateParser.parseState("game_files/test.xml", s_playID, &m_gameObjects, &m_textureIDList);

    return true;
}

bool PlayState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    m_gameObjects.clear();

    for(auto i : m_textureIDList)
        TheTextureManager::Instance()->clearFromTextureMap(i);

    return true;
}

// Check for collision between two game objects
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();
    
    // Calculate the sides of rect B
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();
    
    // If any of the sides from A are outside of B
    if (bottomA <= topB)
        return false;
    if (topA >= bottomB)
        return false;
    if (rightA <= leftB)
        return false;
    if (leftA >= rightB)
        return false;

    return true;
}

void PlayState::setCallbacks(const std::vector<Callback>& callbacks) {
    for(auto i : m_gameObjects) {
        if(dynamic_cast<MenuButton*>(i)) {
            MenuButton *pButton = dynamic_cast<MenuButton *>(i);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}