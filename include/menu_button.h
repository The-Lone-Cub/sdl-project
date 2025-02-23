#include "game_object.h"

// Simple button for menus
class MenuButton : public SDLGameObject {
    public:
        MenuButton(const LoaderParams *pParams, void(*callback)());
        ~MenuButton() {}

        virtual void draw();    // renders button onscreen
        virtual void update();  // updates button's state
        virtual void clean();   // clear itself up freeing memory
    private:
        // enum for states of button. Whether mouse is outside button area,
        // hovering over the button or clicking the button
        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER,
            MOUSE_CLICKED
        };
        
        void (*m_callback)();   // stores function to call when button is clicked
        bool m_bReleased;       // stores whether button has been released
};