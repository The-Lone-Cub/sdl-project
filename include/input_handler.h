#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "vector2D.h"

class InputHandler {
    public:
        static InputHandler* Instance() {
            if(s_pInstance == 0)
                s_pInstance = new InputHandler();
            return s_pInstance;
        }

        void update();
        void clean();

        int xvalue(int joy, int stick);
        int yvalue(int joy, int stick);

        void InitialiseJoysticks();
        bool joysticksInitialised() { return m_bJoysticksInitialised; }

    private:
        InputHandler() {}
        ~InputHandler() {}

        std::vector<SDL_Joystick *> m_joysticks;
        std::vector<std::pair<Vector2D *, Vector2D *>> m_joystickValues;
        bool m_bJoysticksInitialised;

        const int m_joystickDeadZone = 10000;
        static InputHandler *s_pInstance;
};

using TheInputHandler = InputHandler;