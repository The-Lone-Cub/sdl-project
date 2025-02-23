#include <iostream>
#include "include/game.h"
#include "include/menu_state.h"
#include "include/pause_state.h"
#include "include/game_object.h"
#include "include/menu_button.h"
#include "include/input_handler.h"
#include "include/texture_manager.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

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
    if(!TheTextureManager::Instance()->load("assets/resume.png", "resumebutton", TheGame::Instance()->getRenderer()))
        return false;
    if(!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
        return false;

    GameObject *button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton", 3), s_pauseToMain);
    GameObject *button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton", 3), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering PauseState\n";
    return true;
}

bool PauseState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");

    // reset mouse button states to false
    TheInputHandler::Instance()->reset();

    std::cout << "Exiting PauseState\n";
    return true;
}