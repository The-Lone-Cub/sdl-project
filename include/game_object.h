#pragma once
#include "loader_params.h"
#include "vector2D.h"

// Base class for all objects in game
class GameObject {
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

        virtual void load(LoaderParams *pParams) = 0;

    protected:
        GameObject() {}
        virtual ~GameObject() {}
};

// Sub-class of GameObject. For specifically objects that need SDL related functionality
class SDLGameObject : public GameObject {
public:
    // constructor / destructor
    SDLGameObject();
    virtual ~SDLGameObject() {}

    virtual void draw();    // renders object on screen
    virtual void update();  // updates object related details
    virtual void clean();   // clears object freeing necessary memory
    virtual void load(LoaderParams *pParams); // loads object parameters

    // getters
    Vector2D& getPosition() { return m_position; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

protected:
    Vector2D m_position;        // stores position of object
    Vector2D m_velocity;        // stores velocity of object
    Vector2D m_acceleration;    // stores acceleration of object
    int m_width;                // stores width of object
    int m_height;               // stores height of object
    int m_currentRow;           // stores current row of image object is using
    int m_currentFrame;         // stores current frame at which object is
    int m_numFrames;            // stores total number of frames object has
    
    /*  Stores ID of texture object is using
     ** Useful for accessing texture through TheTextureManager
    */
    std::string m_textureID;
};