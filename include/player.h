#pragma once
#include "game_object.h"

class Player : public SDLGameObject {
    public:
        Player(const LoaderParams* pParams);

        virtual void draw();
        virtual void update();
        virtual void clean();
    private:
        void handleInput();
};

class Enemy : public SDLGameObject {
    public:
        Enemy(const LoaderParams* pParams);
        
        virtual void draw();
        virtual void update();
        virtual void clean();
};