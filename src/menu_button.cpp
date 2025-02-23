#include "include/menu_button.h"
#include "include/input_handler.h"

MenuButton::MenuButton() : SDLGameObject() {
    m_currentFrame = MOUSE_OUT; // Start at frame 0
}

void MenuButton::load(LoaderParams* pParams) {
    SDLGameObject::load(pParams);
    m_callbackID = pParams->getCallbackID();
    m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
    SDLGameObject::draw(); // Use base class drawing
}

void MenuButton::update() {
    Vector2D *pMousePos = TheInputHandler::Instance()->getMousePosition();

    if(pMousePos->getX() < (m_position.getX() + m_width)
    && pMousePos->getX() > m_position.getX()
    && pMousePos->getY() < (m_position.getY() + m_height)
    && pMousePos->getY() > m_position.getY()) {
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased) {
            m_currentFrame = MOUSE_CLICKED;
            m_callback();   // Call our callback function
            m_bReleased = false;
        } else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    } else {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clean() {
    SDLGameObject::clean();
}
