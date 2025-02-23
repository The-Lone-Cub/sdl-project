#include "include/game.h"
#include "include/menu_state.h"
#include "include/play_state.h"
#include "include/game_object.h"
#include "include/menu_button.h"
#include "include/gameover_state.h"
#include "include/texture_manager.h"
#include "include/animated_graphic.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

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
    if(!TheTextureManager::Instance()->load("assets/gameover.png", "gameovertext", TheGame::Instance()->getRenderer()))
        return false;
    if(!TheTextureManager::Instance()->load("assets/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
        return false;
    if(!TheTextureManager::Instance()->load("assets/restart.png", "restartbutton", TheGame::Instance()->getRenderer()))
        return false;

    GameObject *gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext", 2), 2);
    GameObject *button1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), s_gameOverToMain);
    GameObject *button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);
    m_gameObjects.push_back(gameOverText);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);
    return true;
}

bool GameOverState::onExit() {
    for(auto i : m_gameObjects)
        i->clean();
    TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
    return true;
}