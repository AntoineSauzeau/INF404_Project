#pragma once

#include "animation.hpp"
#include "interface.hpp"

#include <time.h>
#include <vector>
#include <thread>
#include <chrono>

class AnimationHandler {

    public:
        AnimationHandler();

        void AddAnimation(Animation *animation);
        void StartAnimationHandling();
        void Run();

        void AttachInterface(ProgInterface *interface);

    private:
        std::vector<Animation *> l_animation;
        std::thread *thread = nullptr;
        ProgInterface *interface = nullptr;
};