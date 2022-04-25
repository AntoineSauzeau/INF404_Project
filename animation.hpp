#pragma once

#include <map>
#include <string>
#include <time.h>
#include <chrono>

class Object;
#include "object.hpp"

#include <SFML/Graphics.hpp>

enum type_animation {SLIDE, COLOR, SIZE};
enum type_animation_event {NONE, ONCLICK};

class Animation {

    public:
        Animation(Object *object, std::map<std::string, std::string> *l_property);

        void Run();
        void Update();
        void Reset();

        bool IsEnable();

    private:
        Object *object;
        int time = 0;
        std::chrono::system_clock::time_point start_time;
        type_animation type;
        type_animation_event event;
        bool reset_at_end = false;
        bool enable = false;

        sf::Color new_color;
        sf::Color old_color;
};