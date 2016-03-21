//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_ANIMATIONHANDLER_H
#define WATCH_ANIMATIONHANDLER_H

#include "Animation.h"
#include <vector>

class AnimationHandler {
public:
    void addAnim(Animation &anim);

    void update(const float dt);

    void changeAnim(unsigned int animID);

    sf::IntRect bounds;
    sf::IntRect frameSize;

    AnimationHandler();

    AnimationHandler(const sf::IntRect &frameSize);

private:
    std::vector<Animation> animations;
    float t;
    int currentAnim;
};


#endif //WATCH_ANIMATIONHANDLER_H
