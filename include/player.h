#pragma once
#include "game_object.h"
#include "game_object_factory.h"

// Class representing a player in the game
class Player : public SDLGameObject {
    public:
        Player();

        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void load(LoaderParams *pParams);

    private:
        // Handle player input
        void handleInput();
};

// Factory class to create Player objects
class PlayerCreator : public BaseCreator {
    public:
        GameObject *createGameObject() const { return new Player(); }
};

// Class representing an enemy in the game
class Enemy : public SDLGameObject {
    public:
        Enemy();
        
        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void load(LoaderParams *pParams);
};

// Factory class to create Enemy objects
class EnemyCreator : public BaseCreator {
public:
    virtual GameObject* createGameObject() const { return new Enemy(); }
};