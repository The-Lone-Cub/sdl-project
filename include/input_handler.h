#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "vector2D.h"

// enum for mouse buttons
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE,
    RIGHT
};

/** Handles all input from joysticks(Gamepad, joystick and steering wheel),
 *  mouse and keyboard. Uses singleton pattern to ensure there can only be
 *  one instance of this class throughout the course of the game.
 * 
 *  Useful to avoid input being captured more than once by different objects.
 */
class InputHandler {
    public:
        static InputHandler* Instance() {
            if(s_pInstance == 0)
                s_pInstance = new InputHandler();
            return s_pInstance;
        }

        void update();  // checks for any input and updates accordingly
        void clean();   // clears itself freeing necessary memory

        // getters for x and y position on a joystick.
        int xvalue(int joy, int stick);
        int yvalue(int joy, int stick);

        void InitialiseJoysticks();     // initialises all joysticks available
        bool joysticksInitialised() { return m_bJoysticksInitialised; } // returns whether or not at least one joystick has been initialised
        bool getButtonState(int joy, int buttonNumber) { return m_buttonStates[joy][buttonNumber]; }    // returns the state of a particular button on the joystick
        
        bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }    // returns state of a particular button on the mouse. Whether it is being pressed or not
        Vector2D *getMousePosition() { return m_mousePosition; }    // returns position of mouse on screen. Relative to game window
        bool isKeyDown(SDL_Scancode key);   // returns whether or not a key is being pressed
        void reset() { for(auto i : m_mouseButtonStates) i = false; }   // sets all mouse buttons to not pressed

    private:
        // constructor / destructor
        InputHandler();
        ~InputHandler() {}

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

        // keyboard variables
        Uint8 *m_keystates; // stores state of all keys on keyboard

        // mouse variables
        std::vector<bool> m_mouseButtonStates; // stores the state of all mouse buttons
        Vector2D *m_mousePosition;             // stores position of mouse on screen. Position is relative to window

        // joystick variables
        std::vector<SDL_Joystick *> m_joysticks;    // stores all joysticks available in the game
        std::vector<std::pair<Vector2D *, Vector2D *>> m_joystickValues;    // stores the x and y values of the analog sticks. For the left and right stick
        std::vector<std::vector<bool>> m_buttonStates;  // stores state all joystick buttons
        bool m_bJoysticksInitialised;                   // stores whether or not at least one joystick has been initialised
        const int m_joystickDeadZone = 10000;   // Dead zone of joystick

        static InputHandler *s_pInstance; // singleton instance
};

using TheInputHandler = InputHandler;   // You can use either TheInputHandler or InputHandler