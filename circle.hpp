#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Circle : public Object {

    public:
        Circle(std::map<std::string, std::string>* l_property, type_object type);
        void Draw(sf::RenderWindow* window);

    private:
        int x = 0;
        int y = 0;
        float radius = 1;
        sf::Color color;
};