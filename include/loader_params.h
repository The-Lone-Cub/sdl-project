#pragma once
#include <string>

// Stores loader parameters of game objects.
class LoaderParams {
    public:
        // constructor / destructor
        LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames = 0, int callbackID = 0, int animSpeed = 0):
                     m_x(x),
                     m_y(y),
                     m_width(width),
                     m_height(height),
                     m_textureID(textureID),
                     m_numFrames(numFrames),
                     m_callbackID(callbackID),
                     m_animSpeed(animSpeed) {}
        ~LoaderParams() {}
        
        // getters
        int getX() const { return m_x; }
        int getY() const { return m_y; }
        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }
        int getFrames() const { return m_numFrames; }
        int getCallbackID() const { return m_callbackID; }
        int getAnimSpeed() const { return m_animSpeed; }
        std::string getTextureID() const { return m_textureID; }
    
    private:
        int m_x;        // x position of object
        int m_y;        // y position of object
        int m_width;    // width of object
        int m_height;   // height of object
        int m_numFrames;            // number of frames object has
        int m_callbackID;           // callback ID for the object
        int m_animSpeed;            // animation speed of the object
        std::string m_textureID;    // ID of texture it uses
};