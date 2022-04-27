#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Rect : public Object {

    public:
        Rect(std::map<std::string, std::string>* l_property, type_object type);
        void Draw(sf::RenderWindow* window);

        sf::FloatRect GetBounds();

    private:
        int width = 0;
        int height = 0;

        sf::RectangleShape *rect = nullptr;
};