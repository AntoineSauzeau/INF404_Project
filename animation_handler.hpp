#pragma once

#include "animation.hpp"
#include "circle.hpp"
#include "rect.hpp"
#include "image.hpp"
#include "triangle.hpp"
#include "text.hpp"

class ProgInterface;
#include "interface.hpp"

#include <time.h>
#include <vector>
#include <thread>
#include <chrono>

class AnimationHandler {

    public:
        AnimationHandler();
        ~AnimationHandler();

        void AddAnimation(Animation *animation);
        void StartAnimationHandling();
        void Run();
        void Event(sf::Event *event);

        void AttachInterface(ProgInterface *interface);

    private:
        std::vector<Animation *> l_animation;
        std::thread *thread = nullptr;
        ProgInterface *interface = nullptr;

        int N_UPDATE_PER_SECOND = 30;
};