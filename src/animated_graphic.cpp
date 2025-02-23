#include <SDL2/SDL_timer.h>
#include "include/animated_graphic.h"

// Constructor for AnimatedGraphic
AnimatedGraphic::AnimatedGraphic() : SDLGameObject() {}

// Load parameters for AnimatedGraphic
void AnimatedGraphic::load(LoaderParams* pParams) {
    SDLGameObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

// Draw the AnimatedGraphic
void AnimatedGraphic::draw() {
    SDLGameObject::draw();
}

// Update the AnimatedGraphic
void AnimatedGraphic::update() {
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

// Clean up the AnimatedGraphic
void AnimatedGraphic::clean() {
    SDLGameObject::clean();
}