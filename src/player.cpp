#include "include/player.h"
#include <SDL2/SDL_timer.h>
#include "include/input_handler.h"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = (((SDL_GetTicks() / 100) % m_numFrames));
    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {
    Vector2D *target = TheInputHandler::Instance()->getMousePosition();
    m_velocity = *target - m_position;
    m_velocity /= 50;
}

Enemy::Enemy(const LoaderParams* pParams):
SDLGameObject(pParams) {
    m_velocity.setY(2);
    m_velocity.setX(0.001);
}

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

    if(m_position.getY() < 0)
        m_velocity.setY(2);
    else if(m_position.getY() > 400)
        m_velocity.setY(-2);

    SDLGameObject::update();
}

void Enemy::clean() {}