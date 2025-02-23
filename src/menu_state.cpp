#include <iostream>
#include "include/game.h"
#include "include/menu_state.h"
#include "include/play_state.h"
#include "include/menu_button.h"
#include "include/texture_manager.h"
#include "include/state_parser.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update() {
    for(auto i : m_gameObjects)
        i->update();
}

void MainMenuState::render() {
    for(auto i : m_gameObjects)
        i->draw();
}

bool MainMenuState::onEnter() {
    // Parse the state
    StateParser stateParser;
    stateParser.parseState("game_files/test.xml", s_menuID, &m_gameObjects, &m_textureIDList);
    
    // Add callbacks
    m_callbacks.push_back(0);   // pushback 0 callbackID start from 1
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    // Set callbacks for menu items
    setCallbacks(m_callbacks);
    return true;
}

bool MainMenuState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    m_gameObjects.clear();
    
    // Clear the texture manager
    for(auto i : m_textureIDList)
        TheTextureManager::Instance()->clearFromTextureMap(i);
    return true;
}

// Callback function to change state to PlayState
void MainMenuState::s_menuToPlay() {
    TheGame::Instance()->getStateMachine()->changeState(new PlayState);
}

// Callback function to exit the game
void MainMenuState::s_exitFromMenu() {
    TheGame::Instance()->clean();
}

// Set callbacks for menu buttons
void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks) {
    for(auto i : m_gameObjects) {
        if(dynamic_cast<MenuButton*>(i)) {
            MenuButton *pButton = dynamic_cast<MenuButton *>(i);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}