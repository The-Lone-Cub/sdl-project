#include "include/menu_state.h"
#include "include/game_state_machine.h"

// Push a new state onto the stack and call its onEnter method
void GameStateMachine::pushState(MenuState* pState) {
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

// Pop the current state from the stack and call its onExit method
void GameStateMachine::popState() {
    if(!m_gameStates.empty()) {
        if(m_gameStates.back()->onExit()) {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

// Change the current state to a new state
void GameStateMachine::changeState(MenuState* pState) {
    if(!m_gameStates.empty()) {
        if(m_gameStates.back()->getStateID() == pState->getStateID()) {
            return;
        }
        if(m_gameStates.back()->onExit()) {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
    // Push back our new state and initialise it
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

// Update the current state
void GameStateMachine::update() {
    if(!m_gameStates.empty()) {
        m_gameStates.back()->update();
    }
}

// Render the current state
void GameStateMachine::render() {
    if(!m_gameStates.empty()) {
        m_gameStates.back()->render();
    }
}