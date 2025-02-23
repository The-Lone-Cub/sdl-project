#pragma once
#include "game_object.h"
#include "game_object_factory.h"

// Class for animated graphics
class AnimatedGraphic : public SDLGameObject {
    public:
        // constructor / destructor
        AnimatedGraphic();
        virtual ~AnimatedGraphic() {}

        virtual void draw();    // renders itself on screen
        virtual void update();  // updates itself
        virtual void clean();   // clears itself freeing up memory
        virtual void load(LoaderParams *pParams); // loads parameters

    private:
        int m_animSpeed;        // the speed at which the frames should change
};

// Factory class for creating AnimatedGraphic objects
class AnimatedGraphicCreator : public BaseCreator {
public:
    virtual GameObject *createGameObject() const { return new AnimatedGraphic(); }
};