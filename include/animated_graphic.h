#pragma once
#include "game_object.h"

class AnimatedGraphic : public SDLGameObject {
    public:
        // constructor / destructor
        AnimatedGraphic(LoaderParams* pParams, int animSpeed);
        virtual ~AnimatedGraphic() {}

        virtual void draw();    // renders itself on screen
        virtual void update();  // updates itself
        virtual void clean();   // clears itself freeing up memory
    private:
        int m_animSpeed;        // the speed at which the frames should change
};