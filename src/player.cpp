#include "include/player.h"
#include <SDL2/SDL_timer.h>
#include "include/input_handler.h"

// Player class constructor
Player::Player() : SDLGameObject() {}

// Load player parameters
void Player::load(LoaderParams* pParams) {
    SDLGameObject::load(pParams);
}

// Draw player
void Player::draw() {
    SDLGameObject::draw();
}

// Update player state
void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = (((SDL_GetTicks() / 100) % m_numFrames));
    SDLGameObject::update();
}

// Clean player resources
void Player::clean() {}

// Handle player input
void Player::handleInput() {
    Vector2D *target = TheInputHandler::Instance()->getMousePosition();
    m_velocity = *target - m_position;
    m_velocity /= 50;
}

// Enemy class constructor
Enemy::Enemy() : SDLGameObject() {}

// Load enemy parameters
void Enemy::load(LoaderParams* pParams) {
    SDLGameObject::load(pParams);
    m_velocity.setY(2);
}

// Draw enemy
void Enemy::draw() {
    SDLGameObject::draw();
}

// Update enemy state
void Enemy::update() {
    m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

    if(m_position.getY() < 0)
        m_velocity.setY(2);
    else if(m_position.getY() > 400)
        m_velocity.setY(-2);

    SDLGameObject::update();
}

// Clean enemy resources
void Enemy::clean() {}