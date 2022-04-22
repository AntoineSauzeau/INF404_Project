#pragma once

#include <iostream>

#include "window.hpp"
#include "rect.hpp"
#include "circle.hpp"

#include <SFML/Graphics.hpp>

class ProgInterface {

    public:
        ProgInterface(Window *window_abstract_object, sf::RenderWindow *window);

        void TreatEvents();
        void RecDraw(Object *);
        void Draw();

    private:
        sf::RenderWindow *window;
        Window* window_abstract_object = nullptr;
};