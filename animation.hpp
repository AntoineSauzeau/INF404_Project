#pragma once

#include "object.hpp"

enum type_animation {ONCLICK, ONFOCUS}

class Animation {

    public:
        Animation(Object* object);

        void Run();

        private:
            int time = 0;
            type_animation type;
};