#include "include/player.h"
#include "include/input_handler.h"
#include <SDL2/SDL_timer.h>

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = (((SDL_GetTicks() / 100) % 6));
    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {
    if(TheInputHandler::Instance()->joysticksInitialised()) {
        if(TheInputHandler::Instance()->xvalue(0, 1) != 0)
            m_velocity.setX(m_velocity.getX() + 1 * TheInputHandler::Instance()->xvalue(0, 1));
        if(TheInputHandler::Instance()->yvalue(0, 1) != 0)
            m_velocity.setY(m_velocity.getY() + 1 * TheInputHandler::Instance()->yvalue(0, 1));
        if (TheInputHandler::Instance()->xvalue(0, 2) != 0)
            m_velocity.setX(m_velocity.getX() + 1 * TheInputHandler::Instance()->xvalue(0, 2));
        if (TheInputHandler::Instance()->yvalue(0, 2) != 0)
            m_velocity.setY(m_velocity.getY() + 1 * TheInputHandler::Instance()->yvalue(0, 2));
    }
}

Enemy::Enemy(const LoaderParams* pParams):
SDLGameObject(pParams) {}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update()
{/*
    m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    */
}

void Enemy::clean() {}