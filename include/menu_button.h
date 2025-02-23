#include "game_object.h"
#include "game_object_factory.h"

// Simple button for menus
class MenuButton : public SDLGameObject {
    public:
        MenuButton();
        ~MenuButton() {}

        virtual void draw();    // renders button onscreen
        virtual void update();  // updates button's state
        virtual void clean();   // clears itself up freeing memory
        virtual void load(LoaderParams* pParams); // loads button parameters

        void setCallback(void (*callback)()) { m_callback = callback; } // sets the callback function
        int getCallbackID() { return m_callbackID; } // gets the callback ID

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
        int m_callbackID;       // stores the callback ID
};

// Factory class for creating MenuButton objects
class MenuButtonCreator : public BaseCreator {
public:
    virtual GameObject* createGameObject() const { return new MenuButton(); }
};