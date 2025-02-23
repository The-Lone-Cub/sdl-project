#pragma once
#include <vector>

// Finite State Manager(FSM) for managing states of game
class GameStateMachine {
    public:
        /** Switches to passed state 
         *  Waits until passed state is done and
         *  Swicthes back to previous state
         */
        void pushState(class GameState *state);

        /** Exits from previous state before
         *  entering into passed state
         */
        void changeState(class GameState* state);

        /** Exits from current state */
        void popState();

        void update();  // updates state
        void render();  // renders state

    private:
        std::vector<GameState*> m_gameStates;   // stores different states open at that moment
};