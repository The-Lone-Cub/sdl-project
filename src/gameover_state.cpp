#include "include/game.h"
#include "include/menu_state.h"
#include "include/play_state.h"
#include "include/game_object.h"
#include "include/menu_button.h"
#include "include/state_parser.h"
#include "include/gameover_state.h"
#include "include/texture_manager.h"
#include "include/animated_graphic.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

// Callback function to change state to MainMenuState
void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

// Callback function to restart play by changing state to PlayState
void GameOverState::s_restartPlay() {
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update() {
    for (auto i : m_gameObjects)
        i->update();
}

void GameOverState::render() {
    for (auto i : m_gameObjects)
        i->draw();
}

bool GameOverState::onEnter() {
    // Parse the state
    StateParser stateParser;
    stateParser.parseState("game_files/test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);

    // Add callbacks
    m_callbacks.push_back(0);
    m_callbacks.push_back(s_gameOverToMain);
    m_callbacks.push_back(s_restartPlay);

    setCallbacks(m_callbacks);
    return true;
}

bool GameOverState::onExit() {
    for(auto i : m_gameObjects) {
        i->clean();
        // Ensure game objects are deleted
        //delete i;
    }
    m_gameObjects.clear();

    // Clear the texture manager
    for(auto i : m_textureIDList)
        TheTextureManager::Instance()->clearFromTextureMap(i);

    return true;
}

// Set callbacks for menu buttons
void GameOverState::setCallbacks(const std::vector<Callback>& callbacks) {
    for (auto i : m_gameObjects) {
        if (dynamic_cast<MenuButton *>(i)) {
            MenuButton *pButton = dynamic_cast<MenuButton *>(i);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}