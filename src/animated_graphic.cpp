#include <SDL2/SDL_timer.h>
#include "include/animated_graphic.h"

AnimatedGraphic::AnimatedGraphic(LoaderParams* pParams, int animSpeed):
SDLGameObject(pParams), m_animSpeed(animSpeed) {}

void AnimatedGraphic::draw() {
    SDLGameObject::draw();
}

void AnimatedGraphic::update() {
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::clean() {
    SDLGameObject::clean();
}