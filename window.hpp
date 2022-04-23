#pragma once

#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Window : public Object {

    public:
        Window(std::map<std::string, std::string>* l_property, type_object type);

        void Draw(sf::RenderWindow *window);

        int GetWidth();
        int GetHeight();

    private:
        int width = 0;
        int height = 0;
        sf::Color background_color;
};