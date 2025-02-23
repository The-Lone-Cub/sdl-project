#include "include/game.h"
#include "include/game_object.h"
#include "include/loader_params.h"
#include "include/texture_manager.h"

// Constructor
SDLGameObject::SDLGameObject() : GameObject() {}

// Load object parameters
void SDLGameObject::load(LoaderParams* pParams) {
    m_position = Vector2D(pParams->getX(), pParams->getY());
    m_velocity = Vector2D(0, 0);
    m_acceleration = Vector2D(0, 0);

    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_currentFrame = 1;
    m_currentRow = 1;
    m_textureID = pParams->getTextureID();
    m_numFrames = pParams->getFrames();
}

// Draw the object
void SDLGameObject::draw() {
    if(m_velocity.getX() > 0) {
        TheTextureManager::Instance()->drawFrame(m_textureID,
                                                 (Uint32)m_position.getX(), (Uint32)m_position.getY(),
                                                 m_width, m_height, m_currentRow, m_currentFrame,
                                                 TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
    } else {
        TheTextureManager::Instance()->drawFrame(m_textureID,
                                                 (Uint32)m_position.getX(), (Uint32)m_position.getY(),
                                                 m_width, m_height, m_currentRow, m_currentFrame,
                                                 TheGame::Instance()->getRenderer());
    }
}

// Update the object state
void SDLGameObject::update() {
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

// Clean up the object
void SDLGameObject::clean() {}