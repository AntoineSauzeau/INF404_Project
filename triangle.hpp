#pragma once

#include <map>
#include <string>

#include "object.hpp"

#include <SFML/Graphics.hpp>

class Triangle : public Object {

    public:
        Triangle(std::map<std::string, std::string>* l_property, type_object type);
        void Draw(sf::RenderWindow* window);

    private:
        float radius = 1;
};