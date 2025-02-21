#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "vector2D.h"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE,
    RIGHT
};

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
        bool getButtonState(int joy, int buttonNumber) { return m_buttonStates[joy][buttonNumber]; }
        bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }
        Vector2D *getMousePosition() { return m_mousePosition; }
        bool isKeyDown(SDL_Scancode key);

    private:
        InputHandler();
        ~InputHandler() {}

        std::vector<SDL_Joystick *> m_joysticks;
        std::vector<std::pair<Vector2D *, Vector2D *>> m_joystickValues;
        bool m_bJoysticksInitialised;

        std::vector<std::vector<bool>> m_buttonStates;
        std::vector<bool> m_mouseButtonStates;
        Uint8 *m_keystates;

        Vector2D *m_mousePosition;

        const int m_joystickDeadZone = 10000;
        static InputHandler *s_pInstance;

        // private functions to handle different event types

        // handle keyboard events
        void onKeyDown();
        void onKeyUp();

        // handle mouse events
        void onMouseMove(SDL_Event &event);
        void onMouseButtonDown(SDL_Event &event);
        void onMouseButtonUp(SDL_Event &event);

        // handle joystick events
        void onJoystickAxisMove(SDL_Event &event);
        void onJoystickButtonDown(SDL_Event &event);
        void onJoystickButtonUp(SDL_Event &event);
};

typedef InputHandler TheInputHandler;