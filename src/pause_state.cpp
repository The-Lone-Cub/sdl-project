#include <iostream>
#include "include/game.h"
#include "include/menu_state.h"
#include "include/state_parser.h"
#include "include/pause_state.h"
#include "include/game_object.h"
#include "include/menu_button.h"
#include "include/input_handler.h"
#include "include/texture_manager.h"

const std::string PauseState::s_pauseID = "PAUSE";

// Callback function to change state to MainMenuState
void PauseState::s_pauseToMain() {
    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

// Callback function to resume play by popping the current state
void PauseState::s_resumePlay() {
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
    for(auto i : m_gameObjects)
        i->update();
}

void PauseState::render() {
    for(auto i : m_gameObjects)
        i->draw();
}

bool PauseState::onEnter() {
    StateParser stateParser;
    stateParser.parseState("game_files/test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);

    // Add callbacks
    m_callbacks.push_back(0);
    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);

    setCallbacks(m_callbacks);

    return true;
}

// Set callbacks for menu buttons
void PauseState::setCallbacks(const std::vector<Callback>& callbacks) {
    // go through the game objects
    for(auto i : m_gameObjects) {
        // if they are of type MenuButton, then assign them a callback based
        // on the id based in from the file
        if(dynamic_cast<MenuButton*>(i)) {
            MenuButton *pButton = dynamic_cast<MenuButton *>(i);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}

bool PauseState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    m_gameObjects.clear();

    // Clear the texture manager
    for(auto i : m_textureIDList)
        TheTextureManager::Instance()->clearFromTextureMap(i);

    // Reset mouse button states to false
    TheInputHandler::Instance()->reset();

    return true;
}