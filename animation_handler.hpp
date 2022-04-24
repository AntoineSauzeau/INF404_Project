#pragma once

#include "animation.hpp"

#include <time.h>
#include <vector>
#include <thread>
#include <chrono>

class AnimationHandler {

    public:
        AnimationHandler();

        void AddAnimation(Animation *animation);
        void Run();

    private:
        std::vector<Animation *> l_animation;
        std::thread *thread = nullptr;
};