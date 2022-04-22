#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Rect : public Object {

    public:
        Rect(std::map<std::string, std::string>* l_property, type_object type);
        void Draw(sf::RenderWindow* window);

    private:
        int x = 0;
        int y = 0;
        int width = 0;
        int height = 0;
        sf::Color color;
};