#pragma once

#include <iostream>

#include "window.hpp"

#include <SFML/Graphics.hpp>

class Interface {

    public:
        Interface(Window *window_abstract_object);

        void TreatEvents();
        void RecDraw(Object *object);
        void Draw();

    private:
        sf::RenderWindow *window;
        Window* window_abstract_object = nullptr;
};