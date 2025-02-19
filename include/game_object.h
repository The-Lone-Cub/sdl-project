#pragma once
#include "loader_params.h"
#include "vector2D.h"

class GameObject {
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;
    
    protected:
        GameObject(const LoaderParams* pParams) {}
        virtual ~GameObject() {}
};

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams *pParams = nullptr);
    virtual ~SDLGameObject() {}
    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
};