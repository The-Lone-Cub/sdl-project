#include <iostream>
#include "include/game.h"
#include "include/menu_state.h"
#include "include/play_state.h"
#include "include/menu_button.h"
#include "include/texture_manager.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    for(auto i : m_gameObjects)
        i->update();
}

void MenuState::render() {
    for(auto i : m_gameObjects)
        i->draw();
}

bool MenuState::onEnter() {
    if(!TheTextureManager::Instance()->load("assets/button.png",
    "playbutton", TheGame::Instance()->getRenderer()))
        return false;
    
    if(!TheTextureManager::Instance()->load("assets/exit.png",
    "exitbutton", TheGame::Instance()->getRenderer()))
        return false;

    GameObject *button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton", 3), s_menuToPlay);
    GameObject *button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton", 3), s_exitFromMenu);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering MenuState...\n";
    return true;
}

bool MenuState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
    std::cout << "exiting MenuState\n";
    return true;
}

void MenuState::s_menuToPlay() {
    TheGame::Instance()->getStateMachine()->changeState(new PlayState);
}

void MenuState::s_exitFromMenu() {
    TheGame::Instance()->clean();
}