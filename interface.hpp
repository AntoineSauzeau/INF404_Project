#pragma once

#include "window.hpp"

#include <SFML/Graphics.hpp>

class Interface {

    public:
        Interface(Window *window_abstract_object);
        void Draw();

    private:
        sf::RenderWindow *window;
};