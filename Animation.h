//
// Created by Łukasz on 2016-03-20.
//

#ifndef WATCH_ANIMATION_H
#define WATCH_ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation {
public:
    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration) : startFrame(startFrame),
                                                                                endFrame(endFrame),
                                                                                duration(duration) { }

    unsigned int getLength() { return endFrame - startFrame + 1; }
};


#endif //WATCH_ANIMATION_H
